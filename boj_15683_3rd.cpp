#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> pan;
int N, M = 0;
typedef struct _CAM {
	int num = 0;
	pair<int, int> pos;
} camera;
vector<camera> cams;
int ans = INT_MAX;
vector<vector<int>> arrows = { { 0, 1, 0, 0},
						{ 0, 1, 0, 1},
						{ 1, 1, 0, 0},
						{ 1, 1, 1, 0},
						{ 1, 1, 1, 1} };
int rdir[4] = { -1, 0, 1, 0 };
int cdir[4] = { 0, 1, 0, -1 };
bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < M;
}
void countDP(vector<vector<int>> const& p) {
	int cnt = 0;
	for (auto row : p) {
		cnt += count(row.begin(), row.end(), 0);
	}
	ans = min(ans, cnt);
}

void secure(vector<vector<int>>& p, int num, pair<int, int> pos, vector<int> arrow) {
	int r = pos.first;
	int c = pos.second;

	for (int j = 0; j < 4; j++) {
		if (arrow[j] == 1) {
			int rnext = r + rdir[j];
			int cnext = c + cdir[j];

			while (isValid(rnext, cnext) && p[rnext][cnext] != 6) {
				if (p[rnext][cnext] == 0) {
					p[rnext][cnext] = '#';
				}
				rnext += rdir[j];
				cnext += cdir[j];
			}
		}
	}
}

void dfs(int n, vector<vector<int>> const& p) {

	if (n == cams.size()) {
		countDP(p);
		return;
	}

	vector<int> arrow = arrows[cams[n].num];

	int rtCnt = 4;
	switch (cams[n].num) {
		case 1:
			rtCnt = 2;
			break;
		case 4:
			rtCnt = 1;
			break;
	}
	for (int i = 0; i < rtCnt; i++) {
		vector<vector<int>> pCpy(p);
		secure(pCpy, cams[n].num, cams[n].pos, arrow);
		dfs(n + 1, pCpy);
		rotate(arrow.rbegin(), arrow.rbegin() + 1, arrow.rend());
	}

}

int main() {
	cin >> N >> M;

	vector<int> row(M, 0);
	pan.assign(N, row);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pan[i][j];
			if (pan[i][j] != 0 && pan[i][j] != 6) {
				pan[i][j];
				camera c;
				c.num = pan[i][j] - 1;
				c.pos.first = i; c.pos.second = j;
				cams.push_back(c);
			}
		}
	}


	dfs(0, pan);
	cout << ans << '\n';
	return 0;
}

