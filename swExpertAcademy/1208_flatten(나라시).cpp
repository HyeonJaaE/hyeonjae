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

	int T = 10;
	int Tcnt = 1;
	int N; //덤프 가능 횟수

	while (T--) {

		int arr[100];

		int max = -1;
		int min = -1;
		int ans = 0;

		cin >> N;

		for (int i = 0; i < 100; i++) {
			cin >> arr[i];

			if (i == 0) {
				max = i;
				min = i;
			}

			if (arr[i] >= arr[max]) max = i;
			if (arr[i] <= arr[min]) min = i;
		}

		//N 번 평탄화
		for (int i = 0; i < N; i++) {

			ans = arr[max] - arr[min];
			if (ans == 0 || ans == 1 ) break;

			// 평탄화 수행
			arr[max] = arr[max] - 1;
			arr[min] = arr[min] + 1;

			for (int j = 0; j < 100; j++) {
				if (arr[j] >= arr[max]) max = j;
				if (arr[j] <= arr[min]) min = j;
			}
		}

		ans = arr[max] - arr[min];
		cout << "#" << Tcnt++ << " " << ans << endl;
	}

	return 0;
}
