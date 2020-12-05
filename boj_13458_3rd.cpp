#include<bits/stdc++.h>
using namespace std;
int N = 0;
vector<long long> A;
long long B, C = 0;
long long cnt = 0;

int main() {
	cin >> N;
	A.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cin >> B >> C;

	for_each(A.begin(), A.end(), [](long long& a) { a = a - B > 0 ? a - B : 0; });
	cnt += A.size();

	for (auto const &a : A) {
		cnt += (a / C);
		cnt += a % C == 0 ? 0 : 1;
	}

	cout << cnt << '\n';
	return 0;
}

