#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);

	int hash[10001] = { 0 };
	int data[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
		hash[data[i]]++;
	}

	// 是否存在赢家
	bool exists = false;
	for (int i = 0; i < n; i++) {
		if (hash[data[i]] == 1) {
			exists = true;
			printf("%d\n", data[i]);
			break;
		}
	}
	if (!exists) {
		printf("None\n");
	}
	return 0;
}
