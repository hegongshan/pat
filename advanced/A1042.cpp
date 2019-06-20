#include <cstdio>

const int n = 54;

void sort(int arr[n][2]) {
	int temp = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j >= i + 1; j--) {
			if (arr[j][1] < arr[j - 1][1]) {
				temp = arr[j][1];
				arr[j][1] = arr[j - 1][1];
				arr[j - 1][1] = temp;

				temp = arr[j][0];
				arr[j][0] = arr[j - 1][0];
				arr[j - 1][0] = temp;
			}
		}
	}
}

int main() {
	int k;
	scanf("%d", &k);
	int arr[n][2] = { 0 };
	int numbers[n];
	for (int i = 0; i < n; i++) {
		arr[i][0] = i + 1;
		scanf("%d", &numbers[i]);
	}
	while (k--) {
		for (int i = 0; i < n; i++) {
			arr[i][1] = numbers[i];
		}
		sort(arr);
	}

	for (int i = 0; i < n; i++) {
		char c;
		if (arr[i][0] <= 13) {
			c = 'S';
		} else if (arr[i][0] <= 26) {
			c = 'H';
		} else if (arr[i][0] <= 39) {
			c = 'C';
		} else if (arr[i][0] <= 52) {
			c = 'D';
		} else {
			c = 'J';
		}
		int r = arr[i][0] % 13;
		int data = r == 0 ? 13 : r;
		printf("%c%d", c, data);
		if (i < n - 1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
	return 0;
}

/*
#include <cstdio>
#include <string>
using namespace std;

const int N = 54;

void copy(string arr1[N],string arr2[N]) {
	for(int i=0;i<N;i++) {
		arr1[i] = arr2[i];
	}
}

int main() {
	int k;
	scanf("%d",&k);
	string sArr[N] = {"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
			"H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
			"C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
			"D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
		"J1","J2"};
	int arr[N];
	for(int i=0;i<N;i++) {
		scanf("%d",&arr[i]);
	}
	string sArr2[N];
	while(k--) {
		copy(sArr2,sArr);
		for(int j=0;j<N;j++) {
			sArr[arr[j]-1] = sArr2[j];
		}
	}
	for(int i=0;i<N;i++) {
		printf("%s",sArr[i].c_str());
		if(i != N - 1) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
}
*/
