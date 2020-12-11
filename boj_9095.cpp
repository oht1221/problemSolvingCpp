#include<iostream>
using namespace std;

int N = 0;
int T = 0;
int dp[11] = { 0, };

int solve(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;

	if (dp[n] == 0) {
		dp[n] = solve(n - 1) + solve(n - 2) + solve(n - 3);
	}
	return dp[n];
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N;

		cout << solve(N) << '\n';
	}
	return 0;
}