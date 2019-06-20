#include <cstdio>

int main() {
	int a, b, sum, index = 0;
	scanf("%d %d", &a, &b);
	sum = a + b;
	char s[30];
	if (sum < 0) {
		printf("-");
		sum = -sum;
	}
	int count = 0;
	do {
		count++;
		s[index++] = sum % 10 + '0';
		sum /= 10;
		if (count % 3 == 0 && sum != 0) {
			count = 0;
			s[index++] = ',';
		}
	} while (sum != 0);
	for (int i = index - 1; i >= 0; i--) {
		printf("%c", s[i]);
	}
	printf("\n");
	return 0;
}
