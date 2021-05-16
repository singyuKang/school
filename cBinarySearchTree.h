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

			printf("에러");

		else

		{

			rear = (rear + 1) % MAX_QUEUE_SIZE;

			data[rear] = n;

		}

	}

	BinaryNode* dequeue()

	{

		if (isEmpty())

			printf("에러");
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

			//재귀

			reverse(node->getLeft());

			reverse(node->getRight());

			//leftNode와 rightNode를 서로 바꾼다

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

	//순환 호출에 의해 node를 루트로 하는 트리의 전체 용량 계산 함수

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

	void levelorder() //레벨 장착

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

	//이진 탐색 트리의 탐색 연산

	BinaryNode* search(int key)

	{

		BinaryNode* node = searchRecur(root, key);

		if (node != NULL)

		{

			cout << "탐색 성공:키 값이 " << node->getData();

			printf("인 노드=0x%x\n", node);

		}

		else

			cout << "탐색 실패: 키값이 " << key << "인 노드 없음" << endl;

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

	//이진 탐색 트리의 삽입 연산
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

	//이진 탐색 트리의 삭제 연산
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

		//없앨 노드와 그 노드의 부모 노드를 찾는다

		BinaryNode* parent = NULL; //없앨 노드의 부모

		BinaryNode* node = root; //없앨 노드

		while (node != NULL && node->getData() != key)

		{

			parent = node;

			node = (key < node->getData()) ? node->getLeft() : node->getRight();

		}

		//없앨 노드가 트리에 없음

		if (node == NULL)

		{

			cout << "Error: key is not in the tree!" << endl;

			return;

		}

		//없앨 노드가 트리에 있음

		else

			treeDelete(parent, node);

	}

	//parent를 부모로 갖는 노드 node를 이진탐색 트리에서 삭제하는 함수

	void treeDelete(BinaryNode* parent, BinaryNode* node)

	{

		//case1:삭제하려는 노드가 단말노드일 경우

		if (node->isLeaf())

		{

			if (parent == NULL)

				root = NULL; //상속을 받은 변수를 접근해야하므로 BinaryTree.h의 멤버 변수 BinaryNode *root를 protected로 선언

			else

			{

				if (parent->getLeft() == node)

					parent->setLeft(NULL);

				else

					parent->setRight(NULL);

			}

		}

		//case2: 삭제하려는 노드가 왼쪽이나 오른쪽 자식만 갖는 경우

		else if (node->getLeft() == NULL || node->getRight() == NULL)

		{

			//삭제할 노드의 유일한 자식노드=>child

			BinaryNode* child = (node->getLeft() != NULL) ? node->getLeft() : node->getRight();

			//삭제할 노드가 루트이면==>child가 새로운 root가 됨

			if (node == root)

				root = child;

			//아니면==>부모노드의 자식으로 자식 노드 child를 직접 연결

			else

			{

				if (parent->getLeft() == node)

					parent->setLeft(child);

				else

					parent->setRight(child);

			}

		}

		//case3: 삭제하려는 노드가 두개의 자식이 모두 있는 경우

		else

		{

			//삭제하려는 노드의 오른쪽 서브트리에서 가장 작은 노드를 탐색

			//succ=>후계 노드:오른쪽 서브트리에서 가장 key가 작은 노드

			//succp=>후계 노드의 부모 노드

			BinaryNode* succp = node;

			BinaryNode* succ = node->getRight();

			while (succ->getLeft() != NULL)

			{

				succp = succ;

				succ = succ->getLeft();

			}

			//후계 노드의 부모와 후계 노드의 오른쪽 자식을 직접 연결

			if (succp->getLeft() == succ)

				succp->setLeft(succ->getRight());

			else //후계노드가 삭제할 노드의 바로 오른쪽 자식인 경우

				succp->setRight(succ->getRight());

			//후계 노드 정보를 삭제할 노드에 복사

			node->setData(succ->getData());

			//삭제할 노드를 후계 노드로 변경: 실제로는 후계 노드가 제거됨

			node = succ;

		}

		delete node; //메모리 동적해제

	}

};