#include<bits/stdc++.h>
using namespace std;
int N = 0;
int memo[1000000] = { 0, };

void dfs(int n, int stage) {
	if (n != N && memo[n - 1] <= stage) return;
	memo[n - 1] = stage;

	if (n == 1) return;

	if (n % 3 == 0) dfs(n / 3, stage + 1);
	if (n % 2 == 0) dfs(n / 2, stage + 1);
	dfs(n - 1, stage + 1);
	
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		memo[i] = N - 1;
	}

	dfs(N, 0);
	cout << memo[0] << '\n';
	return 0;
}
