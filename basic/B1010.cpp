#include <cstdio>

int main() {
	int coefficient;
	int exponent;
	//判断是否已经有过输出
	bool flag = false;
	while (scanf("%d %d", &coefficient, &exponent) != EOF) {
		if (exponent != 0) {
			if (flag) {
				printf(" ");
			}
			printf("%d %d", coefficient * exponent, exponent - 1);
			flag = true;
		}
	}
	if(!flag) {
		printf("0 0");
	}
	return 0;
}
