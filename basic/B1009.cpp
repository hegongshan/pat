/*#include <cstdio>

int main() {
	char str[81][81];
	int index = 0;
	while (scanf("%s", str[index]) != EOF) {
		index++;
	}
	for (int i = index - 1; i >= 0; i--) {
		printf("%s", str[i]);
		if(i > 0) {
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}*/

#include <cstdio>

int main() {
	char str[81];
	char c;
	int index = 0;
	// PAT的编译器不支持gets()
	while((c = getchar()) != '\n' && c != EOF) {
		str[index++] = c;
	}
	int end = index;
	for (int i = index - 1; i >= 0; i--) {
		// 输出一个单词
		if (i == 0 || str[i] == ' ') {
			int start = i == 0 ? i : i + 1;
			for (int j = start; j < end; j++) {
				printf("%c", str[j]);
			}
			if (i > 0) {
				printf(" ");
			}
			end = i;
		}
	}
	printf("\n");
	return 0;
}


