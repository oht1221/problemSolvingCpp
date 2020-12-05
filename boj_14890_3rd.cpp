#include<bits/stdc++.h>
using namespace std;
int N = 0;
int L = 0;
vector<vector<int>> pan;
int ans = 0;
int main() {
	cin >> N >> L;
	vector<int> row(N, 0);
	pan.assign(N, row);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> pan[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		bool pass = true;
		int gauge = 1;

		for (int j = 0; j < N; j++) {
			if (j + 1 == N) break;

			int next = pan[i][j + 1];

			if (pan[i][j] == next) {
				gauge += 1;
			}
			else if(next - pan[i][j] == 1 && gauge >= L){
				gauge = 1;
			}
			else if (next - pan[i][j] == -1 && gauge >= 0) {
				gauge = 1 - L;
			}
			else {
				pass = false;
				break;
			}
		}
		if (pass) {
			if (gauge >= 0) {
				ans++;
			}
		}
	}
	for (int j = 0; j < N; j++) {
		bool pass = true;
		int gauge = 1;

		for (int i = 0; i < N; i++) {
			if (i + 1 == N) break;

			int next = pan[i + 1][j];

			if (pan[i][j] == next) {
				gauge += 1;
			}
			else if (next - pan[i][j] == 1 && gauge >= L) {
				gauge = 1;
			}
			else if (next - pan[i][j] == -1 && gauge >= 0) {
				gauge = 1 - L;
			}
			else {
				pass = false;
				break;
			}
		}
		if (pass) {
			if (gauge >= 0) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
