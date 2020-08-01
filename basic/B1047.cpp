#include <cstdio>

int main() {
	int n, teamNo, peopleNo, score;
	scanf("%d", &n);
	int hash[1001] = { 0 };
	for (int i = 0; i < n; i++) {
		scanf("%d-%d %d", &teamNo, &peopleNo, &score);
		hash[teamNo] += score;
	}
	int maxIndex = 0;
	for (int i = 0; i < 1001; i++) {
		if (hash[i] > hash[maxIndex]) {
			maxIndex = i;
		}
	}
	printf("%d %d\n", maxIndex, hash[maxIndex]);
	return 0;
}
