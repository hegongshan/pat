#include <cstdio>

struct Student {
	char name[11];
	char no[11];
	int grade;
};

int main() {
	int n;
	scanf("%d", &n);
	Student stu[n];
	Student maxGradeStu, minGradeStu;
	maxGradeStu.grade = 0;
	minGradeStu.grade = 101;
	for (int i = 0; i < n; i++) {
		scanf("%s %s %d", stu[i].name, stu[i].no, &stu[i].grade);
		if (maxGradeStu.grade < stu[i].grade) {
			maxGradeStu = stu[i];
		}
		if (minGradeStu.grade > stu[i].grade) {
			minGradeStu = stu[i];
		}
	}
	printf("%s %s\n", maxGradeStu.name, maxGradeStu.no);
	printf("%s %s\n", minGradeStu.name, minGradeStu.no);
	return 0;
}
