#include <cstdio>
#include <cmath>

int main() {
	int n, a1, a2, a3, a5, a2Index, a4Count;
	a1 = a2 = a3 = a5 = a2Index = a4Count = 0;
	double a4 = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x % 10 == 0) {
			a1 += x;
		} else if (x % 5 == 1) {
			a2 += pow(-1, a2Index++) * x;
		} else if (x % 5 == 2) {
			a3 += 1;
		} else if (x % 5 == 3) {
			a4 += x;
			a4Count++;
		} else if (x % 5 == 4) {
			if (x > a5) {
				a5 = x;
			}
		}
	}
	if (!a1) {
		printf("N ");
	} else {
		printf("%d ", a1);
	}
	if (!a2Index) {
		printf("N ");
	} else {
		printf("%d ", a2);
	}
	if (!a3) {
		printf("N ");
	} else {
		printf("%d ", a3);
	}
	if (!a4Count) {
		printf("N ");
	} else {
		printf("%.1f ", a4 / a4Count);
	}
	if (!a5) {
		printf("N");
	} else {
		printf("%d", a5);
	}
	printf("\n");
	return 0;
}
