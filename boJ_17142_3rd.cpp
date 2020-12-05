#include<vector>
#include<iostream>
#include<string.h>
#include<queue>
#include<climits>
using namespace std;

int N = 0;
int M = 0;
int pan[50][50] = { 0, };
vector<pair<int, int>> virus;
vector<int> selected;
int ans = INT_MAX;

int rdir[4] = { -1, 1, 0, 0, };
int cdir[4] = { 0, 0, -1, 1 };

bool isCompleted(int const p[][50]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (p[i][j] == 0) return false;
		}
	}
	return true;
}

bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

void spread() {

	int newPan[50][50];
	memcpy(newPan, pan, sizeof(newPan));
	int visit[50][50] = { 0, };
	queue<pair<int, int>> Q;
	queue<int> Qdist;

	for (auto n : selected) {
		int r = virus[n].first;
		int c = virus[n].second;
		Q.push(make_pair(r, c));
		newPan[r][c] = 3;
		Qdist.push(0);
		visit[r][c] = 1;
	}
	int current = 0;
	int cnt = 0;
	int flag = 0;

	while (!Q.empty()) {
		pair<int, int> p = Q.front(); Q.pop();
		int dist = Qdist.front(); Qdist.pop();

		int r = p.first;
		int c = p.second;

		for (int k = 0; k < 4; k++) {  //4방향
			int rnext = r + rdir[k];
			int cnext = c + cdir[k];

			if (isValid(rnext, cnext)) {
				if (newPan[rnext][cnext] != 1 && visit[rnext][cnext] == 0) { // 0 or 2 면 q에 넣음
					if (newPan[rnext][cnext] == 0) {
						current = dist + 1;
					}
					newPan[rnext][cnext] = 3;
					visit[rnext][cnext] = 1;
					Q.push(make_pair(rnext, cnext));
					Qdist.push(dist + 1);
				}
			}
		}
		
	}
	if (isCompleted(newPan)) {
		ans = min(ans, current);
	}
}

void dfs(int n) {

	if (selected.size() == M) {
		spread();
	}

	if (M - selected.size() > virus.size() - n) {
		return;
	}
	if (n == virus.size()) { // 더 이상 고를 거 없음
		return;
	}

	selected.push_back(n);
	dfs(n + 1);
	selected.pop_back();
	dfs(n + 1);
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> pan[i][j];
			if (pan[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}

	dfs(0);
	if (ans == INT_MAX) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}

