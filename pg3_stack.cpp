#define _CRT_SECURE_NO_WARNINGS //201614792 ��ǻ�Ͱ��а� ���ű�
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
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
	std::stack<double> st;
	char c;
	char op;
	double val;
	string fix = "";

	while ((c = getc(fp)) != EOF) {
		if ((c >= '0' && c <= '9')) {
			ungetc(c, fp);
			fscanf(fp, "%lf", &val);
			fix.append(to_string(val));

		}
		else if (c == '(') st.push(c);

		else if (c == ')') {
			while (!st.empty()) {
				op = st.top();
				st.pop();
				if (op == '(') break;
				else {
					fix += op;
				}
			}
		}

		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (!st.empty()) {
				op = st.top();
				if (precedence(c) <= precedence(op)) {
					fix += op;
					st.pop();
				}
				else break;
			}
			st.push(c);
		}
	}
	while (st.empty() == false) {
		char ch = st.top();
		st.pop();
		fix += ch;
	}

	printf("\n");

	return fix;
}

double calcPostfixExpr(string fix) {
	char c;
	std::stack<double> st1;
	int i = 0;

	while (i < fix.size()) {
		if (fix[i] == '+' || fix[i] == '-' || fix[i] == '*' || fix[i] == '/') {//���ڰ� �������϶� ���ؾȿ� �ִ� 2 ���ڸ� ��������ص� �ٽ� ���ؿ� �ִ´�.
			double val2 = st1.top();
			st1.pop();
			double val1 = st1.top();
			st1.pop();

			switch (fix[i]) {
			case '+': st1.push((double)val1 + (double)val2); break;
			case '-': st1.push((double)val1 - (double)val2); break;
			case '*': st1.push((double)val1 * (double)val2); break;
			case '/': st1.push((double)val1 / (double)val2); break;
			}
		}
		else if (fix[i] == '0') {
			double val = (double(fix[i + 2] - 48)) / 10 + (double(fix[i + 3] - 48)) / 100 + (double(fix[i + 4] - 48)) / 1000 + (double(fix[i + 5] - 48)) / 10000 + (double(fix[i + 6] - 48)) / 100000 +
				(double(fix[i + 7] - 48)) / 1000000; //8��Ʈ�� ������ �޾Ƽ� ���ڰ� 1�����϶� ex> 0.5 0.6 �Ҽ����� �����༭ �����ص� val���� �������� ���ؿ� �־��ش�
			st1.push(val);
			i = i + 7;

		}
		else if (fix[i] > '0' && fix[i] <= '9') {
			double val = fix[i] - 48 + (double(fix[i + 2] - 48)) / 10 + (double(fix[i + 3] - 48)) / 100 + (double(fix[i + 4] - 48)) / 1000 + (double(fix[i + 5] - 48)) / 10000 + (double(fix[i + 6] - 48)) / 100000 +
				(double(fix[i + 7] - 48)) / 1000000;//���ڰ� 1�̻��϶� ex)1.5 6.7 �Ҽ����� �����༭ val���� �������� ���ؿ� �־��ش�
			st1.push(val);
			i = i + 7;//8��Ʈ������ ������ ������ �ޱ����� 7��Ʈ �ڷΰ���
		}
		i = i + 1;
	}
	return (st1.top()); //������ ���о����� ���� �������� �ִ� ���ڸ� ��ȯ���ش�.
}

int main(void) {

	string fix = infix2Postfix("Text.txt");//Text ������ �о string fix�� ����  ����ǥ���� �Ѱ��ش�
	cout << "���Ͻ� ��ȯ���: " << fix + "  " << endl;
	printf("�����: %lf", calcPostfixExpr(fix));//string fix �� �Լ� calcPosfixExpr �� �Ѱ��༭ ����ǥ���� ������ش�

	return 0;
}