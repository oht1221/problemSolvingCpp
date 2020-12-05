#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> blanks;
vector<pair<int, int>> virus;
vector<vector<int>> pan;
vector<int> selected; 

int N, M;
int ans = 0;
int rdir[4] = { -1, 1, 0, 0 };
int cdir[4] = { 0, 0, -1, 1 };


int Count(vector<vector<int>> const& p) {
	int c = 0;
	for (int i = 0; i < N; i++) {
		c += count(p[i].begin(), p[i].end(), 0);
	}
	return c;
}

bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < M;
}
void spread(vector<vector<int>>& p) {

	vector<vector<int>> visit;
	vector<int> row(M, 0); visit.assign(N, row);

	for (auto const& v : virus) {
		int r = v.first;
		int c = v.second;

		queue<pair<int, int>> Q;
		Q.push(make_pair(r, c));
		visit[r][c] = 1;

		while (!Q.empty()) {
			pair<int, int>  pos = Q.front();
			Q.pop();

			for (int i = 0; i < 4; i++) {
				int rnext = pos.first + rdir[i];
				int cnext = pos.second + cdir[i];

				if (isValid(rnext, cnext)) {
					if (visit[rnext][cnext] == 0) {
						if (p[rnext][cnext] == 0) {
							Q.push(make_pair(rnext, cnext));
							visit[rnext][cnext] = 1;
							p[rnext][cnext] = 2;
						}
					}
				}
			}
		}

	}
}

void dfs(int n, int cnt) {
	if (cnt == 3) {
		vector<vector<int>> panCpy(pan);
		spread(panCpy);
		ans = max(ans, Count(panCpy));
		return;
	}

	if (n >= blanks.size()) {
		return;
	}

	if (3 - cnt > blanks.size() - n) {
		return;
	}


	int r = blanks[n].first;
	int c = blanks[n].second;

	pan[r][c] = 1; // 벽 설치 (선택)
	dfs(n + 1, cnt + 1);

	pan[r][c] = 0; //벽 제거 (안 선택)
	dfs(n + 1, cnt);
}
int main() {
	cin >> N >> M;
	vector<int> a(M, 0);
	pan.assign(N, a);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pan[i][j];
			if (pan[i][j] == 0) {
				blanks.push_back(make_pair(i, j));
			}
			else if (pan[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}

	dfs(0, 0);
	cout << ans << '\n';

	return 0;
}
