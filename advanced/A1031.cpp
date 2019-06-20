#include <cstdio>
#include <cstring>

int main() {
	char str[81];
	scanf("%s", str);
	int n = strlen(str);
	int n1, n2, n3;
	n1 = n3 = (n + 2) / 3;
	n2 = (n + 2) / 3 + (n + 2) % 3;
	for (int i = 0; i < n1 - 1; i++) {
		printf("%c", str[i]);
		for (int j = 0; j < n2 - 2; j++) {
			printf(" ");
		}
		printf("%c\n", str[n - i - 1]);
	}
	for (int i = 0; i < n2; i++) {
		printf("%c", str[n1 + i - 1]);
	}
	printf("\n");
	return 0;
}
