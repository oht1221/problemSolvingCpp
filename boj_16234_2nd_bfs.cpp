#include<bits/stdc++.h>
using namespace std;
int N = 0;
int L, R = 0;
int mp[50][50] = { 0, };

int rdir[4] = { -1, 1, 0, 0 };
int cdir[4] = { 0, 0, -1,1 };

bool isvalid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

void check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << mp[i][j] << " ";
		}
		cout << '\n';
	}
}
int calcAvg(vector<pair<int, int>> &n) {
	int sum = 0;
	for (auto coord : n) {
		sum += mp[coord.first][coord.second];
	}

	return sum / n.size();
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

		for(int i =0; i < N ; i++) {
			for (int j = 0; j < N; j++) {
				queue<pair<int, int>> Q;
				vector<pair<int, int>> nation;
				int sum = 0;

				if (visit[i][j] == 1) {
					continue;
				}

				else {
					Q.push(make_pair(i, j));
					visit[i][j] = 1;
					nation.push_back(make_pair(i, j));
					sum += mp[i][j];
				}

				while (!Q.empty()) {
					pair<int, int> q = Q.front(); Q.pop();
					for (int i = 0; i < 4; i++) {
						int r_next = q.first + rdir[i];
						int c_next = q.second + cdir[i];
						if (isvalid(r_next, c_next) && visit[r_next][c_next] == 0) {
							int gab = abs(mp[q.first][q.second] - mp[r_next][c_next]);
							if (L <= gab && gab <= R) {
								Q.push(make_pair(r_next, c_next));
								visit[r_next][c_next] = 1;
								nation.push_back(make_pair(r_next, c_next));
								sum += mp[r_next][c_next];
								flag = 1;
							}
						}
					}
				}
				if (nation.size() >= 2) {
					int avg = sum / nation.size();
					for (auto coord : nation) {
						mp[coord.first][coord.second] = avg;
					}
				}
			}
		}
		if (flag == 0) break;
		else ans++;
	}

	cout << ans << '\n';

	return 0;
}
