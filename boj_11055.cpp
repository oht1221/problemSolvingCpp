#include<iostream>
#include<algorithm>
using namespace std;
int N = 0;
int A[1001] = { 0, };
int dp[1001] = { 0, };

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++){
		cin >> A[i];
		dp[i] = A[i];

		for (int j = i - 1; j >= 1; j--) {
			if (A[j] < A[i]) {
				dp[i] = max(dp[i], dp[j] + A[i]);
			}
		}
	}

	int* ans = max_element(dp + 1, dp + N + 1);
	cout << *ans << '\n';
	return 0;
}
