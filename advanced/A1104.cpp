#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	long long n;
	scanf("%lld", &n);

	long double x, sum = 0.0;
	for (int i = 0; i < n; i++) {
		scanf("%Lf", &x);
		sum += (n - i) * (i + 1) * x;
	}

	/*
	 float %f
	 double 输入%lf，输出%f和%lf均可
	 long double %Lf
	 int %d
	 long %ld
	 longlong %lld
	 */
	printf("%.2Lf\n", sum);
	return 0;
}
