#include <cstdio>

int main() {
	int n, m, temp = 0;
	scanf("%d %d", &n, &m);
	int arr[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < m; i++) {
		temp = arr[n - 1];
		for (int j = n - 2; j >= 0; j--) {
			arr[j + 1] = arr[j];
		}
		arr[0] = temp;
	}
	for (int i = 0; i < n; i++) {
		printf("%d", arr[i]);
		if (i != n - 1) {
			printf(" ");
		}
	}
	return 0;
}
