#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i < b; i++) 
const char nl = '\n';
using namespace std;

int mp[21][21] = { 0, };
int pop[21][21] = { 0, };
int N = 0;

void init() {
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			mp[i][j] = 0;
		}
	}
}

int divide(int x, int y, int d1, int d2) {
	vector <int> prt;
	prt.push_back(0); prt.push_back(0); prt.push_back(0); prt.push_back(0); prt.push_back(0);

	FOR(i, 0, d1 + 1) { if (y - i >= 0 && x + i < N) mp[x + i][y - i] = 5; }
	FOR(i, 0, d2 + 1) { if (x + i < N && y + i < N) mp[x + i][y + i] = 5; }
	FOR(i, 0, d2 + 1) { if (x + d1 + i < N && 0 <= y - d1 + i && y - d1 + i < N) mp[x + d1 + i][y - d1 + i] = 5; }
	FOR(i, 0, d1 + 1) { if (x + d2 + i < N && 0 <= y + d2 - i && y + d2 - i < N) mp[x + d2 + i][y + d2 - i] = 5; }
	
	FOR(i, 0, d1) {
		int l1 = 1;
		while (mp[x + i + l1][y - i] != 5) {
			mp[x + i + l1][y - i] = 5; l1++;
		}
	}

	FOR(i, 1, d2) {
		int l2 = 1;
		while (mp[x + i + l2][y + i] != 5) {
			mp[x + i + l2][y + i] = 5; l2++;
		}
	}

	FOR(i, 0, d2 + 1) { if (x + i < N && y + i < N) mp[x + i][y + i] = 5; }

	
	FOR(r, 0, N) {
		FOR(c, 0, N) {
			if (mp[r][c] == 5) continue;
			if (0 <= r && r < x + d1 && 0 <= c && c <= y) mp[r][c] = 1;
			else if (0 <= r && r <= x + d2 && y < c && c <= N - 1) mp[r][c] = 2;
			else if (x + d1 <= r && r <= N - 1 && 0 <= c && c < y - d1 + d2) mp[r][c] = 3;
			else if (x + d2 < r && r <= N - 1 && y - d1 + d2 <= c && c <= N - 1) mp[r][c] = 4;
		}
	}
	

	FOR(i, 0, N) {
		FOR(j, 0, N) {
			prt[mp[i][j] - 1] += pop[i][j];
		}
	}

	sort(prt.begin(), prt.end());
	int mul = 1;
	int ret = 0;
	FOR(i, 0, 5) mul *= prt[i];
	if (mul == 0) ret = 40000;
	else ret = abs(prt[4] - prt[0]);
	return ret;
}

int main() {
	cin >> N;
	FOR(i, 0, N) {
		FOR(j, 0, N) cin >> pop[i][j];
	}

	int ans = 40000;
	
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			FOR(d1, 1, N) {
				FOR(d2, 1, N) {
					if (i + d1 + d2 < N && j - d1 >= 0 && j + d2 < N) ans = min(ans, divide(i, j, d1, d2));
					init();
				}
			}
		}
	}
	cout << ans;
	
	/*
	cout << divide(1, 0, 1, 1) << nl;
	FOR(i, 0, N) {
		FOR(j, 0, N) cout << mp[i][j] << ' ';
		cout << nl;
	}
	*/
	return 0;
}
