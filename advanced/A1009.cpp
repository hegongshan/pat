#include <cstdio>

int main() {
	//指数不超过1000
	const int MAX = 1000;
	int k, exponent;
	double coefficient;
	double polynomial[MAX + 1] = { 0 }, polynomial2[2 * MAX + 1] = { 0 };
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %lf", &exponent, &coefficient);
		polynomial[exponent] = coefficient;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %lf", &exponent, &coefficient);
		for (int j = 0; j < MAX + 1; j++) {
			if (polynomial[j] != 0) {
				polynomial2[j + exponent] += polynomial[j] * coefficient;
			}
		}
	}
	int count = 0;
	for (int i = 0; i < 2 * MAX + 1; i++) {
		if (polynomial2[i] != 0) {
			count++;
		}
	}
	printf("%d", count);
	for (int i = 2 * MAX; i >= 0; i--) {
		if (polynomial2[i] != 0) {
			printf(" %d %.1f", i, polynomial2[i]);
		}
	}
	printf("\n");
	return 0;
}
