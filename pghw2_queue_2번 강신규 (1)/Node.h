#include <cstdio> //201614792 ��ǻ�Ͱ��а� ���ű�
class Node {
	Node* link;
	int x; //x��ǥ ������ ����
	int y; //y��ǥ ������ ����
public:
	Node(int a=0, int b=0)  {
		link = NULL;
		x = a; 
		y = b;
	}
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }


	int getrow() {
		return x; //x��ǥ ������ ���
	}
	int getcol() {
		return y; //y��ǥ ������ ���
	}

};