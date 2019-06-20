#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Testee {
	char registrationNumber[14];
	int finalRank;
	int locationNumber;
	int localRank;
	int score;
};

bool cmp(Testee a, Testee b) {
	if (a.score != b.score) {
		return a.score > b.score;
	}
	return strcmp(a.registrationNumber, b.registrationNumber) < 0;
}

int main() {
	int n, k, num = 0;
	scanf("%d", &n);
	// max(n) * max(k) = 100 * 300
	struct Testee testees[30000];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			Testee testee;
			scanf("%s %d", testee.registrationNumber, &testee.score);
			testee.locationNumber = i;
			testees[num++] = testee;
		}
		sort(testees + num - k, testees + num, cmp);
		for (int j = num - k; j < num; j++) {
			if (j == num - k) {
				testees[j].localRank = 1;
			} else {
				if (testees[j].score == testees[j - 1].score) {
					testees[j].localRank = testees[j - 1].localRank;
				} else {
					testees[j].localRank = j - (num - k) + 1;
				}
			}
		}
	}
	sort(testees, testees + num, cmp);
	printf("%d\n", num);
	for (int j = 0; j < num; j++) {
		if (j == 0) {
			testees[j].finalRank = 1;
		} else {
			if (testees[j].score == testees[j - 1].score) {
				testees[j].finalRank = testees[j - 1].finalRank;
			} else {
				testees[j].finalRank = j + 1;
			}
		}
		printf("%s %d %d %d\n", testees[j].registrationNumber,
				testees[j].finalRank, testees[j].locationNumber,
				testees[j].localRank);
	}
	return 0;
}
