#include<iostream>
using namespace std;

int N = 0;
int T = 0;

int main() {
	cin >> T;

	while (T--) {
		cin >> N;

		int dp[3][100001] = { 0, };
		int stickers[2][100001] = { 0, };

		for (int i = 1; i <= N; i++) {
			cin >> stickers[0][i];
		}
		for (int i = 1; i <= N; i++) {
			cin >> stickers[1][i];
		}

		dp[0][1] = 0;
		dp[1][1] = stickers[0][1];
		dp[2][1] = stickers[1][1];

		for (int i = 2; i <= N; i++) {
			dp[0][i] = max(max(dp[0][i - 1], dp[1][i - 1]), dp[2][i - 1]);
			dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + stickers[0][i];
			dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]) + stickers[1][i];
		}

		cout << max(max(dp[0][N], dp[1][N]), dp[2][N]) << endl;

	}
	
	return 0;
}