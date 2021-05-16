#include <iostream>
#include "cNode.h"
#define MAX_QUEUE_SIZE 100
int levelcount = 0;

class CircularQueue

{

	int front;

	int rear;

	BinaryNode* data[MAX_QUEUE_SIZE];

public:

	CircularQueue()

	{

		front = rear = 0;

	}

	bool isEmpty()

	{

		return front == rear;

	}

	bool isFull()

	{

		return (rear + 1) % MAX_QUEUE_SIZE == front;

	}

	void enqueue(BinaryNode* n)

	{

		if (isFull())

			printf("����");

		else

		{

			rear = (rear + 1) % MAX_QUEUE_SIZE;

			data[rear] = n;

		}

	}

	BinaryNode* dequeue()

	{

		if (isEmpty())

			printf("����");
		else

		{

			front = (front + 1) % MAX_QUEUE_SIZE;

			return data[front];

		}

	}

};
class BinaryTree 

{

private:

	bool reverse(BinaryNode* node)

	{

		if (node == NULL)

			return false;

		else

		{

			//���

			reverse(node->getLeft());

			reverse(node->getRight());

			//leftNode�� rightNode�� ���� �ٲ۴�

			BinaryNode* temp = node->getLeft();

			node->setLeft(node->getRight());

			node->setRight(temp);

		}

		return true;

	}



	int getCount(BinaryNode* node)

	{

		if (node == NULL)

			return 0;

		return 1 + getCount(node->getLeft()) + getCount(node->getRight());

	}

	int getHeight(BinaryNode* node)

	{

		if (node == NULL)

			return 0;

		int hLeft = getHeight(node->getLeft());

		int hRight = getHeight(node->getRight());

		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;

	}

	int getLeafCount(BinaryNode* node)

	{

		if (node == NULL)

			return 0;

		if (node->isLeaf())

			return 1;

		else

			return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());

	}

	int evaluate(BinaryNode* node)

	{

		if (node == NULL)

			return 0;

		if (node->isLeaf())

			return node->getData();

		else

		{

			int op1 = evaluate(node->getLeft());

			int op2 = evaluate(node->getRight());

			switch (node->getData())

			{

			case '+':

				return op1 + op2;

			case '-':

				return op1 - op2;

			case '*':

				return op1 * op2;

			case '/':

				return op1 / op2;

			}

			return 0;

		}

	}

	//��ȯ ȣ�⿡ ���� node�� ��Ʈ�� �ϴ� Ʈ���� ��ü �뷮 ��� �Լ�

	int calcSize(BinaryNode* node)

	{

		if (node == NULL)

			return 0;

		return node->getData() + calcSize(node->getLeft()) + calcSize(node->getRight());

	}

protected:

	BinaryNode* root;

public:

	BinaryTree() :root(NULL)

	{

	}

	void setRoot(BinaryNode* node)

	{

		root = node;

	}

	BinaryNode* getRoot()

	{

		return root;

	}

	bool isEmpty()

	{

		return root == NULL;

	}

	void levelorder() //���� ����

	{
		if (!isEmpty())

		{

			CircularQueue q;
			q.enqueue(root);
			int lel = 0;
			root->setlevel(0);
			while (!q.isEmpty())

			{

				BinaryNode* n = q.dequeue();
				lel = n->getlevel();
				if (n != NULL)

				{
					lel = lel + 1;
					if (n->getLeft() != NULL) {
						(n->getLeft())->setlevel(lel);
					}
					if (n->getRight() != NULL)
					{
						(n->getRight())->setlevel(lel);
					}

					q.enqueue(n->getLeft());
					q.enqueue(n->getRight());

				}

			}
		}



	}


	int getCount()

	{

		return isEmpty() ? 0 : getCount(root);

	}

	int getHeight()

	{

		return isEmpty() ? 0 : getHeight(root);

	}

	int getLeafCount()

	{

		return isEmpty() ? 0 : getLeafCount(root);

	}
};
template <typename T>
class cBinarySearchTree :public BinaryTree

{

public:

	cBinarySearchTree(void)

	{

	}

	~cBinarySearchTree(void)

	{

	}

	//���� Ž�� Ʈ���� Ž�� ����

	BinaryNode* search(int key)

	{

		BinaryNode* node = searchRecur(root, key);

		if (node != NULL)

		{

			cout << "Ž�� ����:Ű ���� " << node->getData();

			printf("�� ���=0x%x\n", node);

		}

		else

			cout << "Ž�� ����: Ű���� " << key << "�� ��� ����" << endl;

		return node;

	}

	BinaryNode* searchRecur(BinaryNode* n, int key)

	{

		if (n == NULL)

			return NULL;

		if (key == n->getData())

			return n;

		else if (key < n->getData())

			return searchRecur(n->getLeft(), key);

		else

			return searchRecur(n->getRight(), key);

	}

