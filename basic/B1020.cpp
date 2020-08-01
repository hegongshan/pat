#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct Node {
	double store;
	double sell;
	double price;
} MoonCake;

bool cmp(MoonCake a, MoonCake b) {
	return a.price > b.price;
}

int main() {
	int n, d;
	scanf("%d %d", &n, &d);

	MoonCake mc[n];
	for (int i = 0; i < n; i++) {
		scanf("%lf", &mc[i].store);
	}
	for (int i = 0; i < n; i++) {
		scanf("%lf", &mc[i].sell);
		mc[i].price = mc[i].sell / mc[i].store;
	}
	sort(mc, mc + n, cmp);

	double income = 0.0;
	for (int i = 0; i < n; i++) {
		// 若月饼库存量高于市场的最大需求量
		if (mc[i].store >= d) {
			income += d * mc[i].price;
			break;
		} else {
			// 当前月饼库存量低于市场的最大需求量
			d -= mc[i].store;
			income += mc[i].sell;
		}
	}
	printf("%.2f\n", income);
	return 0;
}
