#include <iostream>
#include <cstdio>
using namespace std;

bool isLegal(string x) {
	unsigned int i = 0;
	if (x[0] == '-' || x[0] == '+') {
		i++;
	}

	int pointIdx = -1;
	while (i < x.size()) {
		// 如果包含多个.
		if (x[i] == '.') {
			if (pointIdx > 0) {
				return false;
			}
			pointIdx = i;
		}
		// 如果包含非数字
		if (x[i] != '.' && (x[i] < '0' || x[i] > '9')) {
			return false;
		}
		i++;
	}
	// 如果精度超过2位
	if (pointIdx != -1 && x.size() - 1 - pointIdx > 2) {
		return false;
	}
	// [-1000,1000]
	double val = stod(x);
	return -1000 <= val && val <= 1000;
}

int main() {
	int n;
	cin >> n;

	double sum = 0.0;
	int legalCount = 0;
	while (n--) {
		string num;
		cin >> num;

		if (isLegal(num)) {
			legalCount++;
			sum += stod(num);
		} else {
			printf("ERROR: %s is not a legal number\n", num.c_str());
		}
	}

	if (legalCount == 0) {
		printf("The average of 0 numbers is Undefined\n");
	} else if (legalCount == 1) {
		printf("The average of 1 number is %.2f\n", sum);
	} else {
		printf("The average of %d numbers is %.2f\n", legalCount,
				sum / legalCount);
	}
	return 0;
}
