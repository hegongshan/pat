#include <iostream>
#include <cmath>
#include <map>
#include <set>
using namespace std;

bool isPrime(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;

	map<string, int> ranklist;
	for (int i = 1; i <= n; i++) {
		string id;
		cin >> id;

		ranklist[id] = i;
	}

	int k;
	cin >> k;
	set<string> queryIds;
	for (int i = 0; i < k; i++) {
		string queryId;
		cin >> queryId;

		cout << queryId << ": ";
		// 如果已经查过了
		if (queryIds.count(queryId)) {
			cout << "Checked";
		} else if (ranklist.count(queryId)) {
			int rank = ranklist[queryId];
			queryIds.insert(queryId);

			if (rank == 1) {
				cout << "Mystery Award";
			} else if (isPrime(rank)) {
				cout << "Minion";
			} else {
				cout << "Chocolate";
			}
		} else { // 如果query ID不存在
			cout << "Are you kidding?";
		}

		cout << endl;
	}
	return 0;
}
