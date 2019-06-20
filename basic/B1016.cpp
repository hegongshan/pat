#include <cstdio>
#include <cstring>

long long getP(char a[], int da) {
	long long pa = 0;
	long long carry = 1;
	for (int i = strlen(a) - 1; i >= 0; i--) {
		if ((a[i] - '0') == da) {
			pa += da * carry;
			carry *= 10;
		}
	}
	return pa;
}

int main() {
	char a[10], b[10];
	int da, db;
	scanf("%s %d %s %d", a, &da, b, &db);
	printf("%lld\n", getP(a, da) + getP(b, db));
	return 0;
}
