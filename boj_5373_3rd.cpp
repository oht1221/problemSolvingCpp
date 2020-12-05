#include <bits/stdc++.h>
using namespace std;
void func1(char cube[][9]) {
	char tmp1 = cube[2][3]; char tmp2 = cube[2][6];
	cube[2][3] = cube[2][7]; cube[2][6] = cube[2][8];
	cube[2][7] = cube[2][5]; cube[2][8] = cube[2][2];
	cube[2][5] = cube[2][1]; cube[2][2] = cube[2][0];
	cube[2][1] = tmp1;	cube[2][0] = tmp2;
}

void func2(char cube[][9]) {
	char tmp1 = cube[0][6]; char tmp2 = cube[0][7]; char tmp3 = cube[0][8];
	cube[0][6] = cube[1][8]; cube[0][7] = cube[1][5]; cube[0][8] = cube[1][2];
	cube[1][2] = cube[3][0]; cube[1][5] = cube[3][1]; cube[1][8] = cube[3][2];
	cube[3][0] = cube[4][6]; cube[3][1] = cube[4][3]; cube[3][2] = cube[4][0];
	cube[4][0] = tmp1; cube[4][3] = tmp2; cube[4][6] = tmp3;
}

void rt(char cube[][9], char dir) {
	for (int i = 0; i < 3; i++) {
		if (dir == '+' && i == 1) break;
		func1(cube);
	}

	for (int i = 0; i < 3; i++) {
		if (dir == '+' && i == 1) break;
		func2(cube);
	}

}

void trans(char cube[][9], char side, map<char, int> &sts) {
	int idx = sts[side];
	char tmp[6][9]; memcpy(tmp, cube, sizeof(tmp));

	int deltaU = sts['U'] - idx;
	memcpy(cube[(2 + deltaU + 6) % 6], tmp[(idx + deltaU + 6) % 6], sizeof(cube[0]));
	int deltaL = sts['L'] - idx;
	memcpy(cube[(2 + deltaL + 6) % 6], tmp[(idx + deltaL + 6) % 6], sizeof(cube[0]));
	int deltaF = sts['F'] - idx;
	memcpy(cube[(2 + deltaF + 6) % 6], tmp[(idx + deltaF + 6) % 6], sizeof(cube[0]));
	int deltaD = sts['D'] - idx;
	memcpy(cube[(2 + deltaD + 6) % 6], tmp[(idx + deltaD + 6) % 6], sizeof(cube[0]));
	int deltaR = sts['R'] - idx;
	memcpy(cube[(2 + deltaR + 6) % 6], tmp[(idx + deltaR + 6) % 6], sizeof(cube[0]));
	int deltaB = sts['B'] - idx;
	memcpy(cube[(2 + deltaB + 6) % 6], tmp[(idx + deltaB + 6) % 6], sizeof(cube[0]));
	
	sts['U'] = (2 + deltaU + 6) % 6; sts['F'] = (2 + deltaF + 6) % 6;
	sts['L'] = (2 + deltaL + 6) % 6; sts['D'] = (2 + deltaD + 6) % 6;
	sts['R'] = (2 + deltaR + 6) % 6; sts['B'] = (2 + deltaB + 6) % 6;

}	
int main() {
	int T = 0;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int n = 0;
		map<char, int> status;
		status['U'] = 0; status['L'] = 1; status['F'] = 2;
		status['D'] = 3; status['R'] = 4; status['B'] = 5;

		char cube[6][9] = { { 'w', 'w','w','w','w','w','w','w','w'},
							{ 'g', 'g','g','g','g','g','g','g','g'},
							{ 'r', 'r','r','r','r','r','r','r','r'},
							{ 'y', 'y','y','y','y','y','y','y','y'},
							{ 'b', 'b','b','b','b','b','b','b','b'},
							{ 'o', 'o','o','o','o','o','o','o','o'}};

		cin >> n;
		char sides[1000];
		char dirs[1000];
		for (int j = 0; j < n; j++) {
			cin >> sides[j] >> dirs[j];
		}

		for (int j = 0; j < n; j++) {
			char side = sides[j];
			char dir = dirs[j];
			trans(cube, side, status);
			rt(cube, dir);
		}

		for (int j = 0; j < 9; j++) {
			cout << cube[status['U']][j] << " ";
			if ((j + 1) % 3 == 0) cout << '\n';
		}
	}


	return 0;
}
