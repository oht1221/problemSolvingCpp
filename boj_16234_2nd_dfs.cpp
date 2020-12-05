#include<bits/stdc++.h>

using namespace std;

int N = 0;
int L, R = 0;
int mp[50][50] = { 0 , };
int rdir[4] = { 0, 0, -1, 1 };
int cdir[4] = { -1, 1, 0, 0 };

bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

int dfs(int r, int c, vector<pair<int, int>>& nation, int visit[][50]) {

	visit[r][c] = 1;
	nation.push_back(make_pair(r, c));

	int sum = mp[r][c];

	for (int i = 0; i < 4; i++) {
		int rnext = r + rdir[i];
		int cnext = c + cdir[i];
		if (isValid(rnext, cnext)) {
			if (visit[rnext][cnext] == 0) {
				int gab = abs(mp[r][c] - mp[rnext][cnext]);
				if (L <= gab && gab <= R) {
					sum +=  dfs(rnext, cnext, nation, visit);
				}
			}
		}
	}


	return sum;
}

int main() {
	cin >> N >> L >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mp[i][j];
		}
	}

	int ans = 0;
	while (1) {

		int visit[50][50] = { 0, };
		int flag = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {

				if (visit[i][j] == 1) continue;
				vector<pair<int, int>> nation;

				int sum = dfs(i, j, nation, visit);

				if (nation.size() > 1) {
					int avg = sum / nation.size();
					flag = 1;

					for (auto n : nation) { // ¿Ãµø
						mp[n.first][n.second] = avg;
					}
				}
				nation.clear();
			}
		}

		if (flag == 0) break;
		else ans++;
	}
	cout << ans << '\n';
	return 0;
}
