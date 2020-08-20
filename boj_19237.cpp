#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; i++)

int move_r[4] = { -1, 1, 0, 0 }; // À§ ¾Æ·¡ ÁÂ ¿ì
int move_c[4] = { 0, 0, -1, 1 };

int N, M, k;

enum direction {
	UP,
	DOWN,
	LEFT, 
	RIGHT,
};

typedef struct _sm {
	int num;
	int duration;
} smell;

typedef struct _sk {
	int num;
	int dir;
	int prior[4][4];
} shark;


vector<shark> sharks;
int sharkMap[20][20];
smell smellMap[20][20];

void checkShark() {
	FOR(i, 0, N) {
		FOR(j, 0, N) cout << (sharkMap[i][j] + 1) << " ";
		cout << '\n';
	}

	/*
	FOR(i, 0, M) {
		cout << (sharks[i].dir + 1) << " ";
	}

	cout << '\n';

	FOR(i, 0, M) {
		FOR(j, 0, 4) {
			FOR(l, 0, 4) cout << (sharks[i].prior[j][l] + 1) << " ";
			cout << '\n';
		}
	}
	*/
}
void checkSmell() {
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (smellMap[i][j].duration != 0) {
				cout << smellMap[i][j].num << " " << smellMap[i][j].duration << " ";
			}
			else cout << 0 << " " << 0 << " ";
		}
		cout << '\n';
	}
}

void spreadSmell() {
	FOR(i, 0, N) FOR(j, 0, N) {
		if (sharkMap[i][j] != -1) {
			int num = sharkMap[i][j];
			smell sm;
			sm.num = num;
			sm.duration = k;
			smellMap[i][j] = sm;
		}
	}
}

void shrinkSmell() {
	FOR(i, 0, N) FOR(j, 0, N) {
		if (smellMap[i][j].num != -1) {
			smellMap[i][j].duration--;
			if (smellMap[i][j].duration == 0) {
				smellMap[i][j].num = -1;
			}
		}
	}
}
bool inBoundary(int r, int c) {
	return (0 <= r && r < N && 0 <= c && c < N);
 }

void chooseCoord(int r, int c, int* coord) {
	int num = sharkMap[r][c];
	FOR(i, 0, 3) coord[i] = -1;
	int dir = sharks[num].dir;
	int* const p = sharks[num].prior[dir];
	int flag = 0;
	FOR(i, 0, 4) {
		int r_next = r + move_r[p[i]];
		int c_next = c + move_c[p[i]];
		if (inBoundary(r_next, c_next)) {
			if (smellMap[r_next][c_next].num == -1) {
				flag = 1;
				coord[0] = r_next; coord[1] = c_next;
				coord[2] = p[i];
				break;
			}
		}
	}

	if (flag == 0) {
		FOR(i, 0, 4) {
			int r_next = r + move_r[p[i]];
			int c_next = c + move_c[p[i]];
			if (inBoundary(r_next, c_next)) {
				if (smellMap[r_next][c_next].num == num) {
					flag = 1;
					coord[0] = r_next; coord[1] = c_next;
					coord[2] = p[i];
					break;
				}
			}
		}
	}

}

void sharkMove(int r, int c, int dir, int num) {
	//int coordinate[3];
	//chooseCoord(r, c, coordinate);
	//int r_next = coordinate[0]; int c_next = coordinate[1];
	//int dir = coordinate[2];
	if (inBoundary(r, c)) {
		if (sharkMap[r][c] != -1) {
			int winner = min(sharkMap[r][c], num);
			if (winner == num) {
				sharkMap[r][c] = num;
				sharks[num].dir = dir;
			}
		}
		else {
			sharkMap[r][c] = num;
			sharks[num].dir = dir;
		}
	}
}

void allMove() {
	vector<int> visit(M, 0);
	vector<int> row;
	vector<int> col;
	vector<int> nums;
	vector<int> dir;
	int cnt = 0;
	FOR(i, 0, N) FOR(j, 0, N) {
		int num = sharkMap[i][j];
		if (num != -1) {
			if (visit[num] == 0) {
				int coordinate[3];
				chooseCoord(i, j, coordinate);
				row.push_back(coordinate[0]);
				col.push_back(coordinate[1]);
				dir.push_back(coordinate[2]);
				nums.push_back(num);
				sharkMap[i][j] = -1;
				visit[num] = 1;
				cnt++;
			}
		}
	}
	FOR(i, 0, cnt) sharkMove(row[i], col[i], dir[i], nums[i]);
}

bool onlyOneLeft() {
	bool ret = true;
	FOR(i, 0, N) FOR(j, 0, N) {
		if (sharkMap[i][j] != 0 && sharkMap[i][j] != -1) {
			ret = false;
			break;
		}
	}
	return ret;
}
int main() {
	cin >> N >> M >> k;
	FOR(i, 0, N) FOR(j, 0, N) {
		cin >> sharkMap[i][j];
		sharkMap[i][j]--;
	}

	smell sm;
	sm.num = -1; sm.duration = 0;

	FOR(i, 0, N) FOR(j, 0, N) {
		smellMap[i][j] = sm;
	}

	FOR(i, 0, M) {
		shark sk;
		sk.num = i; 
		cin >> sk.dir; sk.dir--;
		sharks.push_back(sk);
	}

	FOR(i, 0, M) FOR(j, 0, 4) FOR(l, 0, 4) {
		cin >> sharks[i].prior[j][l];
		sharks[i].prior[j][l]--;
	}

	spreadSmell(); 
	int sec = 1;
	while(sec) {
		allMove();
		shrinkSmell();
		spreadSmell();
		if (onlyOneLeft()) {
			//checkShark();
			cout << sec << '\n';
			break;
		}
		if (sec == 1000) {
			cout << "-1" << '\n';
			break;
		}
		sec++;
	}
	//checkSmell();

	return 0;
}
