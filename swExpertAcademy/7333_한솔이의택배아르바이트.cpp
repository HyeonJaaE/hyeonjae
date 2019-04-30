#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T, N;
	vector<int> v;

	cin >> T;

	while (T--) {

		int cnt = 0;
		cin >> N;

		while (N--) {
			int t;
			cin >> t;
			v.push_back(t);
		}

		make_heap(v.begin(), v.end());
		sort_heap(v.begin(), v.end());

		while(v.size()){
			int max = v.back();

			int tmp = 50 / max;
			if (50 % max != 0) {
				tmp++;
			}
			//50 = 1, 51 = 0 + 1
			//49 = 1 + 1 , 25 = 2 + 0

			if (v.size() >= tmp) {
				tmp--;
				while (tmp--) {
					v.erase(v.begin());
				}
				cnt++;
				v.pop_back();
			}
		}

		cout << cnt << endl;
	}

}
