#include<bits/stdc++.h>

using namespace std;
vector<int> T;
vector<int> P;
int N = 0;
int ans = 0;

void dfs(int n, int sum) {
	if (n > N) return;

	ans = max(sum, ans);

	if (n == N) return;
	dfs(n + T[n], sum + P[n]); //¼±ÅÃ

	dfs(n + 1, sum);
}

int main() {
	cin >> N;
	T.assign(N, 0);
	P.assign(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> T[i] >> P[i];
	}

	dfs(0, 0);


	cout << ans << '\n';
	return 0;

}
