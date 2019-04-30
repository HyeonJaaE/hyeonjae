#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
int Tcnt = 0;
int arr[4][4];


void hashf(vector<int> v , vector<int> h[]) {
	int val = 0;
	int tmp = 0;
	for (int i = 0; i < 7; i++) {
		tmp += v[i];
		val = val * 10 + v[i];
	}
	for (int i = 0; i < h[tmp].size(); i++) {
		if (h[tmp][i] == val) return;
	}
	cnt++;
	h[tmp].push_back(val);
}

void search(int r, int c, vector<int> v, vector<int> h[]) {
	v.push_back(arr[r][c]);
	if (v.size() == 7) {
		hashf(v,h);
		return;
	}

	if (r + 1 < 4) search(r + 1, c, v, h);
	if (r - 1 > -1) search(r - 1, c ,v, h);
	if (c + 1 < 4) search(r, c + 1, v, h);
	if (c - 1 > -1) search(r, c - 1, v, h);

}


int main() {
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		Tcnt++;

		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				cin >> arr[r][c];
			}
		}
		vector<int> v;
		vector<int> h[70];

		for (int r = 0; r < 4; r++) {
			for (int c = 0; c < 4; c++) {
				search(r, c, v, h);
			}
		}

		cout << "#" << Tcnt << " " << cnt << endl;
		cnt = 0;

	}

	return 0;

}
