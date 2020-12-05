#include<bits/stdc++.h>
using namespace std;
int N = 0;
int M = 0;
int K = 0;
int A[10][10] = { 0, };
int nut[10][10] = { 0, };
vector<int> trees[10][10];
int rdir[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int cdir[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };



bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;

}
void aging() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (!trees[i][j].empty()) {
				sort(trees[i][j].begin(), trees[i][j].end());
				int nutSum = 0;
				for (int t = 0; t < trees[i][j].size(); t++) {
					if (nut[i][j] - trees[i][j][t] >= 0) {
						nut[i][j] -= trees[i][j][t];
						trees[i][j][t]++;
					}
					else {
						nutSum += trees[i][j][t] / 2;
						trees[i][j][t] = 0;
					}
				}
				nut[i][j] += nutSum;
			}
		}
	}
}

void treeDie() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!trees[i][j].empty()) {
				int s = trees[i][j].size();
				for (int t = s - 1; t >= 0; t--) {
					if (trees[i][j][t] == 0) {
						trees[i][j].pop_back();
					}
				}
			}
		}
	}
}

void spread() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!trees[i][j].empty()) {
				for (int t = 0; t < trees[i][j].size(); t++) {
					if (trees[i][j][t] % 5 == 0) {
						for (int l = 0; l < 8; l++) {
							if (isValid(i + rdir[l], j + cdir[l])) {
								trees[i + rdir[l]][j + cdir[l]].push_back(1);
							}
						}
					}
				}
			}
		}
	}
}

void nutRefill() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			nut[i][j] += A[i][j];
		}
	}
}
int sum() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ret += trees[i][j].size();
		}
	}
	return ret;
}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			nut[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, age; cin >> x >> y >> age;
		trees[x - 1][y - 1].push_back(age);
	}

	int ans = 0;
	for (int i = 0; i < K; i++) {
		aging();
		treeDie();
		spread();
		nutRefill();

	}

	ans = sum();

	cout << ans << '\n';
	return 0;
}

