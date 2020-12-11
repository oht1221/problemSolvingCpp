#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int T, N = 0;

int dp[2][100001] = { 0, };
int stickers[2][100001] = { 0, };

void init() {
	memset(dp, 0, 4 * 2 * 100001);
	memset(stickers, 0, 4 * 2 * 100001);
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		init();

		for (int i = 1; i <= N; i++) {
			cin >> stickers[0][i];
		}
		for (int i = 1; i <= N; i++) {
			cin >> stickers[1][i];
		}

		dp[0][1] = stickers[0][1];
		dp[1][1] = stickers[1][1];
		dp[0][2] = stickers[1][1] + stickers[0][2];
		dp[1][2] = stickers[0][1] + stickers[1][2];

		for (int n = 3; n <= N; n++) {
			dp[0][n] = max(dp[1][n - 1], dp[1][n - 2]) + stickers[0][n];
			dp[1][n] = max(dp[0][n - 1], dp[0][n - 2]) + stickers[1][n];
		}

		cout << max(dp[0][N], dp[1][N]) << '\n';
	}


	return 0;
}
