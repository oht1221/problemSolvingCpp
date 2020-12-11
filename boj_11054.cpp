#include<iostream>
#include<algorithm>
using namespace std;

int N = 0;
int dp[2][1001] = { 0, };
int A[1001] = { 0, };

int main() {
	cin >> N;
	fill(dp[0] + 1, dp[0] + 1000, 1);
	fill(dp[1] + 1, dp[1] + 1000, 1);

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		for (int j = i - 1; j >= 1; j--) {
			if (A[i] != A[j]) {
				if (A[i] > A[j]) {
					dp[0][i] = max(dp[0][i], dp[0][j] + 1);
				}
				else if (A[i] < A[j]) {
					dp[1][i] = max(max(dp[1][i], dp[0][j] + 1), dp[1][j] + 1);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < 1001; i++) {
		for (int j = 0; j < 2; j++) {
			ans = max(dp[j][i], ans);
		}
	}
	cout << ans << '\n';
	return 0;
}
