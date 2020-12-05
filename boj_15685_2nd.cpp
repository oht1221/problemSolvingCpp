#include<bits/stdc++.h>
using namespace std;
int N = 0;
int initials[20][4];
int xdir[4] = { 1, 0, -1, 0 };
int ydir[4] = { 0, -1, 0, 1 };
int mp[101][101];

vector<vector<pair<int, int>>> curves;

bool isValid(int r, int c) {
	return 0 <= r && r < 101 && 0 <= c && c < 101;
}

bool isSquare(int x, int y) {
	return mp[x][y] == 1 && mp[x + 1][y] == 1 && mp[x][y + 1] == 1 && mp[x + 1][y + 1] == 1;
}
int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> initials[i][j];
		}
	}


	for (int i = 0; i < N; i++) {
		int x = initials[i][0];
		int y = initials[i][1];
		int d = initials[i][2];
		int g = initials[i][3];

		vector<pair<int, int>> row; 
		row.push_back(make_pair(x, y));
		row.push_back(make_pair(x + xdir[d], y + ydir[d]));
		curves.push_back(row);

		for (int j = 1; j <= g; j++) {
			pair<int, int> base = curves[i].back();
			int baseX = base.first;
			int baseY = base.second;

			int K = curves[i].size();
			for (int k = K - 2; k >= 0; k--) {
				int x = curves[i][k].first;
				int y = curves[i][k].second;
				int dx = x - baseX;
				int dy = y - baseY;
				x = baseX - dy;
				y = baseY + dx;
				curves[i].push_back(make_pair(x, y));
			}
		}
		
		for (auto e : curves[i]) {
			mp[e.first][e.second] = 1;
		}
	}
	
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (isSquare(i, j)) ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}
