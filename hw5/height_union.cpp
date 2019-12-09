#include <iostream>
#include <vector>
#include <string>
using namespace std;

int collapsingFind(int num, vector <int> &tree) {
	int root, trail, lead;
	int cnt = 0;

	// find root
	root = num;
	while (tree[root] >= 0) {
		root = tree[root];
		cnt ++;
	}

	for (trail = num; trail != root; trail = lead) {
		lead = tree[trail];
		if (tree[trail] != root) {
			tree[trail] = root;
			cnt ++;
		}
	}
	return cnt;
}

void heightUnion(int a, int b, vector <int> &tree) {
	int height = tree[a] + tree[b];

	if (tree[a] > tree[b]) {
		tree[a] = b;
		tree[b] = height;
	}
	else {
		tree[b] = a;
		tree[a] = height;
	}
}

int main(void) {
	int n;
	vector <int> tree;
	cin >> n;

	// setting tree
	while (n --) {
		int nodes;
		cin >> nodes;

		for (int i = 0; i < nodes; ++i) {
			int node, tmp;
			cin >> node >> tmp;
			tree.push_back(tmp);
		}
	}

	// operations
	string opt;
	while (cin >> opt) {
		if (opt == "STOP")
			break;
		else if (opt == "UNION") {
			int i, j;
			cin >> i >> j;
			heightUnion(i, j, tree);
		}
		else if (opt == "FIND") {
			int p;
			cin >> p;
			cout << collapsingFind(p, tree) << '\n';
		}
	}

	return 0;
}
