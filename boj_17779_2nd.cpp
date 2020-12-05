#include<bits/stdc++.h>
using namespace std;

int N = 0;
int mp[20][20] = { 0, };
int pop[20][20] = { 0, };
int ans = INT_MAX;

void check() {
	cout << '\n';
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << mp[i][j] << " ";
		}
		cout << '\n';
	}
}

void resetMp() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			mp[i][j] = 0;
		}
	}
}

bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

bool validD1D2(int x, int y, int d1, int d2) {
	return (
			x + d1 + d2 < N &&
			0 <= y - d1 &&
			y + d2 < N
		);
}

void area1234(int x, int y, int d1, int d2) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mp[i][j] != 5) {
				if (0 <= i && i < x + d1 && 0 <= j && j <= y) mp[i][j] = 1;
				else if (0 <= i && i <= x + d2 && y < j && j < N) mp[i][j] = 2;
				else if (x + d1 <= i && i < N && 0 <= j && j < y - d1 + d2) mp[i][j] = 3;
				else if (x + d2 < i && i < N && y - d1 + d2 <= j && j < N) mp[i][j] = 4;
			}
		}
	}
}

void area5(int x, int y, int d1, int d2) {
	for (int i = 0; i <= d1; i++) {
		mp[x + i][y - i] = 5;
		mp[x + d2 + i][y + d2 - i] = 5;
	}

	for (int i = 0; i <= d2; i++) {
		mp[x + i][y + i] = 5;
		mp[x + d1 + i][y - d1 + i] = 5;
	}
	
	for (int i = 1; i <= d1; i++) {
		int r = x + i;
		int c = y - i;
		
		while (mp[r][c + 1] != 5) {
			mp[r][c + 1] = 5;
			c = c + 1;
		}
	}

	for (int i = 1; i < d2; i++) {
		int r = x + d1 + i;
		int c = y - d1 + i;

		while (mp[r][c + 1] != 5) {
			mp[r][c + 1] = 5;
			c = c + 1;
		}
	}
}

int calcDiff() {
	vector<int> sum = { 0, 0, 0, 0, 0 };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum[mp[i][j] - 1] += pop[i][j];
		}
	}

	sort(sum.begin(), sum.end());
	return sum[4] - sum[0];
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> pop[i][j];
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int d1 = 1; d1 < N; d1++) {
				for (int d2 = 1; d2 < N; d2++) {
					if (validD1D2(i, j, d1, d2)) {
						area5(i, j, d1, d2);
						area1234(i, j, d1, d2);

						ans = min(ans, calcDiff());
						resetMp();
					}
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
