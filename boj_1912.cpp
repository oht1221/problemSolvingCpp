#include<iostream>
#include<algorithm>

using namespace std;

int N = 0;
int A[100001] = { 0, };
int ground[100001] = { 0, };
int ans = 0;
int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	ans = A[1];
	ground[1] = max(A[1], 0);

	for (int i = 2; i <= N; i++) {
		ans = max(ground[i - 1] + A[i], ans);
		ground[i] = max(ground[i - 1] + A[i], 0);
	}

	printf("%d \n", ans);
	return 0;
}

