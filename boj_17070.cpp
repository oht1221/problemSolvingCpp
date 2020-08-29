#include<bits/stdc++.h>
using namespace std;
enum type {
	HORI = 0,
	VERT,
	DIAG
};
int memo[3][16][16] = { -1, };
int mp[16][16] = { 0, };
int N = 0;

int rdir[3] = { 0, -1, -1 };
int cdir[3] = { -1, 0, -1 };

void check() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << mp[i][j] << " ";
		}
		cout << '\n';
	}
}

bool isBlocked(int t, int r, int c) {
	if (t == 0) return r < 0 || c - 1 < 0 || mp[r][c - 1] == 1 || mp[r][c] == 1;
	else if (t == 1) return  r - 1 < 0 || c < 0 || mp[r - 1][c] == 1 || mp[r][c] == 1;
	else if (t == 2) return  r - 1 < 0 || c - 1 < 0 || mp[r][c] == 1 || mp[r - 1][c] == 1 || mp[r][c - 1] == 1 || mp[r - 1][c - 1] == 1;
}

int solve(int t, int r, int c) {
	if (t == HORI && r == 0 && c == 1) return (memo[t][r][c] = 1);
	if (isBlocked(t, r, c)) return 0;
	if (memo[t][r][c] != -1) return memo[t][r][c];
	else {
		if (t == HORI) return (memo[t][r][c] = solve(HORI, r, c - 1) + solve(DIAG, r, c - 1));
		else if (t == VERT) return (memo[t][r][c] = solve(VERT, r - 1, c) + solve(DIAG, r - 1, c));
		else if (t == DIAG) return (memo[t][r][c] = solve(HORI, r - 1, c - 1) + solve(VERT, r - 1, c - 1) + solve(DIAG, r - 1, c - 1));
	}
	
	return memo[t][r][c];
}

int main() {
	cin >> N;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 16; j++) {
			for (int k = 0; k < 16; k++) memo[i][j][k] = -1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mp[i][j];
		}
	}

	cout << solve(HORI, N - 1, N - 1) + solve(VERT, N - 1, N - 1) + solve(DIAG, N - 1, N - 1) << '\n';

	return 0;
}