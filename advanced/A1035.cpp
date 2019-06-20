#include <cstdio>
#include <cstring>

struct Account {
	char username[11];
	char password[11];
};

int main() {
	int n;
	scanf("%d", &n);
	struct Account accounts[n];
	int len = 0;
	for (int i = 0; i < n; i++) {
		struct Account a;
		getchar();
		scanf("%s %s", a.username, a.password);
		bool isModified = false;
		for (int j = 0; j < strlen(a.password); j++) {
			switch(a.password[j]) {
				case 'l':
					a.password[j] = 'L';
					isModified = true;
					break;
				case '1':
					a.password[j] = '@';
					isModified = true;
					break;
				case '0':
					a.password[j] = '%';
					isModified = true;
					break;
				case 'O':
					a.password[j] = 'o';
					isModified = true;
					break;
			}
		}
		if (isModified) {
			accounts[len++] = a;
		}
	}
	if (len == 0) {
		if (n == 1) {
			printf("There is 1 account and no account is modified\n");
		} else {
			printf("There are %d accounts and no account is modified\n", n);
		}
	} else {
		printf("%d\n", len);
		for (int i = 0; i < len; i++) {
			struct Account a = accounts[i];
			printf("%s %s\n", a.username, a.password);
		}
	}

	return 0;
}

/*#include <iostream>
#include <string>
using namespace std;

struct Account {
	string username;
	string password;
};

int main() {
	int n;
	cin >> n;
	Account accounts[n];
	int len;
	for (int i = 0; i < n; i++) {
		struct Account a;
		getchar();
		cin >> a.username >> a.password;
		bool isModified = false;
		for (int j = 0; j < a.password.size(); j++) {
			if (a.password[j] == 'l') {
				a.password[j] = 'L';
				isModified = true;
			}
			if (a.password[j] == '1') {
				a.password[j] = '@';
				isModified = true;
			}
			if (a.password[j] == '0') {
				a.password[j] = '%';
				isModified = true;
			}
			if (a.password[j] == 'O') {
				a.password[j] = 'o';
				isModified = true;
			}
		}
		if (isModified) {
			accounts[len++] = a;
		}
	}
	if (len == 0) {
		if (n == 1) {
			cout << "There is 1 account and no account is modified" << endl;
		} else {
			cout << "There are " << n << " accounts and no account is modified"
					<< endl;
		}
	} else {
		cout << len << endl;
		for (int i = 0; i < len; i++) {
			Account a = accounts[i];
			cout << a.username << " " << a.password << endl;
		}
	}
	return 0;
}*/
