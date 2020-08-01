#include <cstdio>

int main() {
	int data[10];
	int count = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &data[i]);
		count += data[i];
	}

	for (int i = 0; i < count; i++) {
		int j = 0;
		if (i == 0) {
			j++;
		}
		while (data[j] == 0) {
			j++;
		}
		data[j] -= 1;
		printf("%d", j);
	}
	printf("\n");
}
