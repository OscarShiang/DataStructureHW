#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	// generate the cards
	srand(time(NULL));
	const string options[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	int cards[13];
	bool exist[13];
	for (int i = 0; i < 13; i++)
		exist[i] = true;

	for (int i = 0; i < 13; i++) {
		int rnd;
		do {
			rnd = rand() % 13;
		} while (!exist[rnd]);
		cards[i] = rnd;
		exist[rnd] = false;
	}

	int remains = 13;
	while (remains > 0) {
		for (int i = 0; i < remains; i ++) {
			cout << options[cards[i]] << ' ';
		}
		cout << '\n';
		
		bool match;
		int tmp;
		if (remains - 1 == cards[0]) {
			remains --;
			match = true;
		}
		else {
			tmp = cards[0];
			match = false;
		}
		for (int i = 1; i < remains + 1; i ++)
			cards[i - 1] = cards[i];
		if (!match) 
			cards[remains - 1] = tmp;
	}

	return 0;
}
