#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Record {
	char name[21];
	int month, day, hour, minute;
	// true表示on-line，false表示off-line
	bool status;
};

// 按照客户姓名的字母顺序升序排列，若为同一客户，则按照时间顺序升序排列
bool cmp(Record a, Record b) {
	int r = strcmp(a.name, b.name);
	if (r != 0) {
		return r < 0;
	}
	if (a.month != b.month) {
		return a.month < b.month;
	}
	if (a.day != b.day) {
		return a.day < b.day;
	}
	if (a.hour != b.hour) {
		return a.hour < b.hour;
	}
	return a.minute < b.minute;
}
// 计算通话的时长及费用
void get_result(struct Record records[], int on, int off, int toll[], int &time,
		int &money) {
	struct Record temp = records[on];
	while (temp.day < records[off].day || temp.hour < records[off].hour
			|| temp.minute < records[off].minute) {
		time++;
		money += toll[temp.hour];
		temp.minute++;
		if (temp.minute >= 60) {
			temp.minute = 0;
			temp.hour++;
		}
		if (temp.hour >= 24) {
			temp.hour = 0;
			temp.day++;
		}
	}
}

int main() {
	int toll[24];
	for (int i = 0; i < 24; i++) {
		scanf("%d", &toll[i]);
	}
	int n;
	scanf("%d", &n);
	struct Record records[n];
	char line[9];
	for (int i = 0; i < n; i++) {
		scanf("%s %d:%d:%d:%d %s", records[i].name, &records[i].month,
				&records[i].day, &records[i].hour, &records[i].minute, line);
		if (strcmp(line, "on-line") == 0) {
			records[i].status = true;
		} else {
			records[i].status = false;
		}
	}
	sort(records, records + n, cmp);
	// next表示下一个客户在records中的下标
	int on = 0, off, next;
	while (on < n) {
		// 若needPrint为0，且当前的状态为on-line，则令needPrint = 1；
		// 若needPrint为1，且当前的状态为off-line，则令needPrint = 2;
		int needPrint = 0;
		next = on;
		while (next < n && strcmp(records[next].name, records[on].name) == 0) {
			if (needPrint == 0 && records[next].status) {
				needPrint = 1;
			} else if (needPrint == 1 && !records[next].status) {
				needPrint = 2;
			}
			next++;
		}
		// 若不存在有效通话，则忽略
		if (needPrint < 2) {
			on = next;
			continue;
		}
		int totalMoney = 0;
		printf("%s %02d\n", records[on].name, records[on].month);
		while (on < next) {
			// 寻找有效通话
			while (on < next - 1
					&& !(records[on].status && !records[on + 1].status)) {
				on++;
			}
			off = on + 1;
			// 若已经没有 有效通话，则跳出循环
			if (off == next) {
				on = next;
				break;
			}
			int time = 0, money = 0;
			get_result(records, on, off, toll, time, money);
			totalMoney += money;
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
					records[on].day, records[on].hour, records[on].minute,
					records[off].day, records[off].hour, records[off].minute,
					time, money / 100.0);
			on = off + 1;
		}
		printf("Total amount: $%.2f\n", totalMoney / 100.0);
	}
	return 0;
}
