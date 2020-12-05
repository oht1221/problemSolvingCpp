#include <bits/stdc++.h>
using namespace std;

typedef struct _SMELL {
	int sk;
	int sml;
} smell;

typedef struct _SHARK {
	int row;
	int col;
	int dir;
} shark;

enum DIR {
	UP,
	DN,
	LT,
	RT
};
smell smellMap[20][20];
vector<shark> sharks(400);

int N;
int M;
int k;
int dirs[400][4][4];
int sec = 0;
int rdir[4] = { -1, 1, 0, 0 };
int cdir[4] = { 0, 0, -1, 1 };

bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

void smellShrink(int const mp[][20]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (smellMap[i][j].sml > 0 && mp[i][j] == -1) smellMap[i][j].sml--;
		}
	}
}

void sharkMove() {
	int tempMap[20][20];
	smell mpCpy[20][20];
	memcpy(mpCpy, smellMap, sizeof(mpCpy));


	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			tempMap[i][j] = -1;
		}
	}

	for (int m = 0; m < M; m++) {
		int direction = sharks[m].dir;
		if (direction == -1) continue;

		int r = sharks[m].row;
		int c = sharks[m].col;
		int flag = 0;
		for (int i = 0; i < 4; i++) {
			int dirN = dirs[m][direction][i];
			int rnext = r + rdir[dirN];
			int cnext = c + cdir[dirN];
			
			if (isValid(rnext, cnext) && mpCpy[rnext][cnext].sml == 0) {
				flag = 1;
				if (tempMap[rnext][cnext] == -1) {
					tempMap[rnext][cnext] = m;
					sharks[m].dir = dirN;
					sharks[m].row = rnext;
					sharks[m].col = cnext;

					smell newSmell; newSmell.sk = m; newSmell.sml = k;
					smellMap[rnext][cnext] = newSmell;
				}
				else {
					sharks[m].row = -1;
					sharks[m].row = -1;
					sharks[m].dir = -1;
				}
				break;
			}
		}

		if (flag == 0) {
			for (int i = 0; i < 4; i++) {
				int dirN = dirs[m][direction][i];
				int rnext = r + rdir[dirN];
				int cnext = c + cdir[dirN];

				if (isValid(rnext, cnext) && mpCpy[rnext][cnext].sk == m) {
					flag = 1;
					if (tempMap[rnext][cnext] == -1) {
						sharks[m].dir = dirN;
						sharks[m].row = rnext;
						sharks[m].col = cnext;
						tempMap[rnext][cnext] = m;

						smell newSmell; newSmell.sk = m; newSmell.sml = k;
						smellMap[rnext][cnext] = newSmell;
					}
					else {
						sharks[m].row = -1;
						sharks[m].row = -1;
						sharks[m].dir = -1;
					}
					break;
				}
			}
		}
	}
	smellShrink(tempMap);
	sec++;
}

bool finished() {
	for (int i = 1; i < M; i++) {
		if (sharks[i].dir != -1) return false;
	}
	return true;
}
int main() {
	cin >> N >> M >> k;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			smell s;
			cin >> s.sk;
			if (s.sk != 0) {
				s.sk -= 1;
				s.sml = k;
				smellMap[i][j] = s;

				sharks[s.sk].row = i;
				sharks[s.sk].col = j;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> sharks[i].dir;
		sharks[i].dir--;
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int l= 0; l < 4; l++) {
				cin >> dirs[i][j][l];
				dirs[i][j][l] -= 1;
			}
		}
	}

	int fail = 0;
	while (!finished()) {
		if (sec >= 1000) { fail = 1; break; }
		sharkMove();
	}

	if (fail) cout << -1 << '\n';
	else cout << sec << '\n';

	return 0;
}
