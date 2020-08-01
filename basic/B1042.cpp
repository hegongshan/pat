#include <cstdio>

int main() {
	char temp;
	// 'z' = 122
	char hash[123] = { 0 };
	while ((temp = getchar()) != '\n') {
		if ('A' <= temp && temp <= 'Z') {
			hash[temp + 32]++;
		} else if ('a' <= temp && temp <= 'z') {
			hash[(int) temp]++;
		}
	}
	int count = 0;
	for (int i = 97; i < 123; i++) {
		if (hash[i] > count) {
			temp = i;
			count = hash[i];
		}
	}
	printf("%c %d\n", temp, count);
	return 0;
}
