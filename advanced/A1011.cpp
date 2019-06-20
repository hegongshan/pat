#include <cstdio>

int main() {
	const int n = 3;
	char results[n + 1] = { "WTL" };
	double x;
	double rate = 0.65;
	int perBetMoney = 2;
	double product = 1.0;
	for (int i = 0; i < n; i++) {
		double maxValue = 0.0;
		int maxChar = 0;
		for (int j = 0; j < n; j++) {
			scanf("%lf", &x);
			if (x > maxValue) {
				maxValue = x;
				maxChar = j;
			}
		}
		product *= maxValue;
		printf("%c ", results[maxChar]);
	}
	printf("%.2f\n", (product * rate - 1) * perBetMoney);
	return 0;
}
