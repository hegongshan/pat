#include <cstdio>
#include <cstring>

int main() {
	int count[10] = { 0 };
	char n[1001];
	scanf("%s", n);
	for (int i = 0; i < strlen(n); i++) {
		count[n[i] - '0'] += 1;
	}
	for (int i = 0; i < 10; i++) {
		if (count[i] != 0) {
			printf("%d:%d\n", i, count[i]);
		}
	}
	return 0;
}
