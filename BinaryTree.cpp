#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int getParent(int parent[], int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b)parent[b] = a;
	else parent[a] = b;
}

int find(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) {
		return 1;
	}
	else {
		return 0;
	}
}
class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator<(Edge& edge) {
		return this->distance < edge.distance;
	}
};

int main() {

	vector<Edge> v;
	int n;
	int line;

	cin >> n;
	cin >> line;

	int* set = new int[n];
	for (int i = 0; i < line; i++) {
		int node1, node2, weight;
		cin >> node1 >> node2 >> weight;
		v.push_back(Edge(node1, node2, weight));
	}


	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		set[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{

		if (!find(set, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			cout << v[i].distance << " ";
			unionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}
	cout << sum << endl;
	return 0;
}
