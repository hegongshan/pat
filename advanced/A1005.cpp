#include <iostream>
#include <string>
using namespace std;

int main() {
	string n;
	cin >> n;
	int sum = 0;
	string digits[10] = { "zero", "one", "two", "three", "four", "five", "six",
			"seven", "eight", "nine" };
	for (int i = 0; i < n.size(); i++) {
		sum += (n[i] - '0');
	}
	string result = to_string(sum);
	for (int i = 0; i < result.size(); i++) {
		if (i != 0) {
			cout << " ";
		}
		cout << digits[result[i] - '0'];
	}
	cout << endl;
	return 0;
}

/*#include <cstdio>
#include <cstring>

int main() {
	char n[102];
	scanf("%s", n);
	int sum = 0;
	char digits[10][6] = { "zero", "one", "two", "three", "four", "five", "six",
			"seven", "eight", "nine" };
	for (int i = 0; i < strlen(n); i++) {
		sum += (n[i] - '0');
	}
	char result[102], index = 0;
	do {
		result[index++] = sum % 10 + '0';
		sum /= 10;
	} while (sum != 0);
	for (int i = index - 1; i >= 0; i--) {
		if (i != index - 1) {
			printf(" ");
		}
		printf("%s", digits[result[i] - '0']);
	}
	printf("\n");
	return 0;
}*/
