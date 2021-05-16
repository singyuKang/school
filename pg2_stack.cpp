#define _CRT_SECURE_NO_WARNINGS //201614792 컴퓨터공학과 강신규
#include <iostream>
#include <cstdlib>
#include <string>
#include "ArrayStack.h"
#include <cstdio>

using namespace std;
inline int precedence(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

string infix2Postfix(const char* filename) {
	FILE* fp = fopen(filename, "r");
	char c;
	char op;
	double val;
	ArrayStack st;

	string fix = "";

	while ((c = getc(fp)) != EOF) {
		if ((c >= '0' && c <= '9')) {
			ungetc(c, fp);
			fscanf(fp, "%lf", &val);
			fix.append(to_string(val));
		}

		else if (c == '(') st.push(c);

		else if (c == ')') {
			while (!st.isEmpty()) {
				op = st.pop();
				if (op == '(') break;
				else {
					fix += op;
				}
			}
		}

		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (!st.isEmpty()) {
				op = st.peek();
				if (precedence(c) <= precedence(op)) {
					fix += op;
					st.pop();
				}
				else break;
			}
			st.push(c);
		}
	}
	while (st.isEmpty() == false) {
		char ch = st.pop();
		fix += ch;
	}

	printf("\n");

	return fix;
}

double calcPostfixExpr(string fix) {
	char c;
	ArrayStack st;
	int i = 0;

	while (i< fix.size()) {
		if (fix[i] == '+' || fix[i] == '-' || fix[i] == '*' || fix[i] == '/') {//문자가 연산자일때 스텍안에 있는 2 숫자를 연산시켜준뒤 다시 스텍에 넣는다.
			double val2 = st.pop();
			double val1 = st.pop();

			switch (fix[i]) {
			case '+': st.push((double)val1 + (double)val2); break;
			case '-': st.push((double)val1 - (double)val2); break;
			case '*': st.push((double)val1 * (double)val2); break;
			case '/': st.push((double)val1 / (double)val2); break;
			}
		}
		else if (fix[i] == '0') {
			double val = (double(fix[i + 2] - 48)) / 10 + (double(fix[i + 3] - 48)) / 100 + (double(fix[i + 4] - 48)) / 1000 + (double(fix[i + 5] - 48)) / 10000 + (double(fix[i + 6] - 48)) / 100000 +
				(double(fix[i + 7] - 48)) / 1000000; //8비트의 정보를 받아서 숫자가 1이하일때 ex> 0.5 0.6 소숫점을 구해줘서 더해준뒤 val값에 저장한후 스텍에 넣어준다
			st.push(val);
			i = i + 7;

		}
		else if (fix[i] > '0' && fix[i] <= '9') {
			double val = fix[i]-48 + (double(fix[i + 2]-48))/10+ (double(fix[i + 3] - 48)) / 100+ (double(fix[i + 4] - 48)) / 1000+ (double(fix[i + 5] - 48)) / 10000+ (double(fix[i + 6] - 48)) / 100000+
				(double(fix[i + 7] - 48)) / 1000000;//숫자가 1이상일때 ex)1.5 6.7 소숫점을 더해줘서 val값에 저장한후 스텍에 넣어준다
			st.push(val);
			i = i + 7;//8비트임으로 다음의 정보를 받기위해 7비트 뒤로간다
		}
		i = i + 1;
	}
	return (st.pop()); //정보를 다읽었으면 스텍 가장위에 있는 숫자를 반환해준다.
}

int main(void) {

	string fix = infix2Postfix("Text.txt");//Text 파일을 읽어서 string fix를 생성  후위표식을 넘겨준다
	cout <<"변환식: " <<fix +""<< endl;
	printf("계산결과: %lf", calcPostfixExpr(fix));//string fix 를 함수 calcPosfixExpr 에 넘겨줘서 후위표식을 계산해준다

	return 0;
}