#include<vector>
#include<map>
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int R, C, M;
int pan[100][100];
int fishman = -1;
int ans = 0;
typedef struct _SHARK {
	int r;
	int c;
	int dir;
	int vel;
	int size;
} shark;

map<int, int> dirChange;
vector<shark> S;

int rdir[4] = { -1, 1, 0, 0 };
int cdir[4] = { 0, 0, 1, -1 };

void fishing(int baseC) {

	for (int i = 0; i < R; i++) {
		if (pan[i][baseC] != 0) {
			int sharkN = pan[i][baseC];
			pan[i][baseC] = 0;
			ans += S[sharkN - 1].size;
			S[sharkN - 1].size = -1; //죽음
			
			break; // 잡았으면 끝
		}
	}
}
bool isValid(int r, int c) {
	return 0 <= r && r < R && 0 <= c && c < C;
}
void fishMove() {
	for (int i = 0; i < S.size(); i++) {
		if (S[i].size != -1) {
			int dist = S[i].vel;
			int size = S[i].size;
			int r = S[i].r;
			int c = S[i].c;
			int dir = S[i].dir;
			int L = (dir == 0 || dir == 1) ? (R - 1) * 2 : (C - 1) * 2;
		
			dist = dist % L;

			for (int j = 0; j < dist; j++) {
				int rnext = r + rdir[dir];
				int cnext = c + cdir[dir];
				if (isValid(rnext, cnext)) {
					r = rnext; c = cnext;
				}
				else {
					dir = dirChange[dir];
					j--;
				}
			}
			if (pan[r][c] == 0) {
				pan[r][c] = i + 1;
				S[i].r = r;
				S[i].c = c;
				S[i].dir = dir;
			}
			else {
				int competeN = pan[r][c];
				if (S[competeN - 1].size < size) {
					pan[r][c] = i + 1;
					S[i].r = r;
					S[i].c = c;
					S[i].dir = dir;
					S[competeN - 1].size = -1;
				}
				else {
					S[i].size = -1;
				}
			}
		}
	}
}
bool noFish() {
	for (int i = 0; i < M; i++) {
		if (S[i].size != -1) return false;
	}
	return true;
}
int main() {

	cin >> R >> C >> M;
	dirChange[0] = 1;
	dirChange[1] = 0;
	dirChange[3] = 2;
	dirChange[2] = 3;

	for(int i = 0; i < M; i++){

		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		shark sk;
		sk.dir = d - 1;
		sk.vel = s;
		sk.r = r - 1;
		sk.c = c - 1;
		sk.size = z;
		S.push_back(sk);
		pan[r - 1][c - 1] = i + 1;
	}
	

	while (++fishman < C ) {
		if( noFish() )break;
		fishing(fishman);
		
		for (auto sk : S) {
			pan[sk.r][sk.c] = 0;
		}
		fishMove();
	}

	cout << ans << endl;
	return 0;
}

