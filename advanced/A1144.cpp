#include <iostream>
#include <set>
using namespace std;

int main() {
	int n, x;
	cin >> n;

	set<int> set;
	int max = 0;
	while (n--) {
		cin >> x;
		if (x <= 0 || set.count(x)) {
			continue;
		}
		set.insert(x);
		if (max < x) {
			max = x;
		}
	}

	// 当[1, max]都在列表中时，缺失的数字为max + 1
	int limit = max + 1;
	for (int i = 1; i <= limit; i++) {
		if (!set.count(i)) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
