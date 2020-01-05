#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;

class condition {
	public:
		condition(int key_ipt, int pos_ipt) : key(key_ipt), pos(pos_ipt) {
		}
		int key;
		int pos;
};

bool compare(const condition a, const condition b) {
	return a.key < b.key;
}

int median(vector <int> data, int left, int right) {
	vector <condition> cmp;
	cmp.push_back(condition(data[left], left));
	cmp.push_back(condition(data[(left + right) / 2], (left + right) / 2));
	cmp.push_back(condition(data[right], right));
	sort(cmp.begin(), cmp.end(), compare);
	return cmp[1].pos;
}

void qsort(vector <int> &data, int left, int right) {
	int pivot, i, j;
	if (left < right) {
		i = left;
		j = right + 1;

		// pivot choose
		int pos = median(data, left, right);

		pivot = data[pos];

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
		swap(data[pos], data[j]);

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
