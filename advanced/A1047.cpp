#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char name[40000][5];
vector<int> arr[2501];

// 按照姓名字母序排列
bool cmp(int a, int b) {
	return strcmp(name[a], name[b]) < 0;
}

int main() {
	int n, k, c;
	scanf("%d %d", &n, &k);

	int index;
	for (int i = 0; i < n; i++) {
		scanf("%s %d", name[i], &c);
		while (c--) {
			scanf("%d", &index);
			arr[index].push_back(i);
		}
	}

	for (int i = 1; i <= k; i++) {
		printf("%d %lu\n", i, arr[i].size());

		sort(arr[i].begin(), arr[i].end(), cmp);
		for (int j = 0; j < arr[i].size(); j++) {
			printf("%s\n", name[arr[i][j]]);
		}
	}

	return 0;
}
