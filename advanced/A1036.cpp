#include <cstdio>

struct Person {
	char name[11];
	char gender;
	char id[11];
	int grade;
};

int main() {
	int n;
	scanf("%d", &n);
	//boy表示分数最低的男学生、girl表示分数最高的女学生
	Person boy, girl, person;
	boy.grade = 101;
	girl.grade = -1;
	for (int i = 0; i < n; i++) {
		scanf("%s %c %s %d", person.name, &person.gender, person.id,
				&person.grade);
		if (person.gender == 'M' && person.grade < boy.grade) {
			boy = person;
		}
		if (person.gender == 'F' && person.grade > girl.grade) {
			girl = person;
		}
	}
	bool isMissing = false;
	if (girl.grade == -1) {
		isMissing = true;
		printf("Absent\n");
	} else {
		printf("%s %s\n", girl.name, girl.id);
	}
	if (boy.grade == 101) {
		isMissing = true;
		printf("Absent\n");
	} else {
		printf("%s %s\n", boy.name, boy.id);
	}
	if (isMissing) {
		printf("NA\n");
	} else {
		printf("%d\n", girl.grade - boy.grade);
	}
	return 0;
}
