#include <cstdio>

int main() {
	int data;
	scanf("%d", &data);
	int b = data / 100;
	int s = data % 100 / 10;
	int n = data % 10;
	for (int i = 0; i < b; i++) {
		printf("B");
	}
	for (int i = 0; i < s; i++) {
		printf("S");
	}
	for (int i = 1; i <= n; i++) {
		printf("%d", i);
	}
	printf("\n");
	return 0;
}
