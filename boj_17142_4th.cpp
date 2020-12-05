#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string.h>
#include<climits>
#include<queue>
using namespace std;
int n, m = 0;
int ans = INT_MAX;
int pan[50][50] = { 0, };

vector<pair<int,int>> virus;
vector<int> selected;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool isValid(int r, int c) {
	return 0 <= r && r < n && 0 <= c && c < n;
}

bool isCompleted(int newPan[][50]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (newPan[i][j] == 0) return false;
		}
	}
	return true;
}
int spread(int pan[][50]) {
	int newPan[50][50];
	memcpy(newPan, pan, sizeof(newPan));
	for (int i = 0; i < m; i++) {
		int num = selected[i];
		pair<int, int> pos = virus[num];
		newPan[pos.first][pos.second] = 3; //최초 활성
	}

	queue<pair<int, int>> Q;
	queue<int> Qdist;
	int visit[50][50] = { 0 , };
	for (int i = 0; i < m; i++) {
		int num = selected[i];
		pair<int, int> pos = virus[num];
		Q.push(pos);
		Qdist.push(0);
		visit[pos.first][pos.second] = 1;
	}
	int current = -1;

	while (!Q.empty()) {
		pair<int, int> pos = Q.front(); Q.pop();
		int r = pos.first; int c = pos.second;
		int dist = Qdist.front(); Qdist.pop();

		if (newPan[r][c] == 0) {
			newPan[r][c] = 3;
		}

		if (current < dist) {
			if (newPan[r][c] != 2) {// 비활성 바이러스면 거리 갱신 안함
				current = dist;
			}
		}

		for (int i = 0; i < 4; i++) {
			int rnext = r + dx[i];
			int cnext = c + dy[i];

			if (isValid(rnext, cnext)) {
				if (visit[rnext][cnext] == 0 && newPan[rnext][cnext] != 1) { //벽 아니면
					visit[rnext][cnext] = 1;
					Q.push(make_pair(rnext, cnext));
					Qdist.push(dist + 1);
				}
			}
		}
	}
	if (isCompleted(newPan)) return current;
	else return -1;
}
void dfs(int num) {
	if (selected.size() == m) {
		int dist = spread(pan);
		if (dist != -1) {
			ans = min(dist, ans);
		}
		return;
	}

	else if (num == virus.size()) {
		return;
	}
	
	selected.push_back(num);
	dfs(num + 1);
	selected.pop_back();
	dfs(num + 1);
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
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

