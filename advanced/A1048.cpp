#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int hash[501] = { 0 };
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		hash[arr[i]]++;
	}

	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (m - arr[i] >= 0 && m - arr[i] <= 500 && hash[m - arr[i]] > 0) {
			if (2 * arr[i] == m && hash[arr[i]] < 2) {
				continue;
			}
			printf("%d %d\n", arr[i], m - arr[i]);
			return 0;
		}
	}
	printf("No Solution\n");
	return 0;
}
