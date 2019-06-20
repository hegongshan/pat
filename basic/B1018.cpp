#include <cstdio>

char getMaxGesture(int wins[]) {
	int max, maxIndex;
	max = maxIndex = 0;
	for (int i = 0; i < 3; i++) {
		if (wins[i] > max) {
			max = wins[i];
			maxIndex = i;
		}
	}
	if (maxIndex == 0) {
		return 'B';
	}
	if (maxIndex == 1) {
		return 'C';
	}
	return 'J';
}

int main() {
	int n, win, draw, defeat;
	win = draw = defeat = 0;
	int aCount[3] = { 0 }, bCount[3] = { 0 }; //0-C,1-J,2-B
	scanf("%d", &n);
	while (n--) {
		char a, b;
		scanf(" %c %c", &a, &b);
		if ((a == 'C' && b == 'J') || (a == 'J' && b == 'B')
				|| (a == 'B' && b == 'C')) {
			win++;
			if (a == 'B') {
				aCount[0]++;
			} else if (a == 'C') {
				aCount[1]++;
			} else {
				aCount[2]++;
			}
		} else if (a == b) {
			draw++;
		} else {
			defeat++;
			if (b == 'B') {
				bCount[0]++;
			} else if (b == 'C') {
				bCount[1]++;
			} else {
				bCount[2]++;
			}
		}
	}
	printf("%d %d %d\n", win, draw, defeat);
	printf("%d %d %d\n", defeat, draw, win);
	printf("%c %c\n", getMaxGesture(aCount), getMaxGesture(bCount));
	return 0;
}
