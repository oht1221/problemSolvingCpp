#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> pan;
int N;
int M;
int dir;
int r, c;

int rdir[4] = { -1, 0, 1, 0 };
int cdir[4] = { 0, 1, 0 , -1 };

int countClean(vector<vector<int>> const& p) {
	int cnt = 0;
	for (auto const & row : p) {
		cnt += count(row.begin(), row.end(), 2);
	}
	return cnt;
}
bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < M;
}
int main() {
	cin >> N >> M;
	cin >> r >> c >> dir;

	vector<int> row(M, 0);
	pan.assign(N, row);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pan[i][j];
		}
	}
	int rtCnt = 0;
	int flag = 1;
	while (flag) {
		pan[r][c] = 2; //청소
		int moved = 0;
		int tnCnt = 0;
		while (moved == 0) {
			int dnext = (dir - 1 + 4) % 4; //왼쪽으로
			int rnext = r + rdir[dnext];
			int cnext = c + cdir[dnext];
			if (isValid(rnext, cnext) && pan[rnext][cnext] == 0) {
				dir = dnext;
				r = rnext;
				c = cnext;
				moved = 1;
			}
			else {
				dir = dnext;
				tnCnt++;
				if (tnCnt == 4) {
					int opDir = (dir + 2) % 4;
					int rOp = r + rdir[opDir];
					int cOp = c + cdir[opDir];

					if (!isValid(rOp, cOp) || (isValid(rOp, cOp) && pan[rOp][cOp] == 1)) {
						flag = 0;
						break;
					}
					else {
						r = r + rdir[opDir];
						c = c + cdir[opDir];
						tnCnt = 0;
					}
				}
			}
		}
	}

	cout << countClean(pan) << '\n';
	return 0;
}

