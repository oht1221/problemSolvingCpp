#include<bits/stdc++.h>
using namespace std;
int ans = 0;
int mp[8][8];
int N, M;
int virus = 0;
vector<pair<int, int>> selected;
vector<pair<int, int>> viruses;

int rdir[4] = { -1, 1, 0, 0 };
int cdir[4] = { 0, 0, -1, 1 };

int valid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < M;
}

int spread(int mpCopy[][8]) {
	queue < pair<int, int>> q;

	for (int i = 0; i < viruses.size(); i++) {
		mpCopy[viruses[i].first][viruses[i].second] = 2;
		q.push(viruses[i]);
	}

	while (!q.empty()) {
		pair<int, int> v = q.front(); q.pop();
		
		for (int i = 0; i < 4; i++) {
			if (valid(v.first + rdir[i], v.second + cdir[i])) {
				if (mpCopy[v.first + rdir[i]][v.second + cdir[i]] == 0) {
					q.push(make_pair(v.first + rdir[i], v.second + cdir[i]));
					mpCopy[v.first + rdir[i]][v.second + cdir[i]] = 2;
				}
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mpCopy[i][j] == 0) cnt++;
		}
	}
	return cnt;
}

pair<int, int > findNext(int r, int c) {
	for (int i = r; i < N; i++) {
		for (int j = (i == r ? c + 1 : 0); j < M; j++) {
			if (valid(i, j) && mp[i][j] == 0) {
				return make_pair(i, j);
			}
		}
	}
	return make_pair(-1, -1);
}

void dfs(int r, int c) {

	if (selected.size() == 3) {
		int mpCopy[8][8];
		memcpy(mpCopy, mp, 8 * 8 * sizeof(int));
		for (int i = 0; i < 3; i++) {
			pair<int, int> s = selected[i];
			mpCopy[s.first][s.second] = 1;
		}
		ans = max(ans, spread(mpCopy));
		return;
	}

	if (!valid(r, c)) return;

	selected.push_back(make_pair(r, c));
	pair<int, int> next = findNext(r, c);
	dfs(next.first, next.second);
	selected.pop_back();
	dfs(next.first, next.second);

}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 2) viruses.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i < N; i++) {
		int flag = 0;
		for (int j = 0; j < M; j++) {
			if (mp[i][j] == 0) {
				dfs(i, j);
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}

	cout << ans << '\n';

	return 0;
}
