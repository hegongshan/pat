#include <cstdio>

int main() {
	int n, b, index = 0;
	scanf("%d %d", &n, &b);
	int data[33];
	do {
		data[index++] = n % b;
		n /= b;
	} while (n != 0);
	bool flag = true;
	for (int i = 0; i < index; i++) {
		if (data[i] != data[index - i - 1]) {
			flag = false;
			break;
		}
	}
	if (flag) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	for (int i = index - 1; i >= 0; i--) {
		printf("%d", data[i]);
		if (i > 0) {
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}
