#include<bits/stdc++.h>
using namespace std;

int ans = 0;
int N = 0;
int pan[20][20] = { 0, };

int rdir[4] = { -1, 1, 0, 0 };
int cdir[4] = { 0, 0, -1, 1 };

void right(int pan[][20]) {

	int panCpy[20][20] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			panCpy[i][j] = pan[N - 1 - j][i];
		}
	}
	memcpy(pan, panCpy, sizeof(panCpy));
	return;
}
void left(int pan[][20]) {

	int panCpy[20][20] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			panCpy[i][j] = pan[j][N - 1 - i];
		}
	}

	memcpy(pan, panCpy, sizeof(panCpy));
	return;
}
void upsideDown(int pan[][20]) {

	int panCpy[20][20] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			panCpy[i][j] = pan[N - 1 - i][N - 1 - j];
		}
	}
	memcpy(pan, panCpy, sizeof(panCpy));
	return;
}
enum _DIR {
	UP,
	DN,
	LT,
	RT
};

bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

void merge(int pan[][20]) {
	int merged[20][20] = { 0, };
	for (int c = 0; c < N; c++) {
		for (int r = 0; r < N; r++) {
			int val = pan[r][c];
			int rnext = r;
			int flag = 0;
			while (isValid(rnext - 1, c)) {
				if (pan[rnext - 1][c] != 0) {
					if (pan[rnext - 1][c] == val && merged[rnext - 1][c] == 0) {
						merged[rnext - 1][c] = 1;
						pan[r][c] = 0;
						pan[rnext - 1][c] = val * 2; // double up
						flag = 1;
					}
					else {
						pan[r][c] = 0;
						pan[rnext][c] = val; //moved
						flag = 1;
					}
					break;
				}
				else {
					rnext = rnext - 1;
				}
			}
			if (flag == 0) {
				pan[r][c] = 0;
				pan[rnext][c] = val;
			}
		}
	}
}

void tilt(int pan[][20], int dir) {

	switch (dir) {
		case UP:
			merge(pan);
			break;
		case DN:
			upsideDown(pan);
			merge(pan);
			upsideDown(pan);
			break;
		case LT:
			right(pan);
			merge(pan);
			left(pan);
			break;
		case RT:
			left(pan);
			merge(pan);
			right(pan);
			break;
	}
}
int findMax(int pan[][20]) {
	int Max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Max = max(Max, pan[i][j]);
		}
	}
	return Max;
}
void dfs(int cnt, int pan[][20]) {

	if (cnt == 5) {
		ans = max(findMax(pan), ans);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int panCpy[20][20];
		memcpy(panCpy, pan, sizeof(panCpy));
		tilt(panCpy, i);
		dfs(cnt + 1, panCpy);
	}
}
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> pan[i][j];
		}
	}

	dfs(0, pan);

	cout << ans << '\n';

	return 0;

}
