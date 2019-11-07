#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Queue {
	public:
		Queue() {
			length = 0;
		}

		void enqueue(char c, vector <char> friends) {
			// check for friends
			int pos = 999999;
			if (friends.empty()) {
				pos = length;
			}
			else {
				for (int i = 0; i < friends.size(); i ++) { 
					for (int j = 0; j < length; j ++) {
						if (c == friends[i])
							continue;
						if (data[j] == friends[i]) 
							pos = min(pos, j);
					}
				}
	
				for (int i = length; i > pos; i --) {
					data[i] = data[i - 1];
				}
			}
			data[min(pos, length)] = c;
			
			length ++;
		}

		char dequeue() {
			if (length <= 0)
				return '\0';
			
			char front = data[0];
			for (int i = 1; i < length; i ++) {
				data[i - 1] = data[i];
			}

			length --;
			return front;
		}

		void print() {
			for (int i = 0; i < length; i ++) 
				cout << data[i] << " ";
			cout << '\n';
		}

	private:
		int length;
		char data[50];
};

int main(void) {
	int n;
	cin >> n;

	vector <char> friends[n];

	for (int i = 0; i < n; i ++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j ++) {
			char input;
			cin >> input;
			friends[i].push_back(input);
		}
	}
	
	Queue queue;
	string operation;
	while (cin >> operation) {
		if (operation == "ENQUEUE") {
			char input;
			cin >> input;

			vector <char> choose = vector <char>();
			for (int i = 0; i < n; i ++) {
				if (find(friends[i].begin(), friends[i].end(), input) != friends[i].end()) {
					choose = friends[i];
				}
			}

			queue.enqueue(input, choose);
		}
		else if (operation == "DEQUEUE") {
			cout << queue.dequeue() << '\n';
		}

		// cout << "Queue state: ";
		// queue.print();
	}
	return 0;
}
