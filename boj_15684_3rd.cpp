#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<vector<int>> hori;

int N, M, H;
vector<pair<int, int>> cand;

int ans = 4;

bool isValid(int r, int c) {
	return 0 <= r && r < H && 0 <= c && c < N - 1;
}

bool play() {
	bool ret = true;
	for (int i = 0; i < N; i++) {
		int a = i;
		for (int j = 0; j < H; j++) {
			if (isValid(j, a - 1) && hori[j][a - 1] == 1) {
				a = a - 1;
			}
			else if (isValid(j, a) && hori[j][a] == 1) {
				a = a + 1;
			}
		}
		if (a != i) {
			ret = false;
			break;
		}
	}

	return ret;
}

void dfs(int n, int cnt, int limit) {
	
	if (cnt >= ans) return;
	if (cnt == limit) {
		if (play()) {
			ans = cnt;
		}
		return;
	}

	if (n == cand.size()) {
		return;
	}

	pair<int, int> line = cand[n];
	hori[line.first][line.second] = 1;
	dfs(n + 1, cnt + 1, limit);


	hori[line.first][line.second] = 0;
	dfs(n + 1, cnt, limit);
}

int main() {
	cin >> N >> M >> H;

	vector<int> row(N - 1, 0);
	hori.assign(H, row);


	for (int i = 0; i < M; i++) {
		int a = 0; int b = 0;
		cin >> a >> b;
		hori[a - 1][b - 1] = 1;
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (hori[i][j] == 1 || (isValid(i, j - 1) && hori[i][j - 1] == 1) || (isValid(i, j + 1) && hori[i][j + 1] == 1)) {
				continue;
			}
			else {
				cand.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		if (i >= ans) break;
		dfs(0, 0, i);
	}

	if (ans > 3) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}
