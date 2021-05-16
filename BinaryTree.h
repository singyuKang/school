// 201614792 컴퓨터공학과 강신규
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
			bool facedNull = false;// Null 인 노드를 마주쳤는지 아닌지 확인하기 위한 변수
			queue<BinaryNode*> Q;
			Q.push(root);

			while (Q.size() > 0) {
				queue<BinaryNode*> tempQ;
				while (Q.size() > 0) {
					BinaryNode* front = Q.front();
					Q.pop();
					BinaryNode* left = front->getLeft();
					BinaryNode* right = front->getRight();

					if (left == NULL && facedNull == false) facedNull = true;// 최초로 NULL 노드를 마주친 경우 facedNull 을 true로
					if (left != NULL && facedNull == false) { tempQ.push(left); }//아직 NUll노드를 마주치지 않았다면 큐에 넣는다
					if (left != NULL && facedNull == true) return false;//NUll 노드를 만났는데 다시 NULL이 아닌 노드가 나온다면 isFull 은 false
					if (right == NULL && facedNull == false) facedNull = true; // 최초로 NULL 노드를 마주친 경우 facedNull 을 true로
					if (right != NULL && facedNull == false) { tempQ.push(right);}//아직 NUll노드를 마주치지 않았다면 큐에 넣는다
					if (right != NULL && facedNull == true) return false;//NUll 노드를 만났는데 다시 NULL이 아닌 노드가 나온다면 isFull 은 false         
				}
				Q = tempQ;//Q를 다음 레벨로 업데이트
			}

			//중간에 값이 반환되지 않고 여기까지 왔다는것은 
			//Null 노드를 마주친 뒤로는 계속 NULL 노드가 나왔다는 것임( ex >> (a) (b) (NULL) (NULL) ) 
			 
			return Q.size() == 0 ? true : false;//if(Q.size() == 0) return true; else return false;
		}
	}
	int level(BinaryNode* node)
	{
		return level(root, node);
	}

	int level(BinaryNode* node1, BinaryNode* node2, int lev = 1) //node2가 우리가 찾고자 하는 node
	{
		if (node1 == NULL)
			return 0;
		if (node1 == node2)
			return lev;

		if (node1->getLeft() == NULL && node1->getRight() == NULL)
			return 0;
		//재귀
		int left = level(node1->getLeft(), node2, lev + 1); //왼쪽으로
		int right = level(node1->getRight(), node2, lev + 1); //오른쪽으로

		if (!left) //왼쪽 노드가 존재하지 않는다면
			return right; //오른쪽 노드 반환
		else //반대
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
			//leftNode와 rightNode를 서로 바꾼다
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