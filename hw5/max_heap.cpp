#include <iostream>
#include <algorithm>
using namespace std;

void buildTree(int tree[], int n) {
	int array[n];
	for (int i = 1; i < n; i++) {
		array[i] = tree[i];
		int index = i;
		while (index / 2 >= 1 && array[index] > array[index / 2]) {
			swap(array[index], array[index / 2]);
			index /= 2;
		}
	}
	for (int i = 1; i < n; i ++) {
		tree[i] = array[i];
	}
}

int main(void) {
	int m, n, times, *tree;
	cin >> times;

	while (times --) {
		cin >> m >> n;
		tree = new int [m + 1];

		// initialize the tree
		for (int i = 1; i <= m; i++) {
			cin >> tree[i];
		}
		buildTree(tree, m + 1);

		int sum = 0;
		for (int i = 0; i < n; i ++) {
			sum += tree[1];
			tree[1] --;
			buildTree(tree, m + 1);
		}
		
		cout << sum << '\n';
		delete[] tree;
	}
	return 0;
}
