#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct Node {
	int rank, id;
	int totalScore;
	// solve表示获得满分的题目个数
	int solve;
	// 数组的值，-2表示未提交，-1表示编译错误
	int s[5];
	// 是否参加排名
	bool status;
} User;

bool cmp(User a, User b) {
	if (a.totalScore != b.totalScore) {
		return a.totalScore > b.totalScore;
	}
	if (a.solve != b.solve) {
		return a.solve > b.solve;
	}
	return a.id < b.id;
}

int main() {
	int k, n, m;
	scanf("%d %d %d", &n, &k, &m);
	int p[k];
	for (int i = 0; i < k; i++) {
		scanf("%d", &p[i]);
	}

	User user[n];
	// 初始化
	for (int i = 0; i < n; i++) {
		user[i].id = i;
		user[i].rank = 0;
		user[i].totalScore = 0;
		user[i].solve = 0;
		for (int j = 0; j < k; j++) {
			// -2表示未提交
			user[i].s[j] = -2;
		}
		user[i].status = false;
	}

	int userId, problemId, score;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &userId, &problemId, &score);
		userId--;
		problemId--;

		user[userId].id = userId + 1;

		if (score > user[userId].s[problemId]) {
			// 当提交结果，编译通过时
			if (score >= 0) {
				// 计算用户的总分
				user[userId].totalScore += score;
				if (user[userId].s[problemId] > 0) {
					user[userId].totalScore -= user[userId].s[problemId];
				}
				// 至少有一次编译通过，则参加排名
				user[userId].status = true;
			}
			// 计算用户得满分的题目个数，条件score > user[userId].s[problemId]保证solve不会重复累加
			if (score == p[problemId]) {
				user[userId].solve++;
			}
			// 更新题目的最高得分
			user[userId].s[problemId] = score;
		}
	}

	// 排名
	sort(user, user + n, cmp);
	user[0].rank = 1;
	for (int i = 1; i < n; i++) {
		if (user[i].totalScore == user[i - 1].totalScore) {
			user[i].rank = user[i - 1].rank;
		} else {
			user[i].rank = i + 1;
		}
	}

	for (int i = 0; i < n && user[i].status; i++) {

		printf("%d %05d %d", user[i].rank, user[i].id, user[i].totalScore);
		for (int j = 0; j < k; j++) {
			// 该题未提交
			if (user[i].s[j] == -2) {
				printf(" -");
			} else if (user[i].s[j] == -1) { // 提交过，但编译错误
				printf(" 0");
			} else {
				printf(" %d", user[i].s[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
