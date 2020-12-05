#include <iostream>
#include <string.h>
using namespace std;

int dp[1001] = { 0, };
int N = 0;
int solve(int n) {
    if (n == 1) {
        dp[n] = 1;
        return dp[n];
    }
    else if (n == 2) {
        dp[n] = 2;
        return dp[n];
    }
    else if (dp[n] != -1) {
        return dp[n];
    }
    dp[n] = (solve(n - 1) + solve(n - 2)) % 10007;
    return dp[n];
}

int main() {
    memset(dp, -1, 1001 * 4);
    cin >> N;
    cout << solve(N);
    return 0;
}
