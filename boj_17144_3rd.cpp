#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

int R;
int C;
int T;

int pan[50][50];
vector<pair<int, int> >purifier;
int rdir[4] = { -1, 0, 1, 0};
int cdir[4] = { 0, 1, 0, -1};

bool isValid(int r, int c) {
	return 0 <= r && r < R && 0 <= c && c < C;
}
void spread() {

	int result[50][50] = { 0, };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (pan[i][j] == -1 || pan[i][j] / 5 == 0) continue;

			int dust = pan[i][j];
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int rnext = i + rdir[k];
				int cnext = j + cdir[k];

				if (isValid(rnext, cnext) && pan[rnext][cnext] != -1) {
					cnt++;
					result[rnext][cnext] += (dust / 5);
				}
			}

			result[i][j] -= (dust / 5) * cnt;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			pan[i][j] += result[i][j];
		}
	}
}


void purify() {

	pair<int, int> p1 = purifier[0];
	pair<int, int> p2 = purifier[1];

	int dir = 0;
	int p1R = p1.first;
	int r = p1.first - 1;
	int c = p1.second;

	while (pan[r][c] != -1) {
		int rprev = r + rdir[dir];
		int cprev = c + cdir[dir];
		if (isValid(rprev, cprev) && rprev <= p1R) {
			if (pan[rprev][cprev] == -1) break;
			pan[r][c] = pan[rprev][cprev];
			pan[rprev][cprev] = 0;
			r = rprev;
			c = cprev;
		}
		else {
			dir = (dir + 1) % 4;
		}
	}

	r = p2.first + 1;
	c = p2.second;
	dir = 2;
	int p2R = p2.first;

	while (pan[r][c] != -1) {
		int rprev = r + rdir[dir];
		int cprev = c + cdir[dir];
		if (isValid(rprev, cprev) && rprev >= p2R) {
			if (pan[rprev][cprev] == -1) break;
			pan[r][c] = pan[rprev][cprev];
			pan[rprev][cprev] = 0;
			r = rprev;
			c = cprev;
		}
		else {
			dir = (dir - 1 + 4) % 4;
		}
	}
}
int main() {
	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> pan[i][j];
			if (pan[i][j] == -1)purifier.push_back(make_pair(i, j));
		}
	}

	while (T--) {
		spread();
		purify();
	}

	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (pan[i][j] == -1)continue;
			sum += pan[i][j];
		}
	}
	
	cout << sum << endl;
	return 0;
}
