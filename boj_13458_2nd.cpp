#include<bits/stdc++.h>
using namespace std;
int N = 0;
long long A[1000000] = { 0, };
long long B, C = 0;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		A[i] = A[i] - B;
		ans += 1;
		if (A[i] > 0) {
			ans += A[i] / C;
			if ((A[i] % C) != 0) ans++;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
