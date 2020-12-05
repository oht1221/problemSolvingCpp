#include<bits/stdc++.h>
using namespace std;

int mp[50][50] = { 0, };
vector<pair<int, int>> purifier;
int R, C, T;
int rdir[4] = { -1, 0, 1, 0 };
int cdir[4] = { 0, 1, 0, -1 };

bool isValid(int r, int c) {
	return 0 <= r && r < R && 0 <= c && c < C;
}

void CCW(int r, int c) {
	int dir = 0;
	int rstart = r;
	int cstart = c;
	while (1) {
		if (isValid(r + rdir[dir], c + cdir[dir]) && r + rdir[dir] <= rstart) {
			if (mp[r + rdir[dir]][c + cdir[dir]] == -1) {
				mp[r][c] = 0;
				break;
			}
			if (mp[r][c] != -1) {
				mp[r][c] = mp[r + rdir[dir]][c + cdir[dir]];
			}
			r = r + rdir[dir];
			c = c + cdir[dir];
		}
		else {
			dir += 1;
		}
	}
}

void CW(int r, int c) {
	int dir = 2;
	int rstart = r;
	int cstart = c;
	while (1) {
		if (isValid(r + rdir[dir], c + cdir[dir]) && r + rdir[dir] >= rstart) {
			if (mp[r + rdir[dir]][c + cdir[dir]] == -1) {
				mp[r][c] = 0;
				break;
			}
			if (mp[r][c] != -1) {
				mp[r][c] = mp[r + rdir[dir]][c + cdir[dir]];
			}
			r = r + rdir[dir];
			c = c + cdir[dir];
		}
		else {
			dir = (dir - 1 + 4) % 4;
		}
	}

}
void purify() {

	CCW(purifier[0].first, purifier[0].second);
	CW(purifier[1].first, purifier[1].second);

}
bool isPurifier(int r, int c) {
	return (r == purifier[0].first && c == purifier[0].second) || (r == purifier[1].first && c == purifier[1].second);
}

void spread() {
	int plusMinus[50][50] = { 0, };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int cnt = 0;
			if (mp[i][j] != -1 && mp[i][j] != 0) {

				for (int k = 0; k < 4; k++) {
					int rtemp = i + rdir[k];
					int ctemp = j + cdir[k];
					if (isValid(rtemp, ctemp) && !isPurifier(rtemp, ctemp)) {
						cnt++;
						plusMinus[rtemp][ctemp] += mp[i][j] / 5;
					}
				}

				plusMinus[i][j] -=  (mp[i][j] / 5 * cnt);
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			mp[i][j] += plusMinus[i][j];
		}
	}
	
}

int count() {
	int sum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (mp[i][j] != -1) {
				sum += mp[i][j];
			}
		}
	}
	return sum;
}
int main() {
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == -1) {
				purifier.push_back(make_pair(i, j));
			}
		}
	}

	for (int t = 0; t < T; t++) {
		spread();
		purify();
	}

	cout << count() << '\n';
	return 0;

}
