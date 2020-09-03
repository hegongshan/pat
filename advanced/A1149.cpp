#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	unordered_map<int, unordered_set<int>> incompatMap;

	// 保存不相容的物品对
	int id1, id2;
	for (int i = 0; i < n; i++) {
		cin >> id1 >> id2;
		incompatMap[id1].insert(id2);
		incompatMap[id2].insert(id1);
	}

	int k, good;
	for (int i = 0; i < m; i++) {
		cin >> k;

		unordered_set<int> goods;
		for (int j = 0; j < k; j++) {
			cin >> good;
			goods.insert(good);
		}

		bool isCompat = true;

		for (int good : goods) {
			if (incompatMap.count(good)) {
				for (int id : incompatMap[good]) {
					if (goods.count(id)) {
						isCompat = false;
						goto output;
					}
				}
			}
		}

		output: if (isCompat) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}

	return 0;
}
