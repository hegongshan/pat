#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int digitSum(int x) {
	int sum = 0;
	while (x > 0) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

int main() {
	int n, x;
	cin >> n;

	set<int> friendNumber;
	while (n--) {
		cin >> x;
		friendNumber.insert(digitSum(x));
	}

	cout << friendNumber.size() << endl;
	for (set<int>::iterator iter = friendNumber.begin();
			iter != friendNumber.end(); iter++) {
		if (iter != friendNumber.begin()) {
			cout << " ";
		}
		cout << *iter;
	}
	cout << endl;
	return 0;
}
