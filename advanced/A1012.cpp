#include <cstdio>
#include <algorithm>
using namespace std;

struct Student {
	int id;
	int score[4];
	int rank[4];
	int best;
};

int flag = 0;
int exists[1000000];
char course[5] = { 'A', 'C', 'M', 'E' };

bool cmp(struct Student s1, struct Student s2) {
	return s1.score[flag] > s2.score[flag];
}

int main() {
	int n, m, id;
	scanf("%d %d", &n, &m);
	struct Student stu[n];
	// 输入
	for (int i = 0; i < n; i++) {
		scanf("%d", &stu[i].id);
		int sum = 0;
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &stu[i].score[j]);
			sum += stu[i].score[j];
		}
		// 平均成绩向上取整
		stu[i].score[0] = sum / 3.0 + 0.5;
	}

	for (flag = 0; flag < 4; flag++) {
		sort(stu, stu + n, cmp);
		stu[0].rank[flag] = 1;
		for (int j = 1; j < n; j++) {
			stu[j].rank[flag] = j + 1;
			// 若分数相同，则排名并列
			if (stu[j].score[flag] == stu[j - 1].score[flag]) {
				stu[j].rank[flag] = stu[j - 1].rank[flag];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		exists[stu[i].id] = i + 1;
		int rank = n + 1;
		for (int j = 0; j < 4; j++) {
			if (stu[i].rank[j] < rank) {
				rank = stu[i].rank[j];
				stu[i].best = j;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		scanf("%d", &id);
		int index = exists[id];
		if (index) {
			index -= 1;
			int best = stu[index].best;
			printf("%d %c\n", stu[index].rank[best], course[best]);
		} else {
			printf("N/A\n");
		}
	}
	return 0;
}
