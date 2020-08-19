#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
void printStatus(vector<vector<int>> & arr, int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

bool inValid(int r, int N, int c, int M) {
	return (r < 0 || r >= N || c < 0 || c >= M);
}
int func(vector<vector<int>> const arr, int i, int N, int M) {
 //1
	int r1 = 0; int c1 = 0;
	int r2 = 0; int c2 = 0;
	int r3 = 0; int c3 = 0;
	int r4 = 0; int c4 = 0;

	if (i == 0) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1 + 1; c2 = c1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1; c3 =  c1 + 1;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 + 1; c4 = c1 + 1;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 1) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1 + 1; c2 = c1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1 + 2; c3 = c1;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 + 3; c4 = c1;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 2) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1; c2 = c1 + 1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1; c3 = c1 + 2;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1; c4 = c1 + 3;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 3) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1 + 1; c2 = c1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1 + 2; c3 = c1;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 + 2; c4 = c1 + 1;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 4) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1; c2 = c1 + 1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1 + 1; c3 = c1 + 1;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 + 2; c4 = c1 + 1;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 5) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1; c2 = c1 + 1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1; c3 = c1 + 2;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 - 1; c4 = c1 + 2;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 6) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1 - 1; c2 = c1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1 - 1; c3 = c1 + 1;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 - 1; c4 = c1 + 2;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 7) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1; c2 = c1 + 1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1 - 1; c3 = c1 + 1;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 - 2; c4 = c1 + 1;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 8) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1 + 1; c2 = c1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1 + 1; c3 = c1 + 1;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 + 1; c4 = c1 + 2;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 9) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1; c2 = c1 + 1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1; c3 = c1 + 2;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 + 1; c4 = c1 + 2;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 10) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1; c2 = c1 - 1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1 + 1; c3 = c1 - 1;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 + 2; c4 = c1 - 1;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 11) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1; c2 = c1 + 1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1 + 1; c3 = c1 + 1;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 + 1; c4 = c1 + 2;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 12) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1; c2 = c1 + 1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1 - 1; c3 = c1 + 1;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 - 1; c4 = c1 + 2;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 13) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1 + 1; c2 = c1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1 + 1; c3 = c1 + 1;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 + 2; c4 = c1 + 1;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 14) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1 - 1; c2 = c1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1 - 1; c3 = c1 + 1;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 - 2; c4 = c1 + 1;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 15) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1; c2 = c1 + 1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1; c3 = c1 + 2;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 - 1; c4 = c1 + 1;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 16) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1; c2 = c1 + 1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1; c3 = c1 + 2;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 + 1; c4 = c1 + 1;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 17) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1 + 1; c2 = c1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1 + 2; c3 = c1;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 + 1; c4 = c1 + 1;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}
	else if (i == 18) {
		int ret = 0;
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				r1 = n; c1 = m;
				r2 = r1 + 1; c2 = c1;
				if (inValid(r2, N, c2, M)) continue;
				r3 = r1 + 2; c3 = c1;
				if (inValid(r3, N, c3, M)) continue;
				r4 = r1 + 1; c4 = c1 - 1;
				if (inValid(r4, N, c4, M)) continue;
				int sum = arr[r1][c1] + arr[r2][c2] + arr[r3][c3] + arr[r4][c4];
				ret = max(ret, sum);
			}
		}
		return ret;
	}


}
int main() {

	int N = 0; int M = 0;
	vector<vector<int>> table;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < M; j++) {
			int a = 0;
			cin >> a;
			row.push_back(a);
		}
		table.push_back(row);
	}
	int ans = 0;
	for (int i = 0; i < 19; i++) {
		ans = max(ans, func(table, i, N, M));
	}
	cout << ans << endl;
	return 0;
}