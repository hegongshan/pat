#include <climits>
#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

enum result {
	DISTANCE_NOT_EXISTS, NOT_CYCLE, SIMPLE_CYCLE, CYCLE
};

int adj[201][201] = { 0 };

result check(vector<int> path, int n, int &dist) {
	unordered_set<int> set;
	for (unsigned int i = 0; i < path.size() - 1; i++) {
		// 如果路径不存在
		if (adj[path[i]][path[i + 1]] == 0) {
			return DISTANCE_NOT_EXISTS;
		}
		set.insert(path[i]);
		dist += adj[path[i]][path[i + 1]];
	}
	// 如果首尾城市编号不相等，或者没有走完所有的城市
	if (path[0] != path[path.size() - 1] || set.size() != n) {
		return NOT_CYCLE;
	}
	if (set.size() + 1 != path.size()) {
		return CYCLE;
	}
	return SIMPLE_CYCLE;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	// 邻接矩阵
	int x, y, w;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &w);
		adj[x][y] = adj[y][x] = w;
	}

	int k, num, u, dist;
	int idx = 0, shortestDist = INT_MAX;
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		vector<int> path;

		scanf("%d", &num);
		while (num--) {
			scanf("%d", &u);
			path.push_back(u);
		}

		dist = 0;
		result res = check(path, n, dist);
		if (res == DISTANCE_NOT_EXISTS) {
			printf("Path %d: NA (Not a TS cycle)\n", i);
		} else if (res == NOT_CYCLE) {
			printf("Path %d: %d (Not a TS cycle)\n", i, dist);
		} else {
			if (res == CYCLE) {
				printf("Path %d: %d (TS cycle)\n", i, dist);
			} else {
				printf("Path %d: %d (TS simple cycle)\n", i, dist);
			}
			if (dist < shortestDist) {
				shortestDist = dist;
				idx = i;
			}
		}
	}

	printf("Shortest Dist(%d) = %d\n", idx, shortestDist);
	return 0;
}
