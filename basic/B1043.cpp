#include <cstdio>

int main() {
	char temp;
	int hash[123] = { 0 };
	while ((temp = getchar()) != '\n') {
		hash[temp]++;
	}

	char arr[7] = { 'P', 'A', 'T', 'e', 's', 't' };
	// flag表示是否还有字符可以输出
	bool flag = true;
	while (flag) {

		for (int i = 0; i < 6; i++) {
			if (hash[arr[i]] != 0) {
				printf("%c", arr[i]);
				hash[arr[i]]--;
			}
		}
		// 判断是否所有的字符都已被输出
		flag = false;
		for (int i = 0; i < 6; i++) {
			if (hash[arr[i]] != 0) {
				flag = true;
			}
		}
	}
	printf("\n");
	return 0;
}
