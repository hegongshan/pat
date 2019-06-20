#include <cstdio>
#include <cstring>

int main() {
	char week[7][4] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	char str[4][61];
	for (int i = 0; i < 4; i++) {
		scanf("%s", str[i]);
	}
	int len0 = strlen(str[0]), len1 = strlen(str[1]);
	int len2 = strlen(str[2]), len3 = strlen(str[3]);
	int i = 0, j = 0;
	while (i < len0 && i < len1) {
		// 第一对相同的大写英文字母，取值范围为A-G
		if (str[0][i] == str[1][i] && 'A' <= str[0][i] && str[0][i] <= 'G') {
			printf("%s ", week[str[0][i] - 'A']);
			break;
		}
		i++;
	}
	i += 1;
	while (i < len0 && i < len1) {
		// 第二对相同的字符，取值范围为0-9及A-N
		if (str[0][i] == str[1][i]
				&& (('A' <= str[0][i] && str[0][i] <= 'N')
						|| ('0' <= str[0][i] && str[0][i] <= '9'))) {
			if ('A' <= str[0][i] && str[0][i] <= 'N') {
				printf("%d:", str[0][i] - 'A' + 10);
			} else {
				printf("%02d:", str[0][i] - '0');
			}
			break;
		}
		i++;
	}
	while (j < len2 && j < len3) {
		// 第一对相同的英文字母
		if (str[2][j] == str[3][j]
				&& (('A' <= str[2][j] && str[2][j] <= 'Z')
						|| ('a' <= str[2][j] && str[2][j] <= 'z'))) {
			printf("%02d\n", j);
			break;
		}
		j++;
	}
	return 0;
}
