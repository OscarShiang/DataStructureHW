#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class activity {
	public:
		activity(int n_ipt, int v_ipt, int w_ipt) {
			n = n_ipt;
			v = v_ipt;
			w = w_ipt;
		}
		int n, v, w;
};

class eventTime {
	public:
		eventTime() {
			ee = -1;
			le = 999999999;
		}
		int ee, le;
};

class actTime {
	public:
		actTime() {
			e = 0;
			l = 0;
		}
		int e, l;
};

class state {
	public:
		state(int start_ipt, int cost_ipt) {
			start = start_ipt;
			cost = cost_ipt;
		}
		int start, cost;
};

int main(void) {
	int n, N;
	vector <activity> graph[100];
	eventTime event[100];
	
	cin >> n;

	for (int i = 0; i < n; i ++) {
		int t, u, v, w;
		cin >> t >> u >> v >> w;
		graph[u].push_back(activity(t, v, w));

		N = max(N, u);
		N = max(N, v);
	}

	queue <state> bfs;
	bfs.push(state(0, 0));
	while (!bfs.empty()) {
		state curr = bfs.front();
		bfs.pop();
		
		event[curr.start].ee = max(event[curr.start].ee, curr.cost);
		for (int i = 0; i < graph[curr.start].size(); i ++) {
			bfs.push(state(graph[curr.start][i].v, curr.cost + graph[curr.start][i].w));
		}
	}

	bfs.push(state(N, event[N].ee));
	while (!bfs.empty()) {
		state curr = bfs.front();
		bfs.pop();

		event[curr.start].le = min(event[curr.start].le, curr.cost);
		for (int i = 0; i <= N; i ++) {
			for (int j = 0; j < graph[i].size(); j ++) {
				if (graph[i][j].v == curr.start) {
					bfs.push(state(i, curr.cost - graph[i][j].w));
				}
			}
		}
	}

	actTime node[n];
	for (int i = 0; i < N; i ++) {
		for (int j = 0; j < graph[i].size(); j ++) {
			int act = graph[i][j].n - 1;
			node[act].e = event[i].ee;
			node[act].l = event[graph[i][j].v].le - graph[i][j].w;
		}
	}

	cout << "event\tee\tle\n";
	for (int i = 0; i <= N; i ++) {
		cout << i << '\t' << event[i].ee << '\t' << event[i].le << '\n';
	}

	vector <int> critical;

	cout << "\nact.\te\tl\tslack\tcritical\n";
	for (int i = 0; i < n; i ++) {
		int slack = abs(node[i].l - node[i].e);
		cout << i + 1 << '\t' << node[i].e << '\t' << node[i].l << '\t' << slack << '\t';
		if (!slack) {
			cout << "Yes\n";
			critical.push_back(i + 1);
		}
		else 
			cout << "No\n";
	}

	if (!critical.empty()) {
		cout << '\n';
		cout << critical[0];
		for (int i = 1; i < critical.size(); i ++) {
			cout << ' ' << critical[i];
		}
		cout << '\n';
	}
	return 0;
}
