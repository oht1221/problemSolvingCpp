#include <iostream>
#include <vector>
#include<algorithm>
#include<cmath>


using namespace std;

vector<int> numbers = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int N = 0;
int M = 0;
int ans = 1000000;
int x[6] = { 0, };

void dfs(int step) {
	if (step == 7) return;

	for (int i = 0; i < numbers.size(); i++) {
		x[step - 1] = numbers[i];
		int num = 0;
		for (int j = 0; j < step; j++) {
			num += x[j] * pow(10, j);
		}
		int cnt = abs(num - N) + step;
		ans = min(cnt, ans);
		dfs(step + 1);
	}
}
int main() {
	cin >> N >> M;
	ans = abs(N - 100);
	for (int i = 0; i < M; i++) {
		int a = 0;
		cin >> a;
		numbers.erase(find(numbers.begin(), numbers.end(), a));
	}

	dfs(1);

	cout << ans << endl;
	return 0;
}
