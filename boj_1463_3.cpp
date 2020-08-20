#include<bits/stdc++.h>
using namespace std;

int N = 0;
bool solved[1000000] = { false, };
int ans[1000000] = { 0, };

int solve(int n) {
	if (n == 1) return 0;
	if (!solved[n - 1]) {
		ans[n - 1] = N;
		if (n % 3 == 0) ans[n - 1] = min(ans[n - 1], solve(n / 3) + 1);
		if (n % 2 == 0) ans[n - 1] = min(ans[n - 1], solve(n / 2) + 1);
		ans[n - 1] = min(ans[n - 1], solve(n - 1) + 1);

		solved[n - 1] = true;
	} 
	
	return ans[n - 1];
}

int main() {
	cin >> N;
	cout << solve(N);
	return 0;
}