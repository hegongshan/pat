#include <cstdio>

int main() {
	int n, row;
	char c;
	scanf("%d %c", &n, &c);
	//若n为奇数，则n % 2 == 1,row = n / 2 + 1;
	//若n为偶数，则row = n / 2;
	row = n / 2 + n % 2;
	for (int i = 0; i < n; i++) {
		printf("%c", c);
	}
	printf("\n");

	for (int i = 1; i < row - 1; i++) {
		printf("%c", c);
		for (int j = 0; j < n - 2; j++) {
			printf(" ");
		}
		printf("%c\n", c);
	}

	for (int i = 0; i < n; i++) {
		printf("%c", c);
	}
	printf("\n");

	return 0;
}
