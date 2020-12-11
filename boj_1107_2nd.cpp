#include<iostream>
using namespace std;

int broken[10] = { 0, };
int N = 0;
int M = 0;
int ans = 0;

int isPossible(int n) {
	int cnt = 0;

	if (n == 0) return broken[0] ? 0 : 1;

	while (n) {
		if (broken[n % 10]) return 0;
		n = n / 10;
		cnt++;
	}

	return cnt;
}

int main() {
	cin >> N;
	cin >> M;
	while (M--) {
		int a = 0;
		cin >> a;
		broken[a] = 1;
	}

	ans = abs(N - 100);

	for (int i = 0; i < 1000000; i++) {
		int cnt = isPossible(i);
		if (cnt) {
			ans = min(ans, abs(i - N) + cnt);
		}
	}

	cout << ans << endl;
	return 0;
}
