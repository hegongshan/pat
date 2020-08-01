/*#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	map<string, vector<int> > dict;
	int index = 0, ni;
	string name;
	while (k--) {
		cin >> index >> ni;
		while (ni--) {
			cin >> name;
			dict[name].push_back(index);
		}
	}
	while (n--) {
		cin >> name;
		sort(dict[name].begin(), dict[name].end());
		cout << name << ' ' << dict[name].size();
		for (int i = 0; i < dict[name].size(); i++) {
			cout << ' ' << dict[name][i];
		}
		cout << endl;
	}
	return 0;
}*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int getId(char name[]) {
	int id = 0;
	for (int i = 0; i < 3; i++) {
		id = id * 26 + (name[i] - 'A');
	}
	id = id * 10 + (name[3] - '0');
	return id;
}

vector<int> arr[26 * 26 * 26 * 10 + 10];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int index = 0, ni, id;
	char name[5];
	while (k--) {
		scanf("%d %d", &index, &ni);
		for (int i = 0; i < ni; i++) {
			scanf("%s", name);
			id = getId(name);
			arr[id].push_back(index);
		}
	}
	while (n--) {
		scanf("%s", name);
		id = getId(name);
		printf("%s %lu", name, arr[id].size());

		sort(arr[id].begin(), arr[id].end());
		for (int i = 0; i < arr[id].size(); i++) {
			printf(" %d", arr[id][i]);
		}
		printf("\n");
	}
	return 0;
}
