#include <cstdio>

int main() {
	char temp;
	// 'z' = 122
	int hash[123] = { 0 };
	while ((temp = getchar()) != '\n') {
		hash[temp]++;
	}
	// 是否缺少珠子
	bool absent = false;
	// 统计多出或者缺少的珠子个数
	int count = 0;
	while ((temp = getchar()) != '\n') {
		// 没有某颗珠子
		if (hash[temp] == 0) {
			// 统计缺少珠子的个数
			count++;
			absent = true;
		} else {
			hash[temp]--;
		}
	}
	if (absent) {
		printf("No ");
	} else {
		printf("Yes ");
		// 计算多余珠子的个数
		for (int i = 0; i < 123; i++) {
			count += hash[i];
		}
	}
	printf("%d\n", count);
	return 0;
}
