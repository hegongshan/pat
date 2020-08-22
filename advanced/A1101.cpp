#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int leftMax[n];
	leftMax[0] = arr[0];
	for (int i = 1; i < n; i++) {
		leftMax[i] = max(arr[i], leftMax[i - 1]);
	}

	int rightMin[n];
	rightMin[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		rightMin[i] = min(arr[i], rightMin[i + 1]);
	}

	vector<int> pivotList;
	for (int i = 0; i < n; i++) {
		if (leftMax[i] <= arr[i] && arr[i] <= rightMin[i]) {
			pivotList.push_back(arr[i]);
		}
	}

	sort(pivotList.begin(), pivotList.end());

	printf("%lu\n", pivotList.size());
	for (unsigned int i = 0; i < pivotList.size(); i++) {
		if (i > 0) {
			putchar(' ');
		}
		printf("%d", pivotList[i]);
	}
	putchar('\n');

	return 0;
}
