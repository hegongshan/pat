#include <cstdio>

bool isNotBroken(int hash[], char c) {
	// 若上档键坏了，那么大写的英文字母不能输出。
	if ('A' <= c && c <= 'Z' && hash['+'] == 1) {
		return false;
	}
	if ('a' <= c && c <= 'z') {
		c -= 32;
	}
	return hash[c] == 0;
}

int main() {
	int hash[123] = { 0 };
	char temp;

	while ((temp = getchar()) != '\n') {
		hash[temp] = 1;
	}

	while ((temp = getchar()) != '\n') {
		if (isNotBroken(hash, temp)) {
			printf("%c", temp);
		}
	}
	printf("\n");
	return 0;
}
