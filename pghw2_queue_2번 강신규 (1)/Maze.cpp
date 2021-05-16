#include <iostream> //201614792 ��ǻ�Ͱ��а� ���ű�
#include "Location2D.h"
#include <iostream>
#include <fstream>
#include "LinkedList.cpp"

using namespace std;
const int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE];


bool isValidLoc(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= MAZE_SIZE) return false;
	else return map[r][c] == '0' || map[r][c] == 'x'; //(r,c)�� �� �� �ִ� ��ġ���� �˻��ϴ�. r,c �� �迭�ȿ� �ְ� ���� �����ִ� ��ġ '0' �̰ų� 'x'�̾����
}

void main() {
	ifstream ifs;
	char line[200];
	int row = 0;
	ifs.open("Text.txt"); //���� 6X6 ���¿��� �Ѵ�
	if (!ifs.is_open()) {
		cout << "������ �� ���� �����ϴ�" << endl;
		exit(1);
	}
	else {
		cout << "������ ������" << endl;
		cout << "�ʻ���:\n" << endl;
		while (ifs.getline(line, sizeof(line))) // �� �پ� �о� ó���� �����Ѵ�.
		{
			int col = 0;
			cout << line << endl; // ���� ���
			for (int i = 0; i < 6; i++) {
				map[row][col] = line[i];
				col++;
			}
			row++;
		}
		cout << "\n" << endl;

		ifs.close();

	}


	LinkedList locQueue;//ó�� ����=�Ա��� (1,0)
	locQueue.enqueue(new Node(1,0));

	while (locQueue.isEmpty() == false) {
		Node* here = locQueue.peek();
		int r = here->getrow();
		int c = here->getcol();

		delete locQueue.dequeue();
		printf("(%d,%d)", r, c);
		if (map[r][c] == 'x') {
			printf("�̷� Ž�� ����\n");
			printf("�̷��ⱸ��(%d,%d)", r, c);
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
	printf("�̷� Ž�� ����\n");

}