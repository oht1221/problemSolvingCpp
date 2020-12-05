#include<bits/stdc++.h>
using namespace std;
int N, H, M;
vector<vector<int>> mp;


bool isValid(int a, int b) {
	return 0 <= a && a < H && 0 <= b && b < N - 1;
}

bool move(int i) {
	int n = i;
	for (int h = 0; h < H; h++) {
		if (isValid(h, n - 1) && mp[h][n - 1] == 1) {
			n = n - 1;
		}
		else if (isValid(h, n) && mp[h][n] == 1) {
			n = n + 1;
		}
	}
	return n == i;
}

bool isCompleted() {
	for (int i = 0; i < N; i++) {
		if (!move(i)) {
			return false;
		}
	}
	return true;
}

bool isEmpty(int a, int b) {
	return !isValid(a, b) || (isValid(a, b) && mp[a][b] == 0);
}

bool dfs(int d, int a, int b) {
	if (d == 0) {
		return isCompleted();
	}
	
	for (int i = a; i < H; i++) {
		for (int j = (i == a ? b : 0); j < N - 1; j++) {
			if (mp[i][j] == 0) {
				if (isEmpty(i, j - 1) && isEmpty(i, j + 1)) {
					mp[i][j] = 1;
					if (dfs(d - 1, i, j)) return true;
					mp[i][j] = 0;
				}
			}
		}
	}
	return false;
}

int main() {
	cin >> N >> M >> H;

	for (int i = 0; i < H; i++) {
		vector<int> row(N - 1);
		mp.push_back(row);
	}

	for (int i = 0; i < M; i++) {
		int a = 0; int b = 0;
		cin >> a >> b;
		mp[a - 1][b - 1] = 1;
	}

	int ans = -1;

	for (int i = 0; i <= 3; i++) {
		if (dfs(i, 0, 0)) {
			ans = i;
			break;
		}
	}
	cout << ans << '\n';

	return 0;
}
