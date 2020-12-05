#include<bits/stdc++.h>
using namespace std;
int N = 0;
int mp[20][20];
int M = 0;
int seconds = 0;
int shkSize = 2;
int eaten = 0;
int shkR;
int shkC;
int rdir[4] = { -1, 0, 0, 1 };
int cdir[4] = { 0, -1, 1, 0 };

bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

bool win(int r1, int c1, int r2, int c2) {
	if (r1 < r2) return true;
	else if (r1 == r2) {
		if (c1 < c2) return true;
	}
	return false;
}
int bfs(int r, int c) {
	queue<pair<int, int>> Qcell;
	queue<int> Qdist;
	int visit[20][20] = { 0, };
	int eatenR = N;
	int eatenC = N;
	int eatenDist = INT_MAX;

	Qcell.push(make_pair(r, c));
	Qdist.push(0);
	visit[r][c] = 1;

	int flag = 0;

	while (!Qcell.empty()) {
		pair<int, int> cell = Qcell.front(); Qcell.pop();
		int dist = Qdist.front(); Qdist.pop();

		if (mp[cell.first][cell.second] != 0 && mp[cell.first][cell.second] < shkSize) {
			if (eatenDist < dist) break;
			flag = 1;
			if (win(cell.first, cell.second, eatenR, eatenC)) {
				eatenR = cell.first;
				eatenC = cell.second;
				eatenDist = dist;
			}
		}

		else {
			for (int i = 0; i < 4; i++) {
				if (isValid(cell.first + rdir[i], cell.second + cdir[i])) {
					if (mp[cell.first + rdir[i]][cell.second + cdir[i]] <= shkSize) {
						if (visit[cell.first + rdir[i]][cell.second + cdir[i]] == 0) {
							Qcell.push(make_pair(cell.first + rdir[i], cell.second + cdir[i]));
							visit[cell.first + rdir[i]][cell.second + cdir[i]] = 1;
							Qdist.push(dist + 1);
						}
					}
				}
			}
		}
	}

	if (flag == 1) {
		eaten++;
		if (eaten == shkSize) {
			eaten = 0;
			shkSize++;
		}
		mp[eatenR][eatenC] = 0;
		shkR = eatenR; shkC = eatenC;
		seconds += eatenDist;
	}

	return flag;
}
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 9) {
				shkR = i; shkC = j;
				mp[i][j] = 0;
			}
		}
	}

	while (1) {
		int moved = bfs(shkR, shkC);
		if (moved == 0) break;
	}

	cout << seconds << '\n';
	return 0;
}
