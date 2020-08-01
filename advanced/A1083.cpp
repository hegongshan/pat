#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct Node {
	char name[11], id[11];
	int grade;
} Student;

bool cmp(Student a, Student b) {
	return a.grade > b.grade;
}

int main() {
	int n, low, high;

	scanf("%d", &n);
	Student stu[n];
	for (int i = 0; i < n; i++) {
		scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
	}
	scanf("%d %d", &low, &high);

	sort(stu, stu + n, cmp);

    // 用于表示是否存在满足条件的学生
	bool exist = false;
	for (int i = 0; i < n; i++) {
		if (low <= stu[i].grade && stu[i].grade <= high) {
			printf("%s %s\n", stu[i].name, stu[i].id);
			exist = true;
		}
	}
	if (!exist) {
		printf("NONE\n");
	}
	return 0;
}
