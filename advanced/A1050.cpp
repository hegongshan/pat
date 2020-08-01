#include <cstdio>

int main() {
	// 'z' = 122
	int hash[123] = { 0 };
	char temp;
	char s1[10001];

	int index = 0;
	// 输入s1,且s1中每个字符在hash值均设置为1
	while ((temp = getchar()) != '\n') {
		s1[index++] = temp;
		hash[(int) temp] = 1;
	}
	s1[index] = '\0';

	// 凡是s2中出现的字符，其hash值均重置为0
	while ((temp = getchar()) != '\n') {
		hash[(int) temp] = 0;
	}

	for (int i = 0; i < index; i++) {
		if (hash[(int) s1[i]] == 1) {
			printf("%c", s1[i]);
		}
	}
	printf("\n");
	return 0;
}
