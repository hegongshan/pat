#include <cstdio>

int main() {
	int t;
	scanf("%d", &t);
	long long a, b, c;
	long long sum;
	for (int i = 0; i < t; i++) {
		scanf("%lld %lld %lld", &a, &b, &c);
		sum = a + b;
		bool flag = false;
		if (a > 0 && b > 0 && sum < 0) {
			flag = true;
		} else if (a < 0 && b < 0 && sum >= 0) {
			flag = false;
		} else if (sum > c) {
			flag = true;
		}
		if (flag) {
			printf("Case #%d: true\n", i + 1);
		} else {
			printf("Case #%d: false\n", i + 1);
		}
	}
	return 0;
}
