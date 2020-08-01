#include <iostream>
#include <string>
using namespace std;

string parse(string num, int n) {
	string str = "0.";

	// 去掉前导0
	while (num.size() > 0 && num[0] == '0') {
		num.erase(num.begin());
	}

	int e = 0, k = 0;
	if (num[0] == '.') {
		num.erase(num.begin());
		while (num.size() > 0 && num[0] == '0') {
			num.erase(num.begin());
			e--;
		}
	} else {
		while (k < num.size() && num[k] != '.') {
			k++;
			e++;
		}
		if (k < num.size()) {
			num.erase(num.begin() + k);
		}
	}
	if (num.size() == 0) {
		e = 0;
	}

	k = 0;
	for (int i = 0; i < n; i++) {
		if (k < num.size()) {
			str += num[k++];
		} else {
			str += '0';
		}
	}

	str += "*10^" + to_string(e);
	return str;
}

int main() {
	int n;
	cin >> n;

	string a, b;
	cin >> a >> b;
	a = parse(a, n);
	b = parse(b, n);

	if (a == b) {
		cout << "YES " << a << endl;
	} else {
		cout << "NO " << a << ' ' << b << endl;
	}

	return 0;
}
