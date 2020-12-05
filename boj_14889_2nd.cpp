#include<bits/stdc++.h>
using namespace std;
int N = 0;
int mp[20][20] = { 0, };
int S = 0;
vector<int> team1;
int selected[20] = { 0, };
int ans = INT_MAX;

int dfs2(int n, vector<int> const & team, vector<int> &s) {
	if (S - n < 2 - s.size()) {
		return 0;
	}
	if (s.size() == 2) {
		return mp[s[0]][s[1]] + mp[s[1]][s[0]];
	}

	s.push_back(team[n]);
	int s1 = dfs2(n + 1, team, s);
	s.pop_back();
	int s2 = dfs2(n + 1, team, s);

	return s1 + s2;
}

int sum(vector<int> const & v) {
	vector<int> s;
	return dfs2(0, v, s);
}

void dfs1(int n) {
	if (N - n < S - team1.size()) return;
	if (team1.size() == S) {
		vector<int> team2;
		for (int i = 0; i < N; i++) {
			if (selected[i] == 0) {
				team2.push_back(i);
			}
		}
		int s1 = sum(team1);
		int s2 = sum(team2);
		ans = min(abs(s1 - s2), ans);
		return;
	}

	team1.push_back(n);
	selected[n] = 1;
	dfs1(n + 1);
	selected[n] = 0;
	team1.pop_back();
	dfs1(n + 1);

}

int main() {
	cin >> N;
	S = N / 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mp[i][j];
		}
	}

	dfs1(0);
	cout << ans << '\n';
	return 0;
}
