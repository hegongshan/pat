#include <cstdio>

int main() {
	int n, aCount, bCount;
	aCount = bCount = 0;
	scanf("%d", &n);
	while (n--) {
		int aSay, aGive, bSay, bGive;
		scanf("%d %d %d %d", &aSay, &aGive, &bSay, &bGive);
		//1.同赢或同输
		if ((aGive == aSay + bSay && bGive == aSay + bSay)
				|| (aGive != aSay + bSay && bGive != aSay + bSay)) {
			continue;
		}
		//2.甲赢
		if (aGive == aSay + bSay) {
			bCount++;
		} else if (bGive == aSay + bSay) {
			//3.乙赢
			aCount++;
		}
	}
	printf("%d %d\n", aCount, bCount);
	return 0;
}
