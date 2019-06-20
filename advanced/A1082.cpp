#include <cstdio>
#include <cstring>

int main() {

	char digits[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi",
			"ba", "jiu" };
	char unit[5][5] = { "Shi", "Bai", "Qian", "Wan", "Yi" };
	char data[11];
	scanf("%s", data);
	int len = strlen(data);
	int left = 0, right = len - 1;
	if (len != 0 && data[0] == '-') {
		printf("Fu");
		left = 1;
	}
	while (left + 4 <= right) {
		right -= 4;
	}

	while (left < len) {
		bool hasPrint = false;
		bool hasZero = false;
		// 处理某一组数字
		while (left <= right) {
			if (left > 0 && data[left] == '0') {
				hasZero = true;
			} else {
				if (hasZero == true) {
					printf(" ling");
					hasZero = false;
				}
				hasPrint = true;
				if (left > 0) {
					printf(" ");
				}
				printf("%s", digits[data[left] - '0']);
				if (right > left) {
					printf(" %s", unit[right - left - 1]);
				}
			}
			left++;
		}
		// 若本节已经输出过一个非零数字，则输出该组数字的单位
		if (hasPrint && right < len - 1) {
			printf(" %s", unit[(len - 1 - right) / 4 + 2]);
		}
		right += 4;
	}

	printf("\n");
	return 0;
}
