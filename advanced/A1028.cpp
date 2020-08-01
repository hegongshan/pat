#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student {
	char id[7];
	char name[9];
	int grade;
};
int c = 0;
bool cmp(struct Student a, struct Student b) {
	if (c == 1) {
		return strcmp(a.id, b.id) < 0;
	}
	if (c == 2) {
		int s = strcmp(a.name, b.name);
		if (s == 0) {
			return strcmp(a.id, b.id) < 0;
		}
		return s < 0;
	}
	if (a.grade == b.grade) {
		return strcmp(a.id, b.id) < 0;
	}
	return a.grade < b.grade;
}

int main() {
	int n;
	scanf("%d %d", &n, &c);
	struct Student stu[n];
	for (int i = 0; i < n; i++) {
		scanf("%s %s %d", stu[i].id, stu[i].name, &stu[i].grade);
	}
	sort(stu, stu + n, cmp);
	for (int i = 0; i < n; i++) {
		printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
	}
	return 0;
}
