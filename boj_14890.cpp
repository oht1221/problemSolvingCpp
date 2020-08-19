#include<iostream>
#include<vector>
using namespace std;
int N = 0;
int L = 0;
int ans = 0;
vector<vector<int>> map;
int main() {
	cin >> N;
	cin >> L;
	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < N; j++) {
			int in = 0; cin >> in; 
			row.push_back(in);
		}
		map.push_back(row);
	}

	for (int i = 0; i < N; i++) {
		int pre = 0;
		int cur = 0;
		vector<int> ladder;
		for (int p = 0; p < N; p++) {
			ladder.push_back(0);
		}

		for (int j = 0; j < N; j++) {
			cur = map[i][j];
			
			if (j == 0) pre = cur;

			int dif = cur - pre;

			if (dif != 0) {
				int len = 0;
			
				if (dif == 1) {
					for (int k = j - 1; k >= 0; k--) {
						if (map[i][k] == pre && ladder[k] == 0) {
							len++; ladder[k] = 1;
							if (len == L) break;
						}
						else break;
					}
					if (len < L) break;
				}

				else if (dif == -1) {
					for (int k = j; k < N; k++) {
						if (map[i][k] == cur && ladder[k] == 0) {
							len++; ladder[k] = 1;
							if (len == L) break;
						}
						else break;
					}
					if (len < L) break;
				}

				else break;
			}
			pre = cur;
			if (j == N - 1) {
				ans++;
				cout << 1 << " " << i << endl;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		int pre = 0;
		int cur = 0;
		vector<int> ladder;
		for (int p = 0; p < N; p++) {
			ladder.push_back(0);
		}

		for (int j = 0; j < N; j++) {
			cur = map[j][i];

			if (j == 0) pre = cur;

			int dif = cur - pre;

			if (dif != 0) {
				int len = 0;

				if (dif == 1) {
					for (int k = j - 1; k >= 0; k--) {
						if (map[k][i] == pre && ladder[k] == 0) {
							len++; ladder[k] = 1;
							if (len == L) break;
						}
						else break;
					}
					if (len < L) break;
				}

				else if (dif == -1) {
					for (int k = j; k < N; k++) {
						if (map[k][i] == cur && ladder[k] == 0) {
							len++;
							ladder[k] = 1;
							if (len == L) break;
						}
						else break;
					}
					if (len < L) break;
				}

				else break;
			}
			pre = cur;
			if (j == N - 1) {
				ans++; cout << 2 << " " << i << endl;
			}
		}
	}

	cout << ans << endl;
	return 0;
}