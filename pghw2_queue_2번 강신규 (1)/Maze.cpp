#include <iostream> //201614792 컴퓨터공학과 강신규
#include "Location2D.h"
#include <iostream>
#include <fstream>
#include "LinkedList.cpp"

using namespace std;
const int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE];


bool isValidLoc(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x'; //(r,c)가 갈 수 있는 위치인지 검사하는. r,c 가 배열안에 있고 값이 갈수있는 위치 '0' 이거나 'x'이어야함
}

void main() {
	ifstream ifs;
	char line[200];
	int row = 0;
	ifs.open("Text.txt"); //맵은 6X6 형태여야 한다
	if (!ifs.is_open()) {
		cout << "파일을 열 수가 없습니다" << endl;
		exit(1);
	}
	else {
		cout << "파일을 열었음" << endl;
		cout << "맵상태:\n" << endl;
		while (ifs.getline(line, sizeof(line))) // 한 줄씩 읽어 처리를 시작한다.
		{
			int col = 0;
			cout << line << endl; // 내용 출력
			for (int i = 0; i < 6; i++) {
				map[row][col] = line[i];
				col++;
			}
			row++;
		}
		cout << "\n" << endl;

		ifs.close();

	}


	LinkedList locQueue;//처음 시작=입구를 (1,0)
	locQueue.enqueue(new Node(1,0));

	while (locQueue.isEmpty() == false) {
		Node* here = locQueue.peek();
		int r = here->getrow();
		int c = here->getcol();

		delete locQueue.dequeue();
		printf("(%d,%d)", r, c);
		if (map[r][c] == 'x') {
			printf("미로 탐색 성공\n");
			printf("미로출구는(%d,%d)", r, c);
			return;
		}
		else {
			map[r][c] = '.';
			if (isValidLoc(r - 1, c)) locQueue.enqueue(new Node(r - 1, c));
			if (isValidLoc(r + 1, c)) locQueue.enqueue(new Node(r + 1, c));
			if (isValidLoc(r, c - 1)) locQueue.enqueue(new Node(r , c - 1));
			if (isValidLoc(r, c + 1)) locQueue.enqueue(new Node(r , c+1));



		}
	}
	printf("미로 탐색 실패\n");

}