#include<vector>
#include<algorithm>
#include<iostream>
#include<climits>
using namespace std;
vector<vector<int>> pan;
vector<pair<int, int>> chick;
vector < pair<int, int>> house;
vector < pair<int, int>> selected;
int N = 0;
int M = 0;
int ans = INT_MAX;

int panDist() {
	int totalDist = 0;

	for (auto const& h : house) {
		int hr = h.first;
		int hc = h.second;
		int dist = INT_MAX;

		for (int i = 0; i < M; i++) {
			int cr = selected[i].first;
			int cc = selected[i].second;
			dist = min(dist, abs(hr - cr) + abs(hc - cc));
		}
		totalDist += dist;
	}

	return totalDist;
}

void dfs(int n, int cnt) {
	if (cnt == M) {
		ans = min(ans, panDist());
		return;
	}

	if (n == chick.size()) {
		return;
	}

	int r = chick[n].first;
	int c = chick[n].second;

	pan[r][c] = 2;
	selected.push_back(make_pair(r, c));
	dfs(n + 1, cnt + 1);

	selected.pop_back();
	pan[r][c] = 0;
	dfs(n + 1, cnt);
}

int main() {
	cin >> N >> M;
	pan.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> pan[i][j];
			if (pan[i][j] == 2) {
				chick.push_back(make_pair(i, j));
				pan[i][j] = 0;
			}
			else if (pan[i][j] == 1) {
				house.push_back(make_pair(i, j));
			}
		}
	}

	dfs(0, 0);

	cout << ans << endl;
	return 0;
}
