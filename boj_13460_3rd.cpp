#include<bits/stdc++.h>
using namespace std;

char pan[10][10] = { 0, };
char colorToChar[2] = { 'R', 'B' };
pair<int, int> ball[2];
int N, M;
int ans = INT_MAX;

enum _ballColor {
	R,
	B
};

enum _Dir {
	UP,
	DN,
	LT,
	RT
};

int rdir[4] = { -1, 1, 0, 0 };
int cdir[4] = { 0, 0, -1, 1 };

char toChar(int color) {
	return colorToChar[color];
}

pair<int, int> moveEach(int dir, pair<int, int> const ball[2], int color, char pan[][10]) {
	char colChar = toChar(color);
	char colCharOp = toChar((color + 1) % 2);
	int r = ball[color].first;
	int c = ball[color].second;
	int rnext = r;
	int cnext = c;
	while (pan[rnext + rdir[dir]][cnext + cdir[dir]] != '#' && pan[rnext + rdir[dir]][cnext + cdir[dir]] != colCharOp) {
		rnext += rdir[dir];
		cnext += cdir[dir];
		if (pan[rnext][cnext] == 'O') break;
	}
	pan[r][c] = '.';
	if (pan[rnext][cnext] != 'O') pan[rnext][cnext] = colChar;

	return make_pair(rnext, cnext);
}

void moveAll(int dir, char pan[][10], pair<int, int> const ball[2], pair<int, int> retBox[2]) {
	int moveFirst = -1;
	switch (dir) {
		case UP:
			moveFirst = ball[R].first <= ball[B].first ? R : B;
			break;
		case DN:
			moveFirst = ball[R].first >= ball[B].first ? R : B;
			break;
		case LT:
			moveFirst = ball[R].second <= ball[B].second ? R : B;
			break;
		case RT:
			moveFirst = ball[R].second >= ball[B].second ? R : B;
			break;

	}
	retBox[moveFirst] = moveEach(dir, ball, moveFirst, pan);
	retBox[(moveFirst + 1) % 2] = moveEach(dir, ball, (moveFirst + 1) % 2, pan);

	return;
}

void dfs(int cnt, char pan[][10], pair<int, int> const ball[2]) {

	if (cnt > 10) {
		ans = min(ans, cnt);
		return;
	}

	if (cnt >= ans) {
		return;
	}

	if (pan[ball[B].first][ball[B].second] == 'O') {
		return;
	}
	else if (pan[ball[R].first][ball[R].second] == 'O') {
		ans = min(ans, cnt);
		return;
	}

	for (int i = 0; i < 4; i++) {
		char panCpy[10][10];
		memcpy(panCpy, pan, sizeof(panCpy));
		pair<int, int> retBox[2];
		moveAll(i, panCpy, ball, retBox);
		if (retBox[R].first == ball[R].first && retBox[R].second == ball[R].second && retBox[B].first == ball[B].first && retBox[B].second == ball[B].second) {
			continue;
		}
		dfs(cnt + 1, panCpy, retBox);
	}
	
}
int main() {
	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pan[i][j];
			if (pan[i][j] == 'R') {
				ball[R].first = i; ball[R].second = j;
			}
			else if (pan[i][j] == 'B') {
				ball[B].first = i; ball[B].second = j;
			}
		}
	}
	dfs(0, pan, ball);
	if (ans <= 10)cout << ans << '\n';
	else cout << -1 << '\n';
	return 0;
}
