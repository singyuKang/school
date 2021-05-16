#include <cstdio> //201614792 컴퓨터공학과 강신규
class Node {
	Node* link;
	int x; //x좌표 데이터 저장
	int y; //y좌표 데이터 저장
public:
	Node(int a=0, int b=0)  {
		link = NULL;
		x = a; 
		y = b;
	}
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }


	int getrow() {
		return x; //x좌표 데이터 얻기
	}
	int getcol() {
		return y; //y좌표 데이터 얻기
	}

};