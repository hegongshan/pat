#include <cstdio>
#include <cstring>

bool is_lower(char c) {
	return 'a' <= c && c <= 'z';
}

void getline(char s[]) {
	char temp;
	int index = 0;
	while ((temp = getchar()) != '\n') {
		s[index++] = temp;
	}
	s[index] = '\0';
}

int main() {
	char s1[81], s2[81];
	getline(s1);
	// 'z'=122
	int hash[123] = { 0 };
	int len1 = strlen(s1);
	for (int i = 0; i < len1; i++) {
		if (is_lower(s1[i])) {
			hash[s1[i] - 32]++;
		} else {
			hash[s1[i]]++;
		}
	}
	getline(s2);
	for (int i = 0; i < strlen(s2); i++) {
		if (is_lower(s2[i])) {
			hash[s2[i] - 32]--;
		} else {
			hash[s2[i]]--;
		}
	}
	char c;
	for (int i = 0; i < len1; i++) {
		if (is_lower(s1[i])) {
			c = s1[i] - 32;
		} else {
			c = s1[i];
		}
		if (hash[c] > 0) {
			printf("%c", c);
			// 相同字符只输出一次
			hash[c] = 0;
		}
	}
	printf("\n");
}
