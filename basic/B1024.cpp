#include <iostream>
#include <string>
using namespace std;

int main() {
	string s, e, n, result;
	cin >> s;

	int index = s.find("E");
	// 数字部分
	n = s.substr(1, index - 1);
	// 指数部分
	e = s.substr(index + 2, s.size() - index - 2);
	// 若为负数
	if (s[0] == '-') {
		result = s[0];
	}
	int x = stoi(e);
	int dot = n.find(".");
	// 若指数为负
	if (s[index + 1] == '-') {
		result += "0.";

		for (int i = 0; i < x - 1; i++) {
			result += "0";
		}

		result += n.substr(0, dot) + n.substr(dot + 1, n.size() - dot - 1);
	} else {
		int count = n.size() - n.find(".") - 1;
		// 若指数大于小数位数
		if (count < x) {
			result += n.substr(0, dot) + n.substr(dot + 1, n.size() - dot - 1);

			for (int i = 0; i < x - count; i++) {
				result += "0";
			}
		} else {
			result += n.substr(0, dot) + n.substr(dot + 1, x);
			// 若指数小于小数位数
			if (x < count) {
				result += "." + n.substr(dot + x + 1, n.size() - dot - x - 1);
			}
		}
	}
	cout << result << endl;
	return 0;
}
