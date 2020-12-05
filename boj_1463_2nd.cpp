#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

vector<int> memo;
int N = 0;

int dp(int n) {
    if (n == N) return 0;
    else if (memo[n] == 0) {
        int mul3 = n * 3 > N ? INT_MAX : dp(n * 3) + 1;
        int mul2 = n * 2 > N ? INT_MAX : dp(n * 2) + 1;
        int pls1 = n + 1 > N ? INT_MAX : dp(n + 1) + 1;
        int m = min(mul3, mul2);
        m = min(m, pls1);
        memo[n] = m;
    }

    return memo[n];
}
int main() {
    cin >> N;
    memo.assign(N + 1, 0);
    int ans = dp(1);
    cout << ans << endl;
    return 0;
}