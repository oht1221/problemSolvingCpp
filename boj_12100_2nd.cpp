#include<bits/stdc++.h>
using namespace std;
int mp[20][20] = { 0, };
int N = 0;
int ans = 0;

enum DIR {
	UP = 0,
	DOWN,
	LEFT,
	RIGHT
} ;
int rdir[4] = { -1, 1, 0, 0 };
int cdir[4] = { 0, 0, -1, 1 };

bool valid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

void move(DIR dir, int mp[][20], int r, int c, int visit[][20]) {
	int value = mp[r][c];
	mp[r][c] = 0;

	while (valid(r + rdir[dir], c + cdir[dir]) && mp[r + rdir[dir]][c + cdir[dir]] == 0){
		r += rdir[dir];
		c += cdir[dir];
	}
	mp[r][c] = value;

	if (valid(r + rdir[dir], c + cdir[dir]) && mp[r + rdir[dir]][c + cdir[dir]] == value) {
		if (valid(r + rdir[dir], c + cdir[dir]) && visit[r + rdir[dir]][c + cdir[dir]] == 0) {
			mp[r][c] = 0;
			r += rdir[dir];
			c += cdir[dir];
			mp[r][c] = value * 2;
			visit[r][c] = 1;
		}
	}
}

void moveAll (DIR dir, int mp[][20]) {

	int visit[20][20] = { 0, };

	switch (dir) {
		case UP:
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					move(dir, mp, i, j, visit);
				}
			}
			break;
		case DOWN:
			for (int i = N - 1; i >= 0; i--) {
				for (int j = 0; j < N; j++) {
					move(dir, mp, i, j, visit);
				}
			}
			break;
		case LEFT:
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					move(dir, mp, j, i, visit);
				}
			}
			break;
		case RIGHT:
			for (int i = N - 1; i >= 0; i--) {
				for (int j = 0; j < N; j++) {
					move(dir, mp, j, i, visit);
				}
			}
			break;
	}
}

int largest(int const mp[][20]) {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ret = max(ret, mp[i][j]);
		}
	}
	return ret;
}

bool mapSame(int const mp1[][20], int const mp2[][20]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mp1[i][j] != mp2[i][j]) return false;
		}
	}
	return true;
}

void dfs(int depth, int const mp[][20]) {

	if (depth >= 5) {
		ans = max(ans, largest(mp));
		return;
	}
	int mpCpy[20][20];

	memcpy(mpCpy, mp, 20 * 20 * sizeof(int));
	moveAll(UP, mpCpy);
	if(!mapSame(mp, mpCpy)) dfs(depth + 1, mpCpy);
	else ans = max(ans, largest(mp));

	memcpy(mpCpy, mp, 20 * 20 * sizeof(int));
	moveAll(DOWN, mpCpy);
	if (!mapSame(mp, mpCpy)) dfs(depth + 1, mpCpy);
	else ans = max(ans, largest(mp));

	memcpy(mpCpy, mp, 20 * 20 * sizeof(int));
	moveAll(LEFT, mpCpy);
	if (!mapSame(mp, mpCpy)) dfs(depth + 1, mpCpy);
	else ans = max(ans, largest(mp));

	memcpy(mpCpy, mp, 20 * 20 * sizeof(int));
	moveAll(RIGHT, mpCpy);
	if (!mapSame(mp, mpCpy)) dfs(depth + 1, mpCpy);
	else ans = max(ans, largest(mp));

}

int main() {
	cin >> N;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >>  mp[i][j];
		}
	}
	int i = 0;

	dfs(0, mp);
	cout << ans << '\n';

	return 0;
}

