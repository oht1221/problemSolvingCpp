#include<bits/stdc++.h>
using namespace std;
int N = 0;
int solved[1000000] = { 0, };
int ans[1000000] = { 0, };

int solve(int n) {
	if (n > N) return N;
	if(n == N) return 0;
	if (solved[n - 1]) return ans[n - 1];
	int best = N;
	best = min(best, solve(n * 3) + 1);
	best = min(best, solve(n * 2) + 1);
	best = min(best, solve(n + 1) + 1);
	
	solved[n - 1] = true;
	ans[n - 1] = best;
	return best;
}

int main() {
	cin >> N;

	cout << solve(1);
}