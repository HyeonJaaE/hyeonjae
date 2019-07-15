#include<iostream>
#include<string>
#include<cmath>

using namespace std;

#define Alice "Alice"
#define Bob "Bob"

int main() {
	ios_base::sync_with_stdio(false);

	int T;
	int Tcnt = 1;

	cin >> T;

	while (T--) {
		string ans = "";
		unsigned long long N, tmpN;
		int x = 0;
		int cnt = 0;
		int turn = 1;
		unsigned long long left, right, mid;
		unsigned long long aliceWin[2];
		unsigned long long bobWin[2];

		// 32 = 2^5

		cin >> N;
		tmpN = N;
		//cout << "N : " << N << endl;

		while (tmpN != 1) {
			cnt++;
			tmpN /= 2;
		}
		//cout << "cnt(depth) : " << cnt << endl;

		left = pow(2, cnt);
		right = pow(2, cnt + 1) - 1;
		//cout << left << " ~ " << right << endl << endl;

		//cnt = 2n-1 이면 Alice차례 , 2n 이면 Bob 차례
		//이기는 범위 설정
		if (cnt == 0) {
			cout << "#" << Tcnt++ << " " << Bob << endl;
			continue;
		}

		if (cnt % 2 == 1) {
			//alice 차례, left ~ N
			aliceWin[0] = left;
			aliceWin[1] = N;
			bobWin[0] = N + 1;
			bobWin[1] = right;
		}
		else {
			//bob 차례 , left ~ N -> bob 승, N+1~right -> Alice 승
			aliceWin[0] = N + 1;
			aliceWin[1] = right;
			bobWin[0] = left;
			bobWin[1] = N;
		}

		//alice 부터 작업 수행
		while (1) {
			mid = left + ((right - left) / 2);
			if (turn % 2 == 1) {
				//alice 차례
				//win의 범위가 전체범위의 1/2 초과할 때============
				if (aliceWin[0] == left && aliceWin[1] >= mid) {
					ans = Alice;
					break;
				}
				else if (aliceWin[1] == right && aliceWin[0] <= mid+1) {
					ans = Alice;
					break;
				}
				//=================================================
				else if( aliceWin[0] < mid && aliceWin[1] < mid ){
					right = mid;
					bobWin[1] = mid;
				}
				else if (aliceWin[0] > mid && aliceWin[1] > mid+1) {
					left = mid + 1;
					bobWin[0] = mid + 1;
				}
			}
			else {
				//bob 차례
				//win의 범위가 전체범위의 1/2 초과할 때============
				if (bobWin[0] == left && bobWin[1] >= mid) {
					ans = Bob;
					break;
				}
				else if (bobWin[1] == right && bobWin[0] <= mid + 1) {
					ans = Bob;
					break;
				}
				//=================================================
				else if (bobWin[0] < mid && bobWin[1] < mid) {
					right = mid;
					aliceWin[1] = mid;
				}
				else if (bobWin[0] > mid && bobWin[1] > mid+1) {
					left = mid + 1;
					aliceWin[0] = mid + 1;
				}
			}

			turn++;
		}

		// N = 5 , x = 1 -> 3 -> 6
		cout << "#" << Tcnt++ << " " << ans << endl;
	}

	return 0;
}
