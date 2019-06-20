#include <cstdio>

int main() {
	int a, b, d, sum;
	int data[32];
	scanf("%d %d %d", &a, &b, &d);
	sum = a + b;
	int i = 0;
	do {
		data[i++] = sum % d;
		sum /= d;
	} while (sum != 0);
	for (int j = i - 1; j >= 0; j--) {
		printf("%d", data[j]);
	}
	printf("\n");
	return 0;
}
