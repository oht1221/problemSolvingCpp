#include<bits/stdc++.h>
using namespace std;
int N, M;
int dir = 0;
int rdir[4] = { -1, 0, 1, 0 };
int cdir[4] = { 0, 1, 0, -1 };
int mp[50][50] = { 0, };
int visit[50][50] = { 0, };
int r, c = 0;
int stk = 0;
int ans = 0;
bool valid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < M;
}
int main() {
	cin >> N >> M;
	cin >> r >> c >> dir;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mp[i][j];
		}
	}

	while (1) {
		if (mp[r][c] == 0) mp[r][c] = 2; // 没家茄 备开篮 2
		int dnext = (dir - 1 + 4) % 4;
		int rnext = r + rdir[dnext];
		int cnext = c + cdir[dnext];

		if (valid(rnext, cnext)) {
			if (mp[rnext][cnext] == 0) {
				dir = dnext;
				r = rnext;
				c = cnext;
				stk = 0;
				continue;
			}
		}

		if (!valid(rnext, cnext) || mp[rnext][cnext] != 0) {
			if (stk != 4) {
				dir = dnext;
				stk++;
				continue;
			}
			else if (stk == 4) {
				int dtemp = ((dir - 2 + 4) % 4);
				rnext = r + rdir[dtemp];
				cnext = c + cdir[dtemp];
				if (!valid(rnext, cnext) || mp[rnext][cnext] == 1) break;
				else {
					stk = 0;
					r = rnext;
					c = cnext;
					continue;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(mp[i][j] == 2)ans++;
		}
	}

	cout << ans << '\n';

	return 0;
}
