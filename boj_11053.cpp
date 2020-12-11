#include<iostream>
#include<string.h>

using namespace std;
int N = 0;
int A[1001] = { 0, };
int dp[1001] = { 0, };

int main() {
	cin >> N;

	fill(dp + 1, dp + 1001, 1);

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		for (int j = i - 1; j >= 1; j--) {
			if (A[i] > A[j]) {
				dp[i] =max(dp[i], dp[j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(dp[i], ans);
	}
	
	cout << ans << endl;
	return 0;
}