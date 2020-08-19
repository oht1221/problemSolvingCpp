#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ans = 100;
int N, M, H;

bool checkComplete(vector<vector<int>>  const& ladders) {
	static int cnt = 0;
	//cout << ++cnt << endl;
	for (int i = 0; i < N; i++) {
		int position = i;
		for (int j = 0; j < H; j++) {
			if (position - 1 >= 0) {
				if (ladders[j][position - 1] == 1) {
					position = position - 1; continue;
				}
			}

			if (position < N - 1) {
				if (ladders[j][position] == 1) {
					position = position + 1; continue;
				}
			}
		}
		if (position != i) return false;
	}
	return true;
}

int dfs(int max, int number, vector<vector<int>> &ladders, int r, int c) {


	if (number >= ans) {
		return true;
	}

	//cout << ans << " " << number << endl;

	if(number != 0) ladders[r][c] = 1; //¼±ÅÃ

	bool completed = checkComplete(ladders);
	if (completed == true) {
		//cout << "true!" << endl;
		ans = min(ans, number);
		//printState(ladders);
		return true;
	}

	if (number == max) {
		return false;
	}

	else {

		bool no_need = false;/*
		if (r == -1) {
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < N - 1; j++) {
					int ladder = ladders[i][j];
					if (ladder == 0) {
						if (j - 1 >= 0) {
							if (ladders[i][j - 1] == 1) continue;
						}
						if (j + 1 < N - 1) {
							if (ladders[i][j + 1] == 1) continue;
						}
						no_need = dfs(max, number + 1, ladders, i, j); ladders[r][c] = 0;
						if (no_need) {
							break;
						}
					}
				}
				if (no_need) {
					break;
				}
			}
		}*/

			for (int i = r; i < H; i++) {
				int j = c ? 0 : i == r;
				for (; j < N - 1; j++) {
					int ladder = ladders[i][j];
					if (ladder == 0) {
						if (j - 1 >= 0) {
							if (ladders[i ][j - 1] == 1) continue;
						}
						if (j + 1 < N - 1) { 
							if (ladders[i][j + 1] == 1) continue;
						}
						no_need = dfs(max, number + 1, ladders, i, j); ladders[i][j] = 0;
						if (no_need) {
							break;
						}
					}
				}
				if (no_need) {
					break;
				}
			}
		return false;
	}
}


int main() {
	cin >> N >> M >> H;
	vector<vector<int>> L(H, vector<int>(N - 1, 0));

	for (int i = 0; i < M; i++) {
		int r, c;
		cin >> r >> c;
		L[r - 1][c - 1] = 1;
	}

	dfs(3, 0, L, 0, 0);
	if (ans == 100) ans = -1;
	cout << ans << endl;
	return 0;
}
