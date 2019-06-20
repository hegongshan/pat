#include <cstdio>
#include <algorithm>
using namespace std;

struct Student {
	// 准考证号
	int permitNo;
	// 德分
	int personalityScore;
	// 才分
	int abilityScore;
	// 所属类别
	int level;
};

bool cmp(struct Student stu1, struct Student stu2) {
	if (stu1.level != stu2.level) {
		return stu1.level < stu2.level;
	}
	// 按总分排序
	if (stu1.abilityScore + stu1.personalityScore
			!= stu2.abilityScore + stu2.personalityScore) {
		return stu1.abilityScore + stu1.personalityScore
				> stu2.abilityScore + stu2.personalityScore;
	}
	// 若总分相同，则按德分降序排列
	if (stu1.personalityScore != stu2.personalityScore) {
		return stu1.personalityScore > stu2.personalityScore;
	}
	// 若德分并列，则按准考证号升序
	return stu1.permitNo < stu2.permitNo;
}

void print(struct Student stu[], int len) {
	for (int i = 0; i < len; i++) {
		printf("%d %d %d\n", stu[i].permitNo, stu[i].personalityScore,
				stu[i].abilityScore);
	}
}

int main() {
	int n, low, high, m = 0;
	scanf("%d %d %d", &n, &low, &high);

	struct Student stu[n];
	int permitNo, personalityScore, abilityScore;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &permitNo, &personalityScore, &abilityScore);
		if (personalityScore < low || abilityScore < low) {
			continue;
		}
		stu[m].permitNo = permitNo;
		stu[m].abilityScore = abilityScore;
		stu[m].personalityScore = personalityScore;
		// 才德全尽
		if (personalityScore >= high && abilityScore >= high) {
			stu[m].level = 1;
		} else if (personalityScore >= high) { // 德胜才
			stu[m].level = 2;
		} else if (abilityScore >= high) {
			stu[m].level = 4;
		} else {
			// “才德兼亡”但尚有“德胜才”
			if (personalityScore >= abilityScore) {
				stu[m].level = 3;
			} else {
				stu[m].level = 4;
			}
		}
		m++;
	}

	// 排序
	sort(stu, stu + m, cmp);

	// 输出
	printf("%d\n", m);
	print(stu, m);
	return 0;
}
