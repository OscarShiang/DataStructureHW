#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Node {
	public:
		Node () {
			s = -1;
			w = -1;
		}

		Node(int s_ipt, int w_ipt) {
			s = s_ipt;
			w = w_ipt;
		}

		int s, w;
};

int main(void) {
	int n, m;
	while (cin >> n >> m) {

		vector <Node> list[n];

		for (int i = 0; i < m; i ++) {
			int s, d, w;
			cin >> s >> d >> w;
			list[s].push_back(Node(d, w));
		}

		Node vertic[n];
		bool visited[n];

		for (int begin = 0; begin < n; ++begin) {
			for (int end = 0; end < n; ++end) {
				if (begin == end)
					continue;

				vertic[begin].w = 0;
				for (int i = 0; i < n; i ++) {
					if (i == begin)
						continue;

					vertic[i] = Node();
					visited[i] = false;
				}


				queue <int> state;
				state.push(begin);

				while (!state.empty()) {
					int index = state.front();
					state.pop();
					visited[index] = true;

					for (int i = 0; i < list[index].size(); i ++) {
						if (vertic[list[index][i].s].w == -1) {
							vertic[list[index][i].s].w = vertic[index].w + list[index][i].w;
							vertic[list[index][i].s].s = index;
						}
						else if (vertic[list[index][i].s].w > vertic[index].w + list[index][i].w) {
							vertic[list[index][i].s].w = vertic[index].w + list[index][i].w;
							vertic[list[index][i].s].s = index;
						}

						if (!visited[list[index][i].s])
							state.push(list[index][i].s);
					}
				}

				vector <int> traverse;
				int index = end;
				while (index != begin) {
					traverse.push_back(index);
					index = vertic[index].s;
				}

				cout << begin; 
				for (int i = traverse.size() - 1; i >= 0; i --) {
					cout << ',' << traverse[i];
				}
				cout << ' ' << vertic[end].w << '\n';
			}

		}
	}

	return 0;
}
