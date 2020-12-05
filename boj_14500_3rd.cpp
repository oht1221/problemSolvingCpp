#include<bits/stdc++.h>
using namespace std;
int N = 0; 
int M = 0;
int ans = 0;
vector<vector<pair<int, int>>> tetro;
vector<vector<int>> pan;

bool isValid(int r, int c, int R, int C) {
	return 0 <= r && r < R && 0 <= c && c < C;
}
int sum(int r, int c, vector<vector<int>> const& p, int n) {
	int s = 0;
	int R = p.size(); int C = p[0].size();
	for (int i = 0; i < 4; i++) {
		if (!isValid(r + tetro[n][i].first, c + tetro[n][i].second, R, C)) {
			s = 0; break;
		}
		s += p[r + tetro[n][i].first][c + tetro[n][i].second];
	}
	return s;
}
void findMaxSum(vector<vector<int>> const &p, int n) {
	int R = p.size(); int C = p[0].size();

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			ans = max(sum(i, j, p, n), ans);
		}
	}
}

vector<vector<int>> Right(vector<vector<int>> const& p) {
	vector<vector<int>> newPan;

	int msize = p.size();
	int nsize = p[0].size();

	vector<int> a(msize, 0);
	newPan.assign(nsize, a);

	for (int i = 0; i < nsize; i++) {
		for (int j = 0; j < msize; j++) {
			newPan[i][j] = p[msize - 1 - j][i];
		}
	}

	return newPan;
}

vector<vector<int>> symmetry(vector<vector<int>> const& p) {
	vector<vector<int>> newPan;

	int nsize = p.size();
	int msize = p[0].size();

	vector<int> a(msize, 0);
	newPan.assign(nsize, a);

	for (int i = 0; i < nsize; i++) {
		for (int j = 0; j < msize; j++) {
			newPan[i][j] = p[i][msize - 1 - j];
		}
	}

	return newPan;
}
int main() {
	cin >> N >> M;

	vector<int> a(M, 0);
	pan.assign(N, a);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pan[i][j];
		}
	}
	
	vector<pair<int, int>> dummy;
	tetro.assign(5, dummy);
	tetro[0].push_back(make_pair(0, 0));
	tetro[0].push_back(make_pair(0, 1));
	tetro[0].push_back(make_pair(0, 2));
	tetro[0].push_back(make_pair(0, 3));

	tetro[1].push_back(make_pair(0, 0));
	tetro[1].push_back(make_pair(1, 0));
	tetro[1].push_back(make_pair(0, 1));
	tetro[1].push_back(make_pair(1, 1));

	tetro[2].push_back(make_pair(0, 0));
	tetro[2].push_back(make_pair(1, 0));
	tetro[2].push_back(make_pair(2, 0));
	tetro[2].push_back(make_pair(2, 1));


	tetro[3].push_back(make_pair(0, 0));
	tetro[3].push_back(make_pair(1, 0));
	tetro[3].push_back(make_pair(1, 1));
	tetro[3].push_back(make_pair(2, 1));

	tetro[4].push_back(make_pair(0, 0));
	tetro[4].push_back(make_pair(0, 1));
	tetro[4].push_back(make_pair(0, 2));
	tetro[4].push_back(make_pair(1, 1));

	vector<vector<int>> right = Right(pan);
	vector<vector<int>> rightSym = symmetry(right);

	vector<vector<int>> upsideDown = Right(right);
	vector<vector<int>> upsideDownSym = symmetry(upsideDown);

	vector<vector<int>> left = Right(upsideDown);
	vector<vector<int>> leftSym = symmetry(left);

	vector<vector<int>> sym = symmetry(pan);


	for (int i = 0; i < 5; i++) {
		findMaxSum(pan, i);
		findMaxSum(right, i);
		findMaxSum(rightSym, i);
		findMaxSum(upsideDown, i);
		findMaxSum(upsideDownSym, i);
		findMaxSum(left, i);
		findMaxSum(leftSym, i);
		findMaxSum(sym, i);
	}
	
	cout << ans << '\n';
	return 0;
}
