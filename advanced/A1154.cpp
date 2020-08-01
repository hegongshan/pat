#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
	int n, m, K;
	scanf("%d %d", &n, &m);

	vector<pair<int, int>> edges;
	for (int i = 0; i < m; i++) {
		pair<int, int> p;
		scanf("%d %d", &p.first, &p.second);
		edges.push_back(p);
	}

	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int color;
		unordered_map<int, int> map;
		unordered_set<int> colors;
		for (int j = 0; j < n; j++) {
			scanf("%d", &color);
			colors.insert(color);
			map[j] = color;
		}

		bool isKColoring = true;
		for (auto &x : edges) {
			if (map[x.first] == map[x.second]) {
				isKColoring = false;
				break;
			}
		}
		if (!isKColoring) {
			printf("No\n");
		} else {
			printf("%lu-coloring\n", colors.size());
		}
	}
	return 0;
}
