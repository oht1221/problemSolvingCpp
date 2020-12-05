#include<bits/stdc++.h>
using namespace std;
int N = 0;
int L = 0;
int mp[100][100] = { 0, };
int ans = 0;
bool valid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}
bool horiPath(int r) {
	int conseq = 1;
	for (int c = 0; c < N; c++) {
		if (valid(r, c + 1)) {
			if (mp[r][c + 1] - mp[r][c] == 0) {
				conseq++;
			}
			else if (mp[r][c + 1] - mp[r][c] == 1) {
				if (conseq >= L) {
					conseq = 1;
				}
				else return false;
			}
			else if (mp[r][c + 1] - mp[r][c] == -1) {
				int cnt = 0;
				for (int i = 1; c + i < N; i++) {
					if (valid(r, c + i) && mp[r][c + 1] == mp[r][c + i]) {
						cnt++;
					}
					else break;
				}
				if (cnt >= L) {
					c = c + L - 1;
					conseq = 0;
				}
				else return false; //내려가는길 못 만듦
			}
			else {
				return false; //차이가 2 이상
			}
		}
	}
	return true;
}

bool vertPath(int c) {
	int conseq = 1;
	for (int r = 0; r < N; r++) {
		if (valid(r + 1, c)) {
			if (mp[r + 1][c] - mp[r][c] == 0) {
				conseq++;
			}
			else if (mp[r + 1][c] - mp[r][c] == 1) {
				if (conseq >= L) {
					conseq = 1;
				}
				else return false;
			}
			else if (mp[r + 1][c] - mp[r][c] == -1) {
				int cnt = 0;
				for (int i = 1; r + i < N; i++) {
					if (valid(r + i, c) && mp[r + 1][c] == mp[r + i][c]) {
						cnt++;
					}
					else break;
				}
				if (cnt >= L) {
					r = r + L - 1;
					conseq = 0;
				}
				else return false; //내려가는길 못 만듦
			}
			else {
				return false; //차이가 2 이상
			}
		}
	}
	return true;
}
int main() {
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mp[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		if (horiPath(i)) ans++;
		if (vertPath(i)) ans++;
	}

	cout << ans << '\n';
	return 0;
}
