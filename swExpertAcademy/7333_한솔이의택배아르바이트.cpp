#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T, N;
	int C = 0;

	cin >> T;

	while (T--) {
		C++;
		int cnt = 0;
		cin >> N;
		int arr[100];

		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		sort(arr, arr+N);

		int idx = 0;
		for (int i = N - 1; i >= 0; i--) {
			int max = arr[i];

			int tmp = 50 / max;
			if (50 % max != 0) {
				tmp++;
			}

			if (i - idx + 1 >= tmp) {
				tmp--;
				while (tmp--) {
					idx++;
				}
				cnt++;
			}
			else {
				break;
			}
		}

		cout << "#" << C << " " << cnt << endl;
	}

}
