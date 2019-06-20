#include <cstdio>

int main() {
	int n, x = 1;
	char c;
	scanf("%d %c", &n, &c);
	while ((x + 1) * (x + 1) / 2 - 1 <= n) {
		x += 2;
	}
	x -= 2;
	for (int i = 0; i < x / 2 + 1; i++) {
		for (int j = 0; j < i; j++) {
			printf(" ");
		}
		for (int j = 0; j < x - 2 * i; j++) {
			printf("%c", c);
		}
		printf("\n");
	}
	for (int i = 1; i < x / 2 + 1; i++) {
		for (int j = 0; j < (x - (2 * i + 1)) / 2; j++) {
			printf(" ");
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			printf("%c", c);
		}
		printf("\n");
	}
	printf("%d\n", n - ((x + 1) * (x + 1) / 2 - 1));
	return 0;
}
