#include<bits/stdc++.h>
using namespace std;

typedef struct _FISH {
	int r;
	int c;
	int d;
} fish ;

typedef struct _SHARK {
	int r;
	int c;
	int d;
} shark;

int ans = 0;
int score = 0;
int mp[4][4];
int rdir[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int cdir[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
shark S;
fish fishes[16];

bool isValid(int r, int c) {
	return 0 <= r && r < 4 && 0 <= c && c < 4;
}
bool isFishAlive(int n) {
	return 0 <= n && n <= 15;
}
void fishesMove(int mp[][4], fish fishes[16]) {

	for (int i = 0; i < 16; i++) {
		if (fishes[i].d == -1) continue; //죽은 물고기면 건너 뛰기
		int flag = 0;
		int rnext = 0;
		int cnext = 0;

		for (int j = 0; j < 8; j++) { //방향 정하기
			rnext = fishes[i].r + rdir[(fishes[i].d + j) % 8];
			cnext = fishes[i].c + cdir[(fishes[i].d + j) % 8];
			if (isValid(rnext, cnext) && mp[rnext][cnext] == -1) {
				int tmpc = fishes[i].c; int tmpr = fishes[i].r;
				fishes[i].d = (fishes[i].d + j) % 8;
				fishes[i].r = rnext;
				fishes[i].c = cnext;

				mp[rnext][cnext] = i; //이동 자리 채워줌
				mp[tmpr][tmpc] = -1; // 원래 자리 비움
				flag = 1;
				break;
			}
			else if (isValid(rnext, cnext) && isFishAlive(mp[rnext][cnext])) {
				int tmpc = fishes[i].c; int tmpr = fishes[i].r;
				fishes[i].d = (fishes[i].d + j) % 8;
				fishes[i].r = rnext;
				fishes[i].c = cnext;
				
				fishes[mp[rnext][cnext]].r = tmpr;
				fishes[mp[rnext][cnext]].c = tmpc;

				mp[tmpr][tmpc] = mp[rnext][cnext];
				mp[rnext][cnext] = i;

				flag = 1;
				break;
			}
		}

	}
}

void dfs(int mp[][4], fish fishes[16]) {

	int mpCpy[4][4];
	fish fCpy[16];
	memcpy(mpCpy, mp, sizeof(mpCpy));
	memcpy(fCpy, fishes, sizeof(fCpy));

	fishesMove(mpCpy, fCpy);

	int rnext = S.r + rdir[S.d];
	int cnext = S.c + cdir[S.d];
	int flag = 0;
	while (isValid(rnext, cnext) ) {
		if (isFishAlive(mpCpy[rnext][cnext])) {

			int fishN = mpCpy[rnext][cnext];
			int skTempD = S.d; int skTempR = S.r; int skTempC = S.c;
			int fishTempD = fCpy[fishN].d;

			mpCpy[S.r][S.c] = -1; // 상어 떠난 위치 -1
			mpCpy[rnext][cnext] = 16;
			S.r = rnext;
			S.c = cnext;
			S.d = fCpy[fishN].d; // 상어 상태

			fCpy[fishN].d = -1; //물고기 상태

			score += fishN + 1;

			dfs(mpCpy, fCpy);

			score -= (fishN + 1);
			fCpy[fishN].d = fishTempD;
			S.d = skTempD; S.r = skTempR; S.c = skTempC;
			mpCpy[rnext][cnext] = fishN;
			mpCpy[S.r][S.c] = 16;

			flag = 1;
		}
		rnext = rnext + rdir[S.d];
		cnext = cnext + cdir[S.d];
	}
	if (flag == 0) ans = max(ans, score);
}
int main() {
		
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;
			fishes[a - 1].r = i;
			fishes[a - 1].c = j;
			fishes[a - 1].d = b - 1;
			mp[i][j] = a - 1;
		}
	}

	S.r = 0; S.r = 0; //상어 위치
	int n = mp[0][0];  S.d = fishes[n].d; //상어 방향 
	fishes[n].d = -1; //물고기 kill
	mp[0][0] = 16; // 맵 상에 상어 위치
	score += (n + 1);
	
	dfs(mp, fishes);
	cout << ans << '\n';
	return 0;
}
