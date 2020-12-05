#include<bits/stdc++.h>
using namespace std;

int ans = 0;
int mp[15][2];
int N;
void dfs(int n, int sum) {
	if (n == N) {
		ans = max(ans, sum);
		return;
	}
	if (n > N) {
		return;
	}

	dfs(n + mp[n][0], sum + mp[n][1]);
	dfs(n + 1, sum);
}
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> mp[i][0] >> mp[i][1];
	}


	dfs(0, 0);

	cout << ans << '\n';

	return 0;
}
