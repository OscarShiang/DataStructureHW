#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

void qsort(vector <int> &data, int left, int right) {
	int pivot, i, j;
	if (left < right) {
		i = left;
		j = right + 1;

		// pivot choose
		pivot = data[left];

		do {
			do {
				i ++;
			} while (data[i] < pivot);
			do {
				j --;
			} while (data[j] > pivot);

			if (i < j)
				swap(data[i], data[j]);
		} while (i < j);
		swap(data[left], data[j]);
		
		// sort order
		if (j - left > right - j) {
			qsort(data, j + 1, right);
			qsort(data, left, j - 1);
		}
		else {
			qsort(data, left, j - 1);
			qsort(data, j + 1, right);
		}
	}
}

int main(void) {
	clock_t start, end;
	double cpu_time;

	int tmp;
	vector <int> data;
	while (cin >> tmp) {
		data.push_back(tmp);
	}

	start = clock();
	qsort(data, 0, data.size() - 1);
	end = clock();

	cout << "time cost: " << (double)(end - start) / CLOCKS_PER_SEC << '\n';
	return 0;
}
