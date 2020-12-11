#include <iostream>
using namespace std;

int dp[1001] = { 0, };
int N = 0;
int solve(int n) {
    if (n == 1) return 1;
    else if (n == 2) return 3;
    else if (dp[n] == 0) {
        dp[n] = (solve(n - 1) + 2 * solve(n - 2)) % 10007;
    }

    return dp[n];
}

int main() {
    cin >> N;

    cout << solve(N);

    return 0;
}