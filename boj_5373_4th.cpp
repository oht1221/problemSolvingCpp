#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<string.h>
using namespace std;
int n = 0;
map<char, int> sides;

vector<int> conv(int idx) {
	vector<int> ret;
	int sideN = idx / 9;
	int side = idx % 9;
	ret.push_back(sideN);
	int r =  side / 3;
	ret.push_back(r);
	int c = side % 3;
	ret.push_back(c);
	return ret;
}

int table[6][12] = 	{ {38, 37, 36, 29, 28, 27, 20, 19, 18, 11, 10, 9},
	 { 0, 3, 6, 18, 21, 24, 45, 48, 51, 44, 41, 38},
	 { 6, 7, 8, 27, 30, 33, 47, 46, 45, 17, 14, 11},
	 { 8, 5, 2, 36, 39, 42, 53, 50, 47, 26, 23, 20},
	 { 2, 1, 0, 9, 12, 15, 51, 52, 53, 35, 32, 29 },
	 { 24, 25, 26, 33, 34, 35, 42, 43, 44, 15, 16, 17}, };

void Rt(char cube[][3][3], char s) {
	int sideN = sides[s];

	char temp[3][3];
	copy(cube[sideN][0], cube[sideN][0] + 3, temp[0]);
	copy(cube[sideN][0] + 3, cube[sideN][0] + 6, temp[1]);
	copy(cube[sideN][0] + 6, cube[sideN][0] + 9, temp[2]);
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cube[sideN][j][2 - i] = temp[i][j];
		}
	}

	vector<char> Q;
	for (int i = 0; i < 12; i++) {
		int idx1 = table[sideN][i];
		vector<int> point1 = conv(idx1);

		Q.push_back(cube[point1[0]][point1[1]][point1[2]]);
	}

	for (int i = 0; i < 12; i++) {
		int idx1 = table[sideN][(i + 3) % 12];
		vector<int> point1 = conv(idx1);

		cube[point1[0]][point1[1]][point1[2]] = Q[i];
	}
}
void Rotate(char cube[][3][3], char s, char d) {
	int cnt = 0;
	switch (d) {
	case '-':
		cnt = 3;
		break;
	case '+':
		cnt = 1;
		break;
	}

	for (int i = 0; i < cnt; i++) {
		Rt(cube, s);
	}

	return;
}

int main() {
	int t = 0;
	cin >> t;
	sides['U'] = 0;
	sides['L'] = 1;
	sides['F'] = 2;
	sides['R'] = 3;
	sides['B'] = 4;
	sides['D'] = 5;

	while(t--) {


		char cube[6][3][3] = { { {'w', 'w', 'w'}, { 'w', 'w', 'w' }, { 'w', 'w', 'w' }},
		{ {'g', 'g', 'g'}, { 'g', 'g', 'g' }, { 'g', 'g', 'g' }},
		{ {'r', 'r', 'r'}, { 'r', 'r', 'r' }, { 'r', 'r', 'r' }},
		{ {'b', 'b', 'b'}, { 'b', 'b', 'b' }, { 'b', 'b', 'b' }},
		{ {'o', 'o', 'o'}, { 'o', 'o', 'o' }, { 'o', 'o', 'o' }},
		{ {'y', 'y', 'y'}, { 'y', 'y', 'y' }, { 'y', 'y', 'y' }} };

		vector<char> side;
		vector<char> dir;

		cin >> n;
		side.assign(n, '0');
		dir.assign(n, '0');

		for (int i = 0; i < n; i++) {
			cin >> side[i] >> dir[i];
		}

		for (int i = 0; i < n; i++) {
			char s = side[i];
			char d = dir[i];

			Rotate(cube, s, d);
		}
		
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << cube[0][i][j];
			}
			cout << endl;
		}
		
	}
	

	return 0;
}
