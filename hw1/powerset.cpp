#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector <string> result;

void powerset(vector <int> &bits, int dep, vector <string> set) {
	if (dep == set.size()) {
		string tmp = "";
		tmp += "{";
		if (bits.at(0)) {
			tmp += set.at(0);
		}
		for (int i = 1; i < set.size(); i++) {
			if (bits[i] && tmp.size() > 1)
				tmp += " " + set.at(i);
			else if (bits[i])
				tmp += set.at(i);
		}
		tmp += "}";
		result.push_back(tmp);
		return;
	}
	bits.at(dep) = 1;
	powerset(bits, dep + 1, set);
	bits.at(dep) = 0;
	powerset(bits, dep + 1, set);

}

bool cmp(string a, string b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	else
		return a.at(1) < b.at(1);
}

int main(void) {
	string ipt;
	while (getline(cin, ipt)) {
		result.clear();	
		vector <string> set;
		stringstream ss(ipt);
		for (string each; getline(ss, each, ' '); set.push_back(each));
	
		vector <int> bits;
		bits.assign(set.size(), 0);
		powerset(bits, 0, set);

		sort(result.begin(), result.end(), cmp);
		for (int i = 0; i < result.size(); ++i) {
			cout << result.at(i) << ' ';
		}
		cout << '\n';
	}
	return 0;
}
