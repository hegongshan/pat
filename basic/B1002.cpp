/*
// C++版
#include <iostream>
#include <string>
using namespace std;

int main() {
	string digits[10] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi",
			"ba", "jiu" };
	string n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n.size(); i++) {
		sum += n[i] - '0';
	}
	string str = to_string(sum);
	for (int i = 0; i < str.size(); i++) {
		if (i > 0) {
			cout << " ";
		}
		cout << digits[str[i] - '0'];
	}
	cout << endl;
	return 0;
}*/

// C语言版
#include <cstdio>
#include <cstring>

int main() {
	char digits[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi",
			"ba", "jiu" };
	char n[102];
	scanf("%s", n);
	int sum = 0;
	for (int i = 0; i < strlen(n); i++) {
		sum += n[i] - '0';
	}
	char str[5];
	int index = 0;
	while (sum != 0) {
		str[index++] = sum % 10 + '0';
		sum /= 10;
	}
	for (int i = index - 1; i >= 0; i--) {
		if (i < index - 1) {
			printf(" ");
		}
		printf("%s", digits[str[i] - '0']);
	}
	printf("\n");
	return 0;
}
