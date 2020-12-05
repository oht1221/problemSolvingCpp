#include<bits/stdc++.h>
using namespace std;
char mp[10][10] = { 0, };
int N, M;

pair<int, int> posR;
pair<int, int> posB;
pair<int, int> posO;

int ans = 11;
int rdir[4] = { -1, 1, 0, 0 };
int cdir[4] = { 0, 0, -1, 1 };

enum Dir {
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
};

void init() {
	mp[10][10] = { 0, };
	N, M = 0;
	ans = 11;
}
bool isR(pair<int, int> pos) {
	return pos.first == posR.first && pos.second == posR.second;
}

bool isB(pair<int, int> pos) {
	return pos.first == posB.first && pos.second == posB.second;
}

bool isO(pair<int, int> pos) {
	return pos.first == posO.first && pos.second == posO.second;
}

pair<int, int> move(Dir dir, pair<int, int> pos, char c) {
	int cnt = 0;
	while (mp[pos.first + rdir[dir]][pos.second + cdir[dir]] != '#') {
		pos.first += rdir[dir];
		pos.second += cdir[dir];
		cnt++;
		if (isO(make_pair(pos.first, pos.second))) break;
	}
	return make_pair(pos.first, pos.second);
}


bool samePosition(pair<int, int> pos1, pair<int, int> pos2) {
	return pos1.first == pos2.first && pos1.second == pos2.second;
}

int moveTwoBalls(Dir dir, pair<int, int> posR, pair<int, int> posB, pair<int, int> & movedR, pair<int, int> & movedB) {

	movedR = move(dir, posR, 'R');
	movedB = move(dir, posB, 'B');
	
	if (isO(movedB)) return 1;
	else if (isO(movedR)) return 2;

	switch (dir) {
		case UP:
			if (samePosition(movedR, movedB)) {
				if (posR.first > posB.first) {
					movedR.first++;
				}
				else if (posR.first < posB.first) {
					movedB.first++;
				}
			}
			break;
		case DOWN:
			if (samePosition(movedR, movedB)) {
				if (posR.first < posB.first) {
					movedR.first--;
				}
				else if (posR.first > posB.first) {
					movedB.first--;
				}
			}
			break;
		case LEFT:
			if (samePosition(movedR, movedB)) {
				if (posR.second < posB.second) {
					movedB.second++;
				}
				else if (posR.second > posB.second) {
					movedR.second++;
				}
			}
			break;
		case RIGHT:
			if (samePosition(movedR, movedB)) {
				if (posR.second < posB.second) {
					movedR.second--;
				}
				else if (posR.second > posB.second) {
					movedB.second--;
				}
			}
			break;
	}

	return 0;
}

void dfs(int depth, pair<int, int> posR, pair<int,int> posB) {
	if (depth >= ans) return;
	if (isO(posR)) {
		ans = min(ans, depth);
		return;
	}
	pair<int, int> movedR;
	pair<int, int> movedB;
	
	int result = moveTwoBalls(UP, posR, posB, movedR, movedB);
	if (result != 1) {
		if (!samePosition(posR, movedR) || !samePosition(posB, movedB)) {
			dfs(depth + 1, movedR, movedB);
		}
	}

	result = moveTwoBalls(DOWN, posR, posB, movedR, movedB);
	if (result != 1) {
		if (!samePosition(posR, movedR) || !samePosition(posB, movedB)) {
			dfs(depth + 1, movedR, movedB);
		}
	}

	result = moveTwoBalls(LEFT, posR, posB, movedR, movedB);
	if (result != 1) {
		if (!samePosition(posR, movedR) || !samePosition(posB, movedB)) {
			dfs(depth + 1, movedR, movedB);
		}
	}

	result = moveTwoBalls(RIGHT, posR, posB, movedR, movedB);
	if (result != 1) {
		if (!samePosition(posR, movedR) || !samePosition(posB, movedB)) {
			dfs(depth + 1, movedR, movedB);
		}
	}

}

int main() {
	//init();
	cin >> N; 
	cin >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 'R') posR = make_pair(i, j);
			else if (mp[i][j] == 'B') posB = make_pair(i, j);
			else if (mp[i][j] == 'O') posO = make_pair(i, j);
		}
	}

	
	dfs(0, posR, posB);
	
	if (ans == 11) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}
