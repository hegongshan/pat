#include <cstdio>

char arr[12] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2', '\0' };
int weight[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };

bool isValid(char idcard[]) {
	int sum = 0;
	for (int i = 0; i < 17; i++) {
		int temp = idcard[i] - '0';
		// 若前17位中存在非数字，则该号码有问题
		if (temp < 0 || temp > 9) {
			return false;
		}
		sum += weight[i] * temp;
	}
	// 比较最后一位校验码是否一致
	sum %= 11;
	return idcard[17] == arr[sum];
}

int main() {
	int n;
	scanf("%d", &n);
	bool allPassed = true;
	while (n--) {
		char idcard[19];
		scanf("%s", idcard);
		if (!isValid(idcard)) {
			allPassed = false;
			printf("%s\n", idcard);
		}
	}
	if (allPassed) {
		printf("All passed\n");
	}
	return 0;
}
