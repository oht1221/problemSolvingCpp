#include<bits/stdc++.h>
using namespace std;
int N; int M; int D;
int archerRow = 0;
vector<vector<int>> mp;
vector<int> sel;
int ans = 0;
#define FOR(i, a, b) for(int i = a; i < b; i++) 
int comb = 0;
void check() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << mp[i][j] << " ";
		}
		cout << '\n';
	}

}
bool isDone() {
	bool ret = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mp[i][j] == 1) {
				ret = false;
				break;
			}
		}
	}

	return ret;
}

void forward() {
	vector<int> replacement(M);

	for (int i = 0; i < N; i++) {
		vector<int> temp = mp[i];
		mp[i] = replacement;
		replacement = temp;
	}

}
int dis(int cArch, int r, int c) {
	return abs(archerRow - r) + abs(cArch - c);
}

int shoot() {
	vector<pair<int, int>> shots;

	for (int m = 0; m < M; m++) {
		if (sel[m] == 1) {
			int cArch = m;
			int minD = D;
			int row = -1; int col = M;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (mp[i][j] == 1) {
						int d = dis(cArch, i, j);

						if (d < minD) {
							minD = d;
							row = i;
							col = j;
						}
						else if (d == minD) {
							if (j < col) {
								row = i;
								col = j;
							}
						}
					}
				}
			}
			if(col != M) shots.push_back(make_pair(row, col));
		}
	}
	int cnt = 0;

	for (auto const x : shots) {
		if (mp[x.first][x.second] == 1) {
			mp[x.first][x.second] = 0;
			cnt++;
		}
	}

	return cnt;
}

void dfs(int stage, int idx) {
	if (M - idx < 3 - stage) return;
	
	if (stage == 3) {
		vector<vector<int>> temp(mp);
		int cnt = 0;
		while (!isDone()) {
			cnt+= shoot();
			forward();
		}
		ans = max(cnt, ans);
		mp = temp;
		return;
	}

	sel[idx] = 1;
	dfs(stage + 1, idx + 1);
	sel[idx] = 0;
	dfs(stage, idx + 1);
}
int main() {
	cin >> N >> M >> D;
	archerRow = N;
	
	vector<int> row(M);
	sel.assign(M, 0);

	mp.assign(N, row);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mp[i][j];
		}
	}

	dfs(0, 0);
	cout << ans << endl;
	return 0;
}
