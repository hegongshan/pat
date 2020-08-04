#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int n;
	cin >> s >> n;

	while (--n) {
		string t;
		int count = 1;
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == s[i + 1]) {
				count++;
			} else {
				t += s[i] + to_string(count);
				count = 1;
			}
		}

		t += s[s.size() - 1] + to_string(count);

		s = t;
	}

	cout << s << endl;
	return 0;
}
