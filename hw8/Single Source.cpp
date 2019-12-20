#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class node {
	public:
		node () {
			s = -1;
			w = -1;
		}

		node(int s_ipt, int w_ipt) {
			s = s_ipt;
			w = w_ipt;
		}

		int s, w;
};

int main(void) {
	int n, m;
	while(cin >> n >> m) {

		vector <node> list[n];

		for (int i = 0; i < m; i ++) {
			int s, d, w;
			cin >> s >> d >> w;
			list[s].push_back(node(d, w));
		}

		node vertic[n];
		bool visited[n];
		vertic[0].w = 0;
		for (int i = 1; i < n; i ++) 
			visited[i] = false;

		
		queue <int> state;
		state.push(0);

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
		for (int i = 1; i < n; i ++) {
			if (vertic[i].w == -1) 
				cout << "Impossible\n";
			else {
				int index = i;
				traverse.push_back(i);
				while (index != 0) {
					traverse.push_back(vertic[index].s);
					index = vertic[index].s;
				}

				cout << traverse[traverse.size() - 1];
				for (int j = traverse.size() - 2; j >= 0; j --) {
					cout << "," << traverse[j];
				}
				cout << ' ' << vertic[i].w << '\n';
			}

			traverse.clear();
		}
	}
	return 0;
}
