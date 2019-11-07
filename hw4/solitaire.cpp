#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const string options[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

typedef struct node {
	int data;
	struct node *next;
} Node;

class List {
	public:
		List(int n) {
			srand(time(NULL));
			
			bool exist[n];
			int cards[n];
			for (int i = 1; i <= n; i ++) {
				cards[i - 1] = i;
				exist[i - 1] = false;
			}

			head = new Node();

			int rnd = rand() % n;
			head->data = cards[rnd];
			exist[rnd] = true;
			
			Node *curr = head;
			for (int i = 1; i < n; i ++) {
				do {
					rnd = rand() % n;
				} while (exist[rnd]);
				curr = insert(curr, cards[rnd]);
				exist[rnd] = true;
			}
			tail = curr;
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

		Node *insert(Node *prev, int data_ipt) {
			Node *node = new Node();

			Node *next = prev->next;
			prev->next = node;
			node->next = next;

			node->data = data_ipt;

			return node;
		}

		void printList() {
			Node *curr = head;
			while (curr != NULL) { 
				cout << options[curr->data - 1] << ' ';
				curr = curr->next;
			}
			cout << '\n';
		}

		Node *pop() {
			Node *node = head;
			head = head->next;

			return node;
		}

		void push(Node* node) {
			tail->next = node;
			node->next = NULL;
			tail = node;
		}

		int front() {
			return head->data;
		}

	private:
		Node *head;
		Node *tail;
};

int main(void) {	
	List list(13);

	int remain = 13;
	while (remain > 0) {
		list.printList();
		if (list.front() == remain) {
			delete list.pop();
			remain --;
		}
		else {
			list.push(list.pop());
		}
	}

	return 0;
}
