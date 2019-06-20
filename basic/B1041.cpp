#include <cstdio>

struct Student {
	long long permitNo;
	int examSeatNumber;
};

int main() {
	int n, m, testSeatNumber, examSeatNumber;
	long long permitNo;
	scanf("%d", &n);
	Student stus[n + 1];
	for (int i = 0; i < n; i++) {
		scanf("%lld %d %d", &permitNo, &testSeatNumber, &examSeatNumber);
		stus[testSeatNumber].permitNo = permitNo;
		stus[testSeatNumber].examSeatNumber = examSeatNumber;
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &testSeatNumber);
		printf("%lld %d\n", stus[testSeatNumber].permitNo,
				stus[testSeatNumber].examSeatNumber);
	}
	return 0;
}
