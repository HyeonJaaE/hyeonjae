#include<iostream>

//시간 측정
//clock_t start, end;
//start = clock();
//end = clock();
//cout << "start : " << start << "end : " << end << endl;
//cout << "time : " << (double)(end - start) << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	//주사위 초기화
	/*
		  2
		4 1 3
		  5
		  6(윗면)
	*/

	int dice[7] = { 0, };
	int map[20][20];
	int R, C, r, c, K;

	cin >> R >> C >> r >> c >> K;

	//지도 생성
	for (int _r = 0; _r < R; _r++) {
		for (int _c = 0; _c < C; _c++) {
			cin >> map[_r][_c];
		}
	}

	while (K--) {

		int op, tmp, dtmp;
		cin >> op;

		/*for (int _r = 0; _r < R; _r++) {
			for (int _c = 0; _c < C; _c++) {
				cout << map[_r][_c] << " ";
			}
			cout << endl;
		}*/

		// 1동, 2서, 3북, 4남
		switch (op) {
			//이동한 칸(tmp)가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다.
			//0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다.
		case 1: //동
			if (c == (C - 1)) continue;
			c += 1;
			tmp = map[r][c];
			if (tmp == 0) {
				dtmp = dice[3];
				dice[3] = dice[6];
				dice[6] = dice[4];
				dice[4] = dice[1];
				dice[1] = dtmp;
				map[r][c] = dtmp;
				break;
			}
			else {
				dice[3] = dice[6];
				dice[6] = dice[4];
				dice[4] = dice[1];
				dice[1] = tmp;
				map[r][c] = 0;
				break;
			}
		case 2:
			if (c == 0) continue;
			c -= 1;
			tmp = map[r][c];
			if (tmp == 0) {
				dtmp = dice[3];
				dice[3] = dice[1];
				dice[1] = dice[4];
				dice[4] = dice[6];
				dice[6] = dtmp;
				map[r][c] = dtmp;
				break;
			}
			else {
				dice[4] = dice[6];
				dice[6] = dice[3];
				dice[3] = dice[1];
				dice[1] = tmp;
				map[r][c] = 0;
				break;
			}
		case 3: //북
			if (r == 0) continue;
			r -= 1;
			tmp = map[r][c];
			if (tmp == 0) {
				dtmp = dice[2];
				dice[2] = dice[6];
				dice[6] = dice[5];
				dice[5] = dice[1];
				dice[1] = dtmp;
				map[r][c] = dtmp;
				break;
			}
			else {
				dice[2] = dice[6];
				dice[6] = dice[5];
				dice[5] = dice[1];
				dice[1] = tmp;
				map[r][c] = 0;
				break;
			}
		case 4:
			if (r == (R - 1)) continue;
			r += 1;
			tmp = map[r][c];
			if (tmp == 0) {
				dtmp = dice[5];
				dice[5] = dice[6];
				dice[6] = dice[2];
				dice[2] = dice[1];
				dice[1] = dtmp;
				map[r][c] = dtmp;
				break;
			}
			else {
				dice[5] = dice[6];
				dice[6] = dice[2];
				dice[2] = dice[1];
				dice[1] = tmp;
				map[r][c] = 0;
				break;
			}
		}

		//cout << "===================" << endl;
		//cout << "r : " << r << " c : " << c << endl;
		//cout << "tmp : " << tmp << endl;
		//cout << "  " << dice[2] << endl;
		//cout << dice[4] << " " << dice[1] << " " << dice[3] << endl;
		//cout << "  " << dice[5] << endl;
		//cout << "  " << dice[6] << endl;
		//cout << "===================" << endl;

		cout << dice[6] << endl;
	}




	return 0;
}
