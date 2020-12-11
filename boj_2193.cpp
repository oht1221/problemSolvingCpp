#include<iostream>
using namespace std;

long long dp[2][91] = { 0, };
int N = 0;
int main() {
	cin >> N;

	dp[0][1] = 0;
	dp[1][1] = 1;

	for (int n = 2; n <= N; n++) {
		dp[0][n] = dp[0][n - 1] + dp[1][n - 1];
		dp[1][n] = dp[0][n - 1];
	}

	cout << dp[0][N] + dp[1][N] << '\n';
	return 0;
}
