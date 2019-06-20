#include <cstdio>

const int Galleon = 17 * 29;
const int Sickle = 29;

int main() {
	int g1, s1, k1, g2, s2, k2;
	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
	//将输入的钱均转换为以纳特(Knut)为单位
	int price = g1 * Galleon + s1 * Sickle + k1;
	int money = g2 * Galleon + s2 * Sickle + k2;
	int change = money - price;
	if (change < 0) {
		printf("-");
		change = -change;
	}
	printf("%d.%d.%d\n", change / Galleon, change % Galleon / Sickle,
			change % Sickle);
	return 0;
}
