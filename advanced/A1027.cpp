#include <cstdio>

int main() {
	char radix[14] = "0123456789ABC";
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	printf("#");
	printf("%c%c", radix[r / 13], radix[r % 13]);
	printf("%c%c", radix[g / 13], radix[g % 13]);
	printf("%c%c\n", radix[b / 13], radix[b % 13]);
}
