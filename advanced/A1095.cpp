#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct Node {
	char plate_number[8];
	int h, m, s;
	bool status;
} Car;

bool cmp(Car a, Car b) {
	int result = strcmp(a.plate_number, b.plate_number);
	if (result != 0) {
		return result < 0;
	}
	if (a.h != b.h) {
		return a.h < b.h;
	}
	if (a.m != b.m) {
		return a.m < b.m;
	}
	return a.s < b.s;
}

bool before(Car car,int h,int m,int s) {
	if(car.h < h) {
		return true;
	}
	if(car.h == h && car.m < m) {
		return true;
	}
	if(car.h == h && car.m == m && car.s < s) {
		return true;
	}
	return false;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	Car car[n];
	char status[4];
	for (int i = 0; i < n; i++) {
		scanf("%s %d:%d:%d %s", car[i].plate_number, &car[i].h, &car[i].m,
				&car[i].s, status);
		if (strcmp(status, "in")) {
			car[i].status = true;
		} else {
			car[i].status = false;
		}
	}

	sort(car, car + n, cmp);
	int next = 0,in = 0,out = 0;
	while(next < n) {

		while() {

		}
	}
	int h,m,s;
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d",&h,&m,&s);
		int total = 0;
		for(int ) {
			if(before()) {
				total++;
			}
		}
		printf("%d\n",total);
	}

	return 0;
}
