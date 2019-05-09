#include<iostream>
#include<string>

using namespace std;

int main() {
	int T;
	int Tc = 0;
	string A, B;

	cin >> T;

	while (T--) {
		Tc++;

		int cnt = 0;
		cin >> A >> B;

		int idx = -1;

		while ((idx = A.find(B)) != string::npos) {
			A.erase(idx, B.size());
			cnt++;
		}
		cnt += A.size();
		cout << "#" << Tc << " " << cnt << endl;
	}

}
