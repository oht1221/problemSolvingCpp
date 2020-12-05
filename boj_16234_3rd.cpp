#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
int N = 0;
vector<vector<int>> pan;
deque<pair<int, int>> Q;
int L, R;
int ans = 0;

bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

int rdir[4] = { -1, 0, 1, 0 };
int cdir[4] = { 0, 1, 0, -1 };

void dfs(int r, int c, int isnation[][50], int &sum, int &cnt, vector<pair<int,int>> & nation) {

	
	isnation[r][c] = 1;
	sum += pan[r][c];
	cnt++;
	nation.push_back(make_pair(r, c));

	for (int i = 0; i < 4; i++) {
		int rnext = r + rdir[i];
		int cnext = c + cdir[i];

		if (isValid(rnext, cnext)) {
			if (isnation[rnext][cnext] == 0) {
				int diff = abs(pan[r][c] - pan[rnext][cnext]);
				if (L <= diff && diff <= R) {
					dfs(rnext, cnext, isnation, sum, cnt, nation);
				}
			}
		}
	}
}
int main() {
	cin >> N >> L >> R;
	pan.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> pan[i][j];
		}
	}

	while (1) {
		int isNation[50][50] = { 0, };
		int flag = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (isNation[r][c] == 0) {
					vector<pair<int, int>> nation;
					int sum = 0;
					int cnt = 0;
					dfs(r, c, isNation, sum, cnt, nation);
					int avg = sum / cnt;

					if (nation.size() >= 2) {
						flag = 1;
						for (auto const& n : nation) {
							pan[n.first][n.second] = avg;
						}
					}

				}
			}
		}
		if (flag == 0) break;
		else ans++;
	}
	cout << ans << endl;
	return 0;
}
