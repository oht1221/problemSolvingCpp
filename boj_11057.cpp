#include<iostream>
using namespace std;

int dp[10][1001] = { 0, };
int N = 0;

int main() {
	cin >> N;
	for (int i = 0; i < 10; i++) {
		dp[i][1] = 1;
	}
	
	for (int n = 2; n <= N; n++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j <= i; j++) {
				dp[i][n] = (dp[i][n] + dp[j][n - 1]) % 10007;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans = (ans + dp[i][N]) % 10007;
	}
	cout << ans << '\n';
	return 0;

}
