#include<iostream>
#include<string.h>

using namespace std;

int arr[100][100];

int search(int r, int c ) {

	while (1) {
		/*
		1000010001
		1111110001
		1000010001
		1000011111
		1000010002
		*/
		if (c - 1 >= 0 && arr[r][c - 1] == 1) {
			int tmp = c - 1;
			while (arr[r][tmp] == 1 && tmp >= 0) {
				tmp--;
			}
			c = tmp + 1;
			r++;
		}
		else if (c + 1 < 100 && arr[r][c + 1] == 1) {
			int tmp = c + 1;
			while (arr[r][tmp] == 1 && tmp < 100) {
				tmp++;
			}
			c = tmp - 1;
			r++;
		}
		else {
			r++;
		}


		if (arr[r][c] == 2) {
			return 1;
		}
		else if (r == 99) {
			return 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int T = 10;
	int Tcnt = 0;

	while (T--) {
		cin >> Tcnt;
		int ans = 0;
		memset(arr, 0, sizeof(arr));

		for (int r = 0; r < 100; r++) {
			for (int c = 0; c < 100; c++) {
				cin >> arr[r][c];
			}
		}

		for (int i = 0; i < 100; i++) {
			int tmp = 0;
			if(arr[0][i] == 1) tmp = search(0, i);
			if (tmp == 1) {
				ans = i;
				break;
			}
		}

		cout << "#" << Tcnt << " " << ans << endl;
	}

	return 0;
}
