#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct Node {
	float price;
	float distance;
} GasStation;

bool cmp(GasStation a, GasStation b) {
	return a.distance < b.distance;
}

int main() {
	int c, d, avg, n;
	scanf("%f %f %f %d", &c, &d, &avg, &n);

	GasStation gs[n];
	for (int i = 0; i < n; i++) {
		scanf("%f %d", &gs[i].price, &gs[i].distance);
	}

	sort(gs, gs + n, cmp);
	if(gs[0].distance != 0) {
		printf("The maximum travel distance = 0.00\n");
		continue;
	}

	int now = 0;
	float money = 0.0,nowTank;
	while (now < n) {

	}

	return 0;
}
