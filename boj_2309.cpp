#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int height[9] = { 0, };
int sum = 0;
vector<int> selected;

int dfs(int n) {
	if (selected.size() == 7) {
		if (sum == 100) {
			vector<int> ans(selected);
			sort(ans.begin(), ans.end());
			for (int i = 0; i < 7; i++) {
				cout << ans[i] << endl;
			}
			return 1;
		}
		else return -1;
	}
	if (n >= 9) {
		return -1;
	}

	selected.push_back(height[n]);
	sum += height[n];
	if (dfs(n + 1) == 1) {
		return 1;
	}
	sum -= height[n];
	selected.pop_back();
	if (dfs(n + 1) == 1) {
		return 1;
	}
	return -1;
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> height[i];
	}

	cout << endl;
	dfs(0);

	return 0;
}
