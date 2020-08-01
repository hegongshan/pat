#include <cstdio>

int main() {
	int n, k, score;
	// 下标表示分数，值表示该分数出现的次数
	int hash[101] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &score);
		hash[score]++;
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &score);
		if (i > 0) {
			printf(" ");
		}
		printf("%d", hash[score]);
	}
	printf("\n");
	return 0;
}
