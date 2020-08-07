#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	while (n--) {
		string z;
		cin >> z;

		int half = z.size() >> 1;
		int a = stoi(z.substr(0, half));
		int b = stoi(z.substr(half));
		int product = a * b;

		if (product != 0 && stoi(z) % product == 0) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
