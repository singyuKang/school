#include <iostream>
#include <cstdlib>
using namespace std;

inline void error(char const* message)
{
	cout << message << endl;
	exit(1);
}

const int MAX_STACK_SIZE = 20;
class ArrayStack
{
private:
	int top;
	int data[MAX_STACK_SIZE];
public:
	ArrayStack()
	{
		top = -1;
	}
	~ArrayStack()
	{
	}
	bool isEmpty()
	{
		return top == -1;
	}
	bool isFull()
	{
		return top == MAX_STACK_SIZE - 1;
	}
	void push(int e)
	{
		if (isFull())
			error("���� ��ȭ ����");
		data[++top] = e;
	}
	int pop()
	{
		if (isEmpty())
			error("���� ���� ����");
		return data[top--];
	}
	int peek()
	{
		if (isEmpty())
			error("���� ���� ����");
		return data[top];
	}
	void display()
	{
		cout << "[���� �׸��� �� = " << top + 1 << "] ==> ";
		for (int i = 0; i <= top; i++)
			cout << "<" << data[i] << "> ";
		cout << endl;
	}
};