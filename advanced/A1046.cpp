#include <cstdio>

int main() {
	int n, m;
	scanf("%d", &n);
	int distances[n+1];
	int sum = 0, temp;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &temp);
		//记录从第1个结点开始，沿顺时针方向到第i个结点的距离
		distances[i] = sum;
		sum += temp;
	}
	for(int i=0;i<n+1;i++) {
		printf("%d ",distances[i]);
	}
	printf("\n");
	int start, end;
	int shortestDistance;
	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &start, &end);
		if (start > end) {
			temp = start;
			start = end;
			end = temp;
		}
		shortestDistance = distances[end] - distances[start];
		// 若 shorestDistance > totalDistance - shorestDistance
		if (sum < 2 * shortestDistance) {
			shortestDistance = sum - shortestDistance;
		}
		printf("%d\n", shortestDistance);
	}
	return 0;
}
