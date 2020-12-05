#include<bits/stdc++.h>
using namespace std;
queue<pair<int, int>> Q;
queue<int> len;
int N, M;
int mp[8][500][500];

int ans = 0;

int r_blue[4] = { 0, 0, 0, 0 };
int c_blue[4] = { 0, 1, 2, 3 };

int r_yellow[4] = { 0, 0, 1, 1 };
int c_yellow[4] = { 0, 1, 0, 1 };

int r_orange[4] = { 0, 1, 2, 2};
int c_orange[4] = { 0, 0, 0, 1 };

int r_green[4] = { 0, 1, 1, 2 };
int c_green[4] = { 0, 0, 1, 1 };

int r_pink[4] = { 0, 0, 0, 1 };

int c_pink[4] = { 0, 1, 2, 1 };

bool valid(int r, int c, int n) {
	if(n == 0 || n == 2 || n == 4 || n == 5) return 0 <= r && r < N && 0 <= c && c < M;
	else if(n == 1 || n == 3 || n == 6 || n == 7) return 0 <= r && r < M && 0 <= c && c < N;
}

int blue(int r, int c, int n) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (valid(r + r_blue[i], c + c_blue[i], n)) {
			sum += mp[n][r + r_blue[i]][c + c_blue[i]];
		}
		else return 0;
	}
	return sum;
}

int yellow(int r, int c, int n) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (valid(r + r_yellow[i], c + c_yellow[i], n)) {
			sum += mp[n][r + r_yellow[i]][c + c_yellow[i]];
		}
		else return 0;
	}
	return sum;
}
int orange(int r, int c, int n) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (valid(r + r_orange[i], c + c_orange[i], n)) {
			sum += mp[n][r + r_orange[i]][c + c_orange[i]];
		}
		else return 0;
	}
	return sum;
}
int green(int r, int c, int n) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (valid(r + r_green[i], c + c_green[i], n)) {
			sum += mp[n][r + r_green[i]][c + c_green[i]];
		}
		else return 0;
	}
	return sum;
}
int pink(int r, int c, int n) {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (valid(r + r_pink[i], c + c_pink[i], n)) {
			sum += mp[n][r + r_pink[i]][c + c_pink[i]];
		}
		else return 0;
	}
	return sum;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int e = 0;
			cin >> e;
			mp[0][i][j] = e;
			mp[1][j][N - 1 - i] = e;
			mp[2][N - 1 - i][M - 1 - j] = e;
			mp[3][M - 1 - j][i] = e;

			mp[4][N - 1 - i][j] = e;
			mp[5][i][M - 1 - j] = e;

			mp[6][M - 1 - j][N - 1 - i] = e;
			mp[7][j][i] = e;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 8; k++) {
				if (k == 0 || k == 2 || k == 4 || k == 5) {
					ans = max(ans, blue(i, j, k));
					ans = max(yellow(i, j, k), ans);
					ans = max(orange(i, j, k), ans);
					ans = max(green(i, j, k), ans);
					ans = max(pink(i, j, k), ans);
				}
				else {
					ans = max(ans, blue(j, i, k));
					ans = max(yellow(j, i, k), ans);
					ans = max(orange(j, i, k), ans);
					ans = max(green(j, i, k), ans);
					ans = max(pink(j, i, k), ans);
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
