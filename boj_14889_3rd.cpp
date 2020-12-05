#include<bits/stdc++.h>
using namespace std;
int N = 0;
int ans = INT_MAX;

int totalSum = 0;
vector<vector<int>> S;

vector<int> selected;
vector<int> selected2;


int selectedSum(vector<int> const & selected) {
	int sum = 0;
	for (int i = 0; i < selected.size(); i++) {
		int idx = selected[i];
		for (int j = 0; j < N; j++) {
			if (find(selected.begin(), selected.end(), j) != selected.end()) {
				sum += S[idx][j];
			}
		}
	}
	return sum;
}


void dfs1(int n) {
	if (selected.size() == N / 2) {
		int sum1 = selectedSum(selected);
		for (int i = 0; i < N; i++) {
			if (find(selected.begin(), selected.end(), i) == selected.end()) {
				selected2.push_back(i);
			}
		}
		int sum2 = selectedSum(selected2);
		ans = min(ans, abs(sum1 - sum2));
		selected2.clear();
		return;
	}

	if (n == N) return;

	if (N / 2 - selected.size() > N - n) {
		return;
	}

	selected.push_back(n);
	dfs1(n + 1);

	selected.pop_back();
	dfs1(n + 1);

}
int main() {
	cin >> N;
	vector<int> row(N, 0);
	S.assign(N, row);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
			totalSum += S[i][j];
		}
	}

	dfs1(0);
	cout << ans << '\n';
	return 0;
}
