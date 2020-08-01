#include <cstdio>
#include <set>
using namespace std;

int main() {
	int n, m, data;
	scanf("%d", &n);

	set<int> arr[n + 1];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		while (m--) {
			scanf("%d", &data);
			arr[i].insert(data);
		}
	}

	int k, x, y;
	scanf("%d", &k);
	while (k--) {
		scanf("%d %d", &x, &y);
		int nc = 0, nt = arr[y].size();
		for (set<int>::iterator iter = arr[x].begin(); iter != arr[x].end();
				iter++) {
			if (arr[y].count(*iter)) {
				nc++;
			} else {
				nt++;
			}
		}
		printf("%.1f%%\n", nc * 100.0 / nt);
	}
	return 0;
}
