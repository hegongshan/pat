#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int k, data;
	scanf("%d", &k);
	int hash[101] = { 0 };
	int arr[k];
	for (int i = 0; i < k; i++) {
		scanf("%d", &arr[i]);

		data = arr[i];
		while (data != 1) {
			if (data % 2 == 0) {
				data /= 2;
			} else {
				data = (3 * data + 1) / 2;
			}
			// 若不加该条件判断，建议将数组hash的长度设置为5000及以上
			// 97能覆盖的最大值为4616
			if (data <= 100) {
				hash[data]++;
			}
		}
	}

	sort(arr, arr + k);

	bool isFirst = true;
	for (int i = k - 1; i >= 0; i--) {
		if (hash[arr[i]] == 0) {
			if (!isFirst) {
				printf(" ");
			}
			isFirst = false;
			printf("%d", arr[i]);
		}
	}
	printf("\n");
	return 0;
}
