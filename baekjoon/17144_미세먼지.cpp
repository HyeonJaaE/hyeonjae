#include<iostream>
#include<string>
#include<time.h>
#include<vector>

//시간 측정
//clock_t start, end;
//start = clock();
//end = clock();
//cout << "start : " << start << "end : " << end << endl;
//cout << "time : " << (double)(end - start) << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int R, C, T;

	cin >> R >> C >> T;

	int arr[50][50];


	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> arr[r][c];
		}
	}

	/*cout << endl;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << _arr[r][c] << " ";
		}
		cout << endl;
	}*/

	int sum;

	while (T--) {
		int _arr[50][50] = { 0, };

		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (arr[r][c] != 0 && arr[r][c] != -1){
					int tmp = arr[r][c];

					if (r - 1 >= 0 && r - 1 < R) {
						if (arr[r - 1][c] != -1) {
							_arr[r - 1][c] += tmp / 5;
							arr[r][c] -= tmp / 5;
						}
					}
					if (r + 1 >= 0 && r + 1 < R) {
						if (arr[r + 1][c] != -1) {
							_arr[r + 1][c] += tmp / 5;
							arr[r][c] -= tmp / 5;
						}
					}
					if (c - 1 >= 0 && c - 1 < C) {
						if (arr[r][c-1] != -1) {
							_arr[r][c-1] += tmp / 5;
							arr[r][c] -= tmp / 5;
						}
					}
					if (c + 1 >= 0 && c + 1 < C) {
						if (arr[r][c+1] != -1) {
							_arr[r][c+1] += tmp / 5;
							arr[r][c] -= tmp / 5;
						}
					}
				}

			}
		}
		sum = 0;
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (arr[r][c] != -1) {
					arr[r][c] += _arr[r][c];
					sum += arr[r][c];
				}
			}
		}

		for (int i = 0; i < R; i++) {
			if (arr[i][0] == -1) {
				int air = i;
				int _air = i + 1;

				//좌측
				sum -= arr[air - 1][0];
				sum -= arr[_air + 1][0];
				for (int j = air - 1; j > 0; j--) {
					arr[j][0] = arr[j - 1][0];
				}
				for (int j = _air + 1; j < R - 1; j++) {
					arr[j][0] = arr[j + 1][0];
				}

				//상, 하단
				for (int j = 0; j < C; j++) {
					arr[0][j] = arr[0][j + 1];
				}
				for (int j = 0; j < C; j++) {
					arr[R - 1][j] = arr[R - 1][j + 1];
				}

				//우측
				for (int j = 0; j < air; j++) {
					arr[j][C - 1] = arr[j + 1][C - 1];
				}
				for (int j = R - 1; j > _air; j--) {
					arr[j][C - 1] = arr[j - 1][C - 1];
				}

				//중앙
				for (int j = C-1; j > 1; j--) {
					arr[air][j] = arr[air][j - 1];
				}
				arr[air][1] = 0;
				for (int j = C - 1; j > 1; j--) {
					arr[_air][j] = arr[_air][j - 1];
				}
				arr[_air][1] = 0;
				break;
			}
		}
	}

	cout << sum;
	return 0;
}
