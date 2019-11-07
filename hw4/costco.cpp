#include <iostream>
using namespace std;

typedef struct node {
	char data;
	struct node *next;
} Node;

class List {
	public:
		List() {
			head = new Node();
			head->data = '\0';
			tail = head;
			tail->next = NULL;
		}

		~List() {
			int i = 0;
			Node *curr = head;
			while (curr != NULL) {
				i ++;
				Node *next = curr->next;
				delete curr;
				curr = next;
			}
			// cout << "delete " << i << " items" << endl;
		}

		void insert(Node *prev, char data_ipt) {
			Node *node = new Node();
			node->data = data_ipt;
			
			if (prev == head) {
				node->next = head;
				head = node;
			}
			else {
				Node *next = prev->next;
				prev->next = node;
				node->next = next;
			}
		}

		void push(char data_ipt) {
			Node *node;
			if (head->data == '\0')
				node = head;
			else 
				node = new Node();
			node->data = data_ipt;

			tail->next = node;
			node->next = NULL;
			tail = node;
		}

		void printList() {
			Node *curr = head;
			while (curr != NULL) {
				cout << curr->data << ' ';
				curr = curr->next;
			}
			cout << '\n';
		}

		void enqueue(char data_ipt, char friends[]) {
			if (friends[0] == '\0') {
				push(data_ipt);
			}
			else {
				Node *pos = NULL;
	
				Node *curr = head, *prev = head;
				while (curr != NULL) {
					int i = 0;
					while (friends[i] != '\0') {
						if (data_ipt == friends[i]) {
							i ++;
							continue;
						}
						if (curr->data == friends[i]) {
							pos = prev;
							break;
						}
						i ++;
					}
					if (pos != NULL)
						break;
					prev = curr;
					curr = curr->next;
				}

				if (pos == NULL) {
					push(data_ipt);
				}
				else {
					insert(pos, data_ipt);
				}
			}
			
		}

		char dequeue() {
			if (head == NULL)
				return -1;

			Node *node = head->next;
			char data = head->data;
	
			delete head;
			head = node;

			return data;
		}

		private:
			Node *head;
			Node *tail;
};


int main(void) {
	int n;
	cin >> n;
	char friends[n][27];
	for (int i = 0; i < n; i ++) {
		int m, j;
		cin >> m;
		for (j = 0; j < m; j ++) 
			cin >> friends[i][j];
		friends[i][j] = '\0';
	}

	List list;
	string operation;
	while (cin >> operation) {
		if (operation == "ENQUEUE") {
			char data;
			cin >> data;

			int index = -1;

			for (int i = 0; i < n; i ++) {
				int j = 0;
				while (friends[i][j] != '\0') {
					if (data == friends[i][j]) {
						index = i;
						break;
					}
					j ++;
				}

				if (index != -1) 
					break;
			}

			if (index == -1)
				list.enqueue(data, (char *)"");
			else
				list.enqueue(data, friends[index]);
		}
		else if (operation == "DEQUEUE") {
			cout << list.dequeue() << '\n';
		}
	}



	return 0;
}