	BinaryNode* searchIter(BinaryNode* n, int key)

	{

		while (n != NULL)

		{

			if (key == n->getData())

				return n;

			else if (key < n->getData())

				n = n->getLeft();

			else

				n = n->getRight();

		}

	}

	//���� Ž�� Ʈ���� ���� ����
	void treeInsert(int x) {
		BinaryNode* n = new BinaryNode(x);
		treeInsert(n);
	}

	void treeInsert(BinaryNode* n)

	{

		if (n == NULL)

			return;

		if (isEmpty())

			root = n;

		else

			insertRecur(root, n);

	}

	void insertRecur(BinaryNode* r, BinaryNode* n)

	{

		if (n->getData() == r->getData())

			return;

		else if (n->getData() < r->getData())

		{

			if (r->getLeft() == NULL)

				r->setLeft(n);

			else

				insertRecur(r->getLeft(), n);

		}

		else

		{

			if (r->getRight() == NULL)

				r->setRight(n);

			else

				insertRecur(r->getRight(), n);

		}

	}

	//���� Ž�� Ʈ���� ���� ����
	void treePrint(BinaryNode *n) {
		if (levelcount == 0) { 
			levelorder();
			levelcount++;
		}
		int x = n->getData();
		for (int i = 0; i < n->getlevel(); i++) {
			for (int k = 0; k < 4; k++) {
				cout << " ";
			}
		
		}
		cout << x << endl;
		if (n->getLeft() != NULL) {
			treePrint(n->getLeft());
		}
		if (n->getRight() != NULL) {
			treePrint(n->getRight());
		}

	}
	void treePrint()

	{

		treePrint(root);

	}
	void treeDelete(int key)

	{

		if (isEmpty())

			return;

		//���� ���� �� ����� �θ� ��带 ã�´�

		BinaryNode* parent = NULL; //���� ����� �θ�

		BinaryNode* node = root; //���� ���

		while (node != NULL && node->getData() != key)

		{

			parent = node;

			node = (key < node->getData()) ? node->getLeft() : node->getRight();

		}

		//���� ��尡 Ʈ���� ����

		if (node == NULL)

		{

			cout << "Error: key is not in the tree!" << endl;

			return;

		}

		//���� ��尡 Ʈ���� ����

		else

			treeDelete(parent, node);

	}

	//parent�� �θ�� ���� ��� node�� ����Ž�� Ʈ������ �����ϴ� �Լ�

	void treeDelete(BinaryNode* parent, BinaryNode* node)

	{

		//case1:�����Ϸ��� ��尡 �ܸ������ ���

		if (node->isLeaf())

		{

			if (parent == NULL)

				root = NULL; //����� ���� ������ �����ؾ��ϹǷ� BinaryTree.h�� ��� ���� BinaryNode *root�� protected�� ����

			else

			{

				if (parent->getLeft() == node)

					parent->setLeft(NULL);

				else

					parent->setRight(NULL);

			}

		}

		//case2: �����Ϸ��� ��尡 �����̳� ������ �ڽĸ� ���� ���

		else if (node->getLeft() == NULL || node->getRight() == NULL)

		{

			//������ ����� ������ �ڽĳ��=>child

			BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();

			//������ ��尡 ��Ʈ�̸�==>child�� ���ο� root�� ��

			if (node == root)

				root = child;

			//�ƴϸ�==>�θ����� �ڽ����� �ڽ� ��� child�� ���� ����

			else

			{

				if (parent->getLeft() == node)

					parent->setLeft(child);

				else

					parent->setRight(child);

			}

		}

		//case3: �����Ϸ��� ��尡 �ΰ��� �ڽ��� ��� �ִ� ���

		else

		{

			//�����Ϸ��� ����� ������ ����Ʈ������ ���� ���� ��带 Ž��

			//succ=>�İ� ���:������ ����Ʈ������ ���� key�� ���� ���

			//succp=>�İ� ����� �θ� ���

			BinaryNode* succp = node;

			BinaryNode* succ = node->getRight();

			while (succ->getLeft() != NULL)

			{

				succp = succ;

				succ = succ->getLeft();

			}

			//�İ� ����� �θ�� �İ� ����� ������ �ڽ��� ���� ����

			if (succp->getLeft() == succ)

				succp->setLeft(succ->getRight());

			else //�İ��尡 ������ ����� �ٷ� ������ �ڽ��� ���

				succp->setRight(succ->getRight());

			//�İ� ��� ������ ������ ��忡 ����

			node->setData(succ->getData());

			//������ ��带 �İ� ���� ����: �����δ� �İ� ��尡 ���ŵ�

			node = succ;

		}

		delete node; //�޸� ��������

	}

};