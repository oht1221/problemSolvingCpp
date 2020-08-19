#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i < b; i++)
using namespace std;
typedef struct _fish {
	int row;
	int col;
	int dir;
	int dead;
} fish;

int ans = 0;
int init_mp[4][4] = { 0, };
fish init_fishes[16];
int move_r[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int move_c[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int shk_r = 0, shk_c = 0, shk_d = 0;
vector<int> track;

void check(int mp[][4], fish *fishes) {
	cout << '\n';
	FOR(i, 0, 4) {
		FOR(j, 0, 4) {
			if (mp[i][j] == 16) {
				cout << 'S' << " ";
				cout << shk_d + 1 << " ";
			}
			else {
				cout << mp[i][j] + 1 << " ";
				if (mp[i][j] != -1)	cout << fishes[mp[i][j]].dir + 1 << " ";
				else cout << 'X' << " ";
			}
		}
		cout << '\n';
	}
}
void move(int num, int mp[][4], fish* fishes) {
	fish* f = fishes + num;
	int r_now = f->row;
	int c_now = f->col;
	FOR(i, 0, 8) {
		int dir = (f->dir + i) % 8;
		int r_next = r_now + move_r[dir];
		int c_next = c_now + move_c[dir];
		if (r_next < 0 || r_next >= 4 || c_next < 0 || c_next >= 4 || (mp[r_next][c_next] == 16)) continue;
		else {
			f->dir = dir;
			int temp = mp[r_next][c_next];
			mp[r_next][c_next] = mp[r_now][c_now];
			f->row = r_next;
			f->col = c_next;

			mp[r_now][c_now] = temp;
			
			if (temp != -1) {
				fishes[temp].row = r_now;
				fishes[temp].col = c_now;
			}

			break;
		}
	}
}

void fishesMove(int mp[][4], fish* fishes) {
	for (int i = 0; i < 16; i++) {
		if (fishes[i].dead == 0)	move(i, mp, fishes);
	}
}

void eat(int r_target, int c_target) {
}

void checkTrack() {
	for (auto const& x : track) {
		cout << x << " ";
	}
	cout << '\n';
}
void dfs(int eaten, int init[][4], fish* f_init) {
	int mp[4][4];
	fish fishes[16];
	memcpy(mp, init, sizeof(int) * 16);
	memcpy(fishes, f_init, sizeof(fish) * 16);
	fishesMove(mp, fishes);

	int flag = 0;
	int r_eat = shk_r + move_r[shk_d];
	int c_eat = shk_c + move_c[shk_d];
	while (0 <= r_eat && r_eat < 4 && 0 <= c_eat && c_eat < 4) {
		if (mp[r_eat][c_eat] != -1) { //물고기 있으면
			flag++;
			int org_shk_r = shk_r;
			int org_shk_c = shk_c;
			int org_shk_d = shk_d;
			int num_eat = mp[r_eat][c_eat];

			fishes[num_eat].dead = 1;

			mp[r_eat][c_eat] = 16; // 상어로 바뀜
			mp[shk_r][shk_c] = -1; //상어가 있던 곳 빈자리로
			shk_r = r_eat; shk_c = c_eat;  //상어 좌표 조정
			shk_d = fishes[num_eat].dir;

			eaten += num_eat + 1;

			track.push_back(num_eat + 1);
			dfs(eaten, mp, fishes);
			track.pop_back();

			eaten -= (num_eat + 1);
			shk_d = org_shk_d; 
			shk_r = org_shk_r;	shk_c = org_shk_c; 
			mp[shk_r][shk_c] = 16;
			mp[r_eat][c_eat] = num_eat;
			fishes[num_eat].dead = 0;

		}
		r_eat += move_r[shk_d]; //다음 자리
		c_eat += move_c[shk_d];

	}
	if (flag == 0) {
		//check(mp, fishes);
		//checkTrack();
		//cout << (ans = max(eaten, ans)) << '\n';
		ans = max(eaten, ans);
	}
}
int main() {
	FOR(i, 0, 4) {
		FOR(j, 0, 4) {
			int num = 0;
			int d = 0;
			cin >> num >> d;
			init_fishes[num - 1].row = i;
			init_fishes[num - 1].col = j;
			init_fishes[num - 1].dir = d - 1;
			init_fishes[num - 1].dead = 0;
			init_mp[i][j] = num - 1;
		}
	}

	int num_target = init_mp[0][0];
	init_fishes[num_target].dead = 1;

	init_mp[0][0] = 16; // 상어로 바뀜
	shk_r = 0; shk_c = 0;  //상어 좌표 조정
	shk_d = init_fishes[num_target].dir;

	ans += num_target + 1;

	dfs(ans, init_mp, init_fishes);
	//fishesMove();
	cout << ans << '\n';
	return 0;
}
