#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	int scores[100001] = { 0 };
	int maxNo, maxScore, no, score;
	maxNo = maxScore = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &no, &score);
		scores[no] += score;
		if (scores[no] > maxScore) {
			maxNo = no;
			maxScore = scores[no];
		}
	}
	printf("%d %d\n", maxNo, maxScore);
	return 0;
}
