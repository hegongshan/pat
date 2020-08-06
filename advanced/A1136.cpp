#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const char cArr[11] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

bool isPalindrome(string a) {
	int len = a.length();
	for (int i = 0; i < len / 2; i++) {
		if (a[i] != a[len - 1 - i]) {
			return false;
		}
	}
	return true;
}

// a和b长度相等
string add(string a, string b) {

	int carry = 0;
	int j = a.length() - 1;
	int k = b.length() - 1;

	string result;
	for (int i = 0; i < a.size(); i++) {
		int val = (a[j] - '0') + (b[k] - '0') + carry;
		carry = val / 10;
		result += cArr[val % 10];
		j--;
		k--;
	}

	if (carry > 0) {
		result += cArr[carry];
	}

	reverse(result.begin(), result.end());
	return result;
}

int main() {
	string a;
	cin >> a;
	for (int i = 0; i < 10 && !isPalindrome(a); i++) {
		string b = a;
		reverse(b.begin(), b.end());
		string c = add(a, b);

		printf("%s + %s = %s\n", a.c_str(), b.c_str(), c.c_str());
		a = c;
	}

	if (isPalindrome(a)) {
		printf("%s is a palindromic number.\n", a.c_str());
	} else {
		printf("Not found in 10 iterations.\n");
	}
	return 0;
}
