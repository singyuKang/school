#define _CRT_SECURE_NO_WARNINGS //201614792 ��ǻ�Ͱ��а� ���ű�
#include <iostream>
#include "ArrayStack.h"
using namespace std;

bool checkMatching(const char* filename)
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
		error("Error: ���� �������� �ʽ��ϴ�.\n");

	int nLine = 1;
	int nChar = 0;
	ArrayStack stack;
	char ch;
	bool quo = false;
	bool bigQuo = false;
	bool comment = false;
	bool comment_star = false;
	bool comment_check = false;
	bool del_star = false;

	while ((ch = getc(fp)) != EOF)
	{
		nChar++;


		if (ch == '\n') {
			nLine++;
			comment = false;
		}

		if (comment_check == true && ch == '/')
			comment = true;
		else if (comment_check == true && ch == '*')
			comment_star = true;
		else
			comment_check = false;

		if (del_star == true && ch == '/')
			comment_star = false;
		else
			del_star = false;




		if (ch == '\'' && quo == false) /* //88*/
			quo = true;
		else if (ch == '\'')
			quo = false;

		if (ch == '\"' && bigQuo == false)
			bigQuo = true;
		else if (ch == '\"')
			bigQuo = false;

		if (comment_check == false && ch == '/')
			comment_check = true;

		if (comment_star == true && ch == '*')
			del_star = true;





		if (ch == '[' || ch == '(' || ch == '{')
		{
			if (quo == false && bigQuo == false && comment == false && comment_star == false)
				stack.push(ch);
		}

		else if (ch == ']' || ch == ')' || ch == '}')
		{
			if (quo == false && bigQuo == false && comment == false && comment_star == false)
			{
				char prev = stack.pop();
				if ((ch == ']' && prev != '[')
					|| (ch == ')' && prev != '(')
					|| (ch == '}' && prev != '{'))
					error("��ȣ �̻�");
				break;

			}

		}


	}

	fclose(fp);
	printf("[%s] ���� �˻���:\n", filename);

	if (!stack.isEmpty())
		printf("Error: �����߰�!(���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);
	else
		printf("ok:��ȣ�ݱ�����(���μ�=%d, ���ڼ�=%d)\n\n", nLine, nChar);

	return stack.isEmpty();
}
int main() {

	checkMatching((char*)"ArrayStack.h");
	checkMatching((char*)"ArrayStackMain.cpp");



}