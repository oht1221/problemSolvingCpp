#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i < b ; i++)
#define FOR_D(i, a, b) for(int i = a; i >= b ; i--)
#define VI vector<int>

const char nl = '\n';
using namespace std;
int dirr[4] = { 0, 0, -1, 1 };
int dirc[4] = { 1, -1, 0, 0 };

typedef struct _hrs{
	int r;
	int c;
	int dir;
} hrs;
int mp[12][12] = { 0, };
hrs hrses[10];
VI stk[12][12];
int N, K = 0;

void check() {
	cout << nl;
	FOR(i, 0, N) {
		FOR(j, 0, N) cout << mp[i][j] << " ";
		cout << nl;
	}

	FOR(i, 0, K) {
		cout << hrses[i].r << " " << hrses[i].c << " " << hrses[i].dir << nl;
	}

	FOR(i, 0, K) {
		int r = hrses[i].r; int c = hrses[i].c;
		cout << r << " " << c << " " << stk[r][c][0] << nl;
	}
}

void move(int no, int sec) {
	vector<int> lst;
	int len = stk[hrses[no].r][hrses[no].c].size();
	FOR(i, 0, len) {
		if (stk[hrses[no].r][hrses[no].c][i] == no) {
			FOR(j, i, len) { lst.push_back(stk[hrses[no].r][hrses[no].c][j]); }
			break;
		}
	}
	int nr = hrses[no].r + dirr[hrses[no].dir];
	int nc = hrses[no].c + dirc[hrses[no].dir];
	int pr = hrses[no].r; int pc = hrses[no].c;
	int color = 0;
	if (nr >= N || nr < 0 || nc < 0 || nc >= N) color = 2;
	else color = mp[nr][nc];
	
	if (color == 0) {
		int l = lst.size();
		FOR(i, 0, l) { hrses[lst[i]].r = nr, hrses[lst[i]].c = nc; stk[nr][nc].push_back(lst[i]); }
		
		int cnt = lst.size();
		FOR(j, 0, cnt) stk[pr][pc].pop_back();
	}
	else if (color == 1) {
		int l = lst.size();
		FOR_D(i, l - 1, 0) { hrses[lst[i]].r = nr, hrses[lst[i]].c = nc; stk[nr][nc].push_back(lst[i]); }
		int cnt = lst.size();
		FOR(j, 0, cnt) stk[pr][pc].pop_back();
	}
	else if (color == 2 && sec == 0) {
		if (hrses[no].dir == 0) {
			hrses[no].dir = 1;
		}
		else if (hrses[no].dir == 1) {
			hrses[no].dir = 0;
		}
		else if (hrses[no].dir == 2) {
			hrses[no].dir = 3;
		}
		else if (hrses[no].dir == 3) {
			hrses[no].dir = 2;
		}
;		move(no, sec + 1);
	}

	return;
}

bool isOver() {
	bool ret = false;
	FOR(i, 0, N) FOR(j, 0, N) {
		if (stk[i][j].size() >= 4) ret = true;
	}
	return ret;
}
int main() {
	cin >> N >> K;
	FOR(i, 0, N) FOR(j, 0, N) cin >> mp[i][j];
	FOR(i, 0, K) {
		int r, c, dir; cin >> r >> c >> dir;
		hrses[i].r = r - 1; hrses[i].c = c - 1; hrses[i].dir = dir - 1;
		stk[hrses[i].r][hrses[i].c].push_back(i);
	}

	int tn = 1;
	while (tn <= 1000) {
		int flag = 0;
		FOR(i, 0, K) {
			move(i, 0);
			if (isOver()) { flag = 1; break; }
		}
		if (flag == 1) break;
		tn++;
	}

	if (tn <= 1000) cout << tn;
	else cout << -1;

	return 0;
}
