// 201614792 ��ǻ�Ͱ��а� ���ű�
#include <queue> 
#include "BinaryNode.h"
class BinaryTree
{
	BinaryNode* root;
public:
	BinaryTree() :root(NULL) {}

	void setRoot(BinaryNode* node) { root = node; }

	BinaryNode* getRoot() { return root; }

	bool isEmpty() { return root == NULL; }

	int getHeight(BinaryNode* node)
	{
		if (node == NULL)
			return 0;
		int hLeft = getHeight(node->getLeft());
		int hRight = getHeight(node->getRight());
		return (hLeft > hRight) ? hLeft + 1 : hRight + 1;

	}

	bool isFull() {
		if (root == NULL) return true;
		else {
			bool facedNull = false;// Null �� ��带 �����ƴ��� �ƴ��� Ȯ���ϱ� ���� ����
			queue<BinaryNode*> Q;
			Q.push(root);

			while (Q.size() > 0) {
				queue<BinaryNode*> tempQ;
				while (Q.size() > 0) {
					BinaryNode* front = Q.front();
					Q.pop();
					BinaryNode* left = front->getLeft();
					BinaryNode* right = front->getRight();

					if (left == NULL && facedNull == false) facedNull = true;// ���ʷ� NULL ��带 ����ģ ��� facedNull �� true��
					if (left != NULL && facedNull == false) { tempQ.push(left); }//���� NUll��带 ����ġ�� �ʾҴٸ� ť�� �ִ´�
					if (left != NULL && facedNull == true) return false;//NUll ��带 �����µ� �ٽ� NULL�� �ƴ� ��尡 ���´ٸ� isFull �� false
					if (right == NULL && facedNull == false) facedNull = true; // ���ʷ� NULL ��带 ����ģ ��� facedNull �� true��
					if (right != NULL && facedNull == false) { tempQ.push(right);}//���� NUll��带 ����ġ�� �ʾҴٸ� ť�� �ִ´�
					if (right != NULL && facedNull == true) return false;//NUll ��带 �����µ� �ٽ� NULL�� �ƴ� ��尡 ���´ٸ� isFull �� false         
				}
				Q = tempQ;//Q�� ���� ������ ������Ʈ
			}

			//�߰��� ���� ��ȯ���� �ʰ� ������� �Դٴ°��� 
			//Null ��带 ����ģ �ڷδ� ��� NULL ��尡 ���Դٴ� ����( ex >> (a) (b) (NULL) (NULL) ) 
			 
			return Q.size() == 0 ? true : false;//if(Q.size() == 0) return true; else return false;
		}
	}
	int level(BinaryNode* node)
	{
		return level(root, node);
	}

	int level(BinaryNode* node1, BinaryNode* node2, int lev = 1) //node2�� �츮�� ã���� �ϴ� node
	{
		if (node1 == NULL)
			return 0;
		if (node1 == node2)
			return lev;

		if (node1->getLeft() == NULL && node1->getRight() == NULL)
			return 0;
		//���
		int left = level(node1->getLeft(), node2, lev + 1); //��������
		int right = level(node1->getRight(), node2, lev + 1); //����������

		if (!left) //���� ��尡 �������� �ʴ´ٸ�
			return right; //������ ��� ��ȯ
		else //�ݴ�
			return left;
	}
	bool isBalanced(BinaryNode* node)
	{
		int left;
		int right;

		if (node == NULL)
			return true;

		left = getHeight(node->getLeft());
		right = getHeight(node->getRight());

		if ((left - right) <= 1 && (left - right) >= -1 && isBalanced(node->getLeft()) && isBalanced(node->getRight()))
			return true;

		return false;
	}
	bool isBalanced()
	{
		return isBalanced(root);
	}

	bool reverse(BinaryNode* node)
	{
		if (node == NULL)
			return false;
		else
		{
			reverse(node->getLeft());
			reverse(node->getRight());
			//leftNode�� rightNode�� ���� �ٲ۴�
			BinaryNode* temp = node->getLeft();
			node->setLeft(node->getRight());
			node->setRight(temp);
		}
		return true;
	}
	bool reverse()
	{
		return reverse(root);
	}
};