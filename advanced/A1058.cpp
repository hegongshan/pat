#include <cstdio>

int main() {
	int g1, s1, k1, g2, s2, k2, g, s, k;
	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
	g = s = k = 0;
	k += k1 + k2;
	if (k >= 29) {
		k -= 29;
		s++;
	}
	s += s1 + s2;
	if (s >= 17) {
		s -= 17;
		g++;
	}
	g += g1 + g2;
	printf("%d.%d.%d\n", g, s, k);
	return 0;
}
