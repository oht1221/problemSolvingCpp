#include<iostream>
#include<string.h>
using namespace std;

int dp[10][101] = { 0, };
int N = 0;

int solve(int i, int n){
	if (n == 1) {
		return dp[i][n];
	}
	if (dp[i][n] == 0) {
		if (i == 0) {
			dp[i][n] = solve(i + 1, n - 1);
		}
		else if (i == 9) {
			dp[i][n] = solve(i - 1, n - 1);
		}
		else {
			dp[i][n] = (solve(i + 1, n - 1) + solve(i - 1, n - 1)) % 1000000000;
		}
	}
	return dp[i][n];
}
int main() {
	memset(dp, 0, 4 * 10 * 101);
	for (int i = 1; i < 10; i++) dp[i][1] = 1;
	cin >> N;
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans = (ans + solve(i, N)) % 1000000000;
	}

	cout << ans<< '\n';
	return 0;
}
