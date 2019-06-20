#include <cstdio>
#include <cstring>

struct Person {
	char idNumber[16];
	char signIn[9];
	char signOut[9];
};

int main() {
	int m;
	scanf("%d", &m);
	Person persons[m];
	Person unlock, lock;
	strcpy(unlock.signIn, "23:59:59");
	strcpy(lock.signOut, "00:00:00");
	for (int i = 0; i < m; i++) {
		scanf("%s %s %s", persons[i].idNumber, persons[i].signIn,
				persons[i].signOut);
		if (strcmp(unlock.signIn, persons[i].signIn) > 0) {
			unlock = persons[i];
		}
		if (strcmp(lock.signOut, persons[i].signOut) < 0) {
			lock = persons[i];
		}
	}
	printf("%s %s\n", unlock.idNumber, lock.idNumber);
	return 0;
}
