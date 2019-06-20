#include <cstdio>

int main() {
	int k, exponent;
	int line = 2;
	const int MAX = 1001;
	double coefficient;
	double polynomials[MAX] = { 0 };
	while (line--) {
		scanf("%d", &k);
		for (int i = 0; i < k; i++) {
			scanf("%d %lf", &exponent, &coefficient);
			polynomials[exponent] += coefficient;
		}
	}
	int len = 0;
	for (int i = 0; i < MAX; i++) {
		if (polynomials[i] != 0) {
			len++;
		}
	}
	printf("%d", len);
	for (int i = MAX - 1; i >= 0; i--) {
		if (polynomials[i] != 0) {
			printf(" %d %.1f", i, polynomials[i]);
		}
	}
}
