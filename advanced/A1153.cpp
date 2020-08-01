#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Testee {
	char level;
	int siteNumber;
	int date;
	int no;
	int score;
	string cardNumber;
};

struct site {
	int siteNumber;
	int personNumber;
	site(int siteNumber, int personNumber) {
		this->siteNumber = siteNumber;
		this->personNumber = personNumber;
	}
};

bool cmp(Testee a, Testee b) {
	if (a.score != b.score) {
		return a.score > b.score;
	}
	return a.cardNumber.compare(b.cardNumber) < 0;
}

bool cmp2(site a, site b) {
	if (a.personNumber != b.personNumber) {
		return a.personNumber > b.personNumber;
	}
	return a.siteNumber < b.siteNumber;
}

int main() {
	int n, m;
	cin >> n >> m;

	Testee arr[n];
	for (int i = 0; i < n; i++) {
		Testee testee;
		cin >> testee.cardNumber >> testee.score;

		string cardNumber = testee.cardNumber;
		testee.level = cardNumber[0];
		testee.siteNumber = stoi(cardNumber.substr(1, 3));
		testee.date = stoi(cardNumber.substr(4, 6));
		testee.no = stoi(cardNumber.substr(10, 3));

		arr[i] = testee;
	}

	for (int i = 1; i <= m; i++) {
		int type;
		string term;
		cin >> type >> term;

		vector<Testee> testees;
		printf("Case %d: %d %s\n", i, type, term.c_str());
		if (type == 1) {
			for (auto &x : arr) {
				if (x.level == term[0]) {
					testees.push_back(x);
				}
			}
			sort(testees.begin(), testees.end(), cmp);

			if (testees.empty()) {
				printf("NA\n");
			} else {
				for (auto &x : testees) {
					printf("%s %d\n", x.cardNumber.c_str(), x.score);
				}
			}
		} else if (type == 2) {
			for (auto &x : arr) {
				if (x.siteNumber == stoi(term)) {
					testees.push_back(x);
				}
			}
			if (testees.empty()) {
				printf("NA\n");
			} else {
				int total = testees.size();
				int scores = 0;
				for (auto &x : testees) {
					scores += x.score;
				}
				printf("%d %d\n", total, scores);
			}
		} else {
			vector<site> sites;
			map<int, int> dict;
			for (auto &x : arr) {
				if (x.date == stoi(term)) {
					dict[x.siteNumber]++;
				}
			}
			for (auto &x : dict) {
				sites.push_back(site(x.first, x.second));
			}
			sort(sites.begin(), sites.end(), cmp2);

			if (sites.empty()) {
				printf("NA\n");
			} else {
				for (auto &x : sites) {
					printf("%d %d\n", x.siteNumber, x.personNumber);
				}
			}
		}
	}

	return 0;
}
