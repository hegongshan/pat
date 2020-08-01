#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct People {
	char name[9];
	int age;
	int netWorth;
};

bool cmp(People a, People b) {
	if (a.netWorth != b.netWorth) {
		return a.netWorth > b.netWorth;
	}
	if (a.age != b.age) {
		return a.age < b.age;
	}
	return strcmp(a.name, b.name) < 0;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	People people[n];
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", people[i].name, &people[i].age, &people[i].netWorth);
	}
	int m, min, max;
	sort(people, people + n, cmp);
	for (int i = 0; i < k; i++) {
		scanf("%d %d %d", &m, &min, &max);
		printf("Case #%d:\n", i + 1);
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (min <= people[j].age && people[j].age <= max) {
				printf("%s %d %d\n", people[j].name, people[j].age,
						people[j].netWorth);
				count++;
				if (count >= m) {
					break;
				}
			}
		}

		if (count == 0) {
			printf("None\n");
		}
	}
	return 0;
}
