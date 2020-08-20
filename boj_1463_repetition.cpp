#include <bits/stdc++.h>
using namespace std;
int N = 0;
int ans[1000000] = { 0, };

int main() {
	cin >> N;
	ans[0] = 0;
	for (int i = 2; i <= N; i++) {
		ans[i - 1] = N;
		if (i % 3 == 0) ans[i - 1] = min(ans[i - 1], ans[(i / 3) - 1] + 1);
		if (i % 2 == 0) ans[i - 1] = min(ans[i - 1], ans[(i / 2) - 1] + 1);
		ans[i - 1] = min(ans[i - 1], ans[(i - 1) - 1] + 1);
	}
	cout << ans[N - 1] << endl;
}