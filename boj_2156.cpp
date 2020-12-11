#include<iostream>
#include<algorithm>
#define CRT_SECURE_NO_WARNINGS

using namespace std;

int N = 0;
int dp[2][10001] = { 0, };
int wine[10001] = { 0 , };

int main() {


	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", &wine[i]);

	dp[0][1] = 0;
	dp[1][1] = wine[1];

	for (int i = 2; i <= N; i++) {
		dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
		dp[1][i] = max(dp[0][i - 1], dp[0][i - 2] + wine[i - 1]) + wine[i];
	}

	cout << max(dp[0][N], dp[1][N]) << '\n';

	return 0;
}
