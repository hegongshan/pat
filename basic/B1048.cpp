#include <cstdio>
#include <cstring>

void reverse(char s[]) {
	int len = strlen(s);
	int temp = 0;
	for (int i = 0; i < len / 2; i++) {
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}

int main() {
	char a[101], b[101], c[101];
	scanf("%s %s", a, b);
	reverse(a);
	reverse(b);
	int lenB = strlen(b);
	int lenA = strlen(a);
	int len = lenA > lenB ? lenA : lenB;

	for (int i = 1; i <= len; i++) {
		int numA = i <= lenA ? a[i - 1] - '0' : 0;
		int numB = i <= lenB ? b[i - 1] - '0' : 0;
		// 若为奇数
		if (i % 2 != 0) {
			int result = (numA + numB) % 13;
			if (result < 10) {
				c[i - 1] = result + '0';
			} else {
				if (result == 10) {
					c[i - 1] = 'J';
				} else if (result == 11) {
					c[i - 1] = 'Q';
				} else {
					c[i - 1] = 'K';
				}
			}
		} else {
			int result = numB - numA;
			if (result < 0) {
				c[i - 1] = result + 10 + '0';
			} else {
				c[i - 1] = result + '0';
			}
		}
	}
	for (int i = strlen(c) - 1; i >= 0; i--) {
		printf("%c", c[i]);
	}
	printf("\n");
	return 0;
}
