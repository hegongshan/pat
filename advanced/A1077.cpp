#include <cstdio>
#include <cstring>

int main() {
	int n;
	scanf("%d", &n);
	getchar();
	char lines[n][257];
	int len = 0, maxLen = 257;
	for (int i = 0; i < n; i++) {
		char c;
		int j = 0;
		while ((c = getchar()) != '\n') {
			lines[i][j++] = c;
		}
		lines[i][j] = '\0';

		if (i > 0) {
			int preIndex = strlen(lines[i - 1]) - 1;
			int currentIndex = strlen(lines[i]) - 1;
			while (preIndex >= 0 && currentIndex >= 0
					&& lines[i][currentIndex--] == lines[i - 1][preIndex--]) {
				len++;
			}
			if (len < maxLen) {
				maxLen = len;
			}
			len = 0;
		}
	}
	if (maxLen == 0) {
		printf("nai");
	} else {
		int len0 = strlen(lines[0]);
		for (int i = len0 - maxLen; i < len0; i++) {
			printf("%c", lines[0][i]);
		}
	}
	printf("\n");
	return 0;
}
