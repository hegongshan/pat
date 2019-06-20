#include <cstdio>

struct Person {
	char name[6];
	int year;
	int month;
	int day;
};
//若p1比p2的年龄大，则返回1；若一样大，返回0；否则，返回-1；
int old(Person p1, Person p2) {
	if (p1.year < p2.year) {
		return 1;
	}
	if (p1.year == p2.year) {
		if (p1.month < p2.month) {
			return 1;
		}
		if (p1.month == p2.month) {
			if (p1.day < p2.day) {
				return 1;
			}
			if (p1.day == p2.day) {
				return 0;
			}
		}
	}
	return -1;
}

int main() {
	int n;
	int currentYear = 2014, currentMonth = 9, currentDay = 6, maxAge = 200;
	scanf("%d", &n);
	Person youngest, oldest, current, maxPerson;
	maxPerson.year = currentYear - maxAge;
	maxPerson.month = currentMonth;
	maxPerson.day = currentDay;
	current.year = currentYear;
	current.month = currentMonth;
	current.day = currentDay;
	oldest = current;
	youngest = maxPerson;
	Person person[n];
	int count = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s %d/%d/%d", person[i].name, &person[i].year, &person[i].month,
				&person[i].day);
		if (old(person[i], current) >= 0 && old(maxPerson, person[i]) >= 0) {
			if (old(person[i], oldest) == 1) {
				oldest = person[i];
			}
			if (old(youngest, person[i]) == 1) {
				youngest = person[i];
			}
			count++;
		}
	}
	printf("%d", count);
	if (count > 0) {
		printf(" %s %s", oldest.name, youngest.name);
	}
	printf("\n");
	return 0;
}
