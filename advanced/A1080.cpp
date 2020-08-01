#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Node {
	int id, rank;
	// 成绩
	int gExam, gInterview, gFinal;
	// 报考院校
	int preferred[5];
} Applicant;

typedef struct Node2 {
	// 计划招生数
	int quota;
	// 上一次录取的学生下标
	int last;
	// 录取名单（学生的编号）
	vector<int> admission;
} School;

bool cmp(Applicant a, Applicant b) {
	if (a.gFinal != b.gFinal) {
		return a.gFinal > b.gFinal;
	}
	return a.gExam > b.gExam;
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	Applicant applicant[n];
	School schools[m];
	for (int i = 0; i < m; i++) {
		scanf("%d", &schools[i].quota);
		schools[i].last = -1;
	}

	for (int i = 0; i < n; i++) {
		applicant[i].id = i;
		scanf("%d %d", &applicant[i].gExam, &applicant[i].gInterview);
		applicant[i].gFinal = (applicant[i].gExam + applicant[i].gInterview)
				/ 2;
		for (int j = 0; j < k; j++) {
			scanf("%d", &applicant[i].preferred[j]);
		}
	}

	// 排名
	sort(applicant, applicant + n, cmp);
	applicant[0].rank = 1;
	for (int i = 1; i < n; i++) {
		if (applicant[i].gFinal == applicant[i - 1].gFinal
				&& applicant[i].gExam == applicant[i - 1].gExam) {
			applicant[i].rank = applicant[i - 1].rank;
		} else {
			applicant[i].rank = i + 1;
		}
	}
	// 录取过程
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int index = applicant[i].preferred[j];
			int last = schools[index].last;
			int size = schools[index].admission.size();

			// 若尚未招满，或者当前学生与上一个录取的学生排名相同
			if (schools[index].quota > size
					|| (last != -1 && applicant[last].rank == applicant[i].rank)) {

				schools[index].admission.push_back(applicant[i].id);
				schools[index].last = i;
				break;
			}
		}
	}
	// 输出录取结果
	for (int i = 0; i < m; i++) {
		int size = schools[i].admission.size();
		if (size > 0) {
			sort(schools[i].admission.begin(), schools[i].admission.end());
			for (int j = 0; j < size; j++) {
				if (j > 0) {
					printf(" ");
				}
				printf("%d", schools[i].admission[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
