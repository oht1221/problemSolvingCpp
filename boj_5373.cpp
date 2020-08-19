#include<bits/stdc++.h>
using namespace std;
enum SIDE {U, L, F, R, B, D};
typedef vector<char> VC;

char arr[54];
int cube[6][3][3] = { {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}},
									 {{9, 10, 11}, {12, 13, 14}, {15, 16, 17}},
	                                 {{18, 19, 20}, {21, 22, 23}, {24, 25, 26}},
	                                 {{27, 28, 29}, {30, 31, 32}, {33, 34, 35}},
	                                 {{36, 37, 38}, {39, 40, 41}, {42, 43, 44}},
									 {{45, 46, 47}, {48, 49, 50}, {51, 52, 53}} };

int table[6][12] = { {38, 37, 36, 29, 28, 27, 20, 19, 18, 11, 10, 9},
					 {0, 3, 6, 18, 21, 24, 45, 48, 51, 44, 41, 38},
					 {6, 7, 8, 27, 30, 33, 47, 46, 45, 17, 14, 11},
					 {8, 5, 2, 36, 39, 42, 53, 50, 47, 26, 23, 20},
					 {2, 1, 0, 9, 12, 15, 51, 52, 53, 35, 32, 29},
					 {24, 25, 26, 33, 34, 35, 42, 43, 44, 15, 16, 17} };

int conv[256];
void rotate(SIDE s) {
	char que[12];
	for (int i = 0; i < 12; i++) {
		int idx = table[s][i];
		que[i] = arr[idx];
	}
	for (int i = 0; i < 12; i++) {
		int idx = table[s][(i + 3) % 12];
		arr[idx] = que[i];
	}

	char temp[3][3];
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
			int idx = cube[s][i][j];
			temp[j][2 - i] = arr[idx];
	}
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
			int idx = cube[s][i][j];
			arr[idx] = temp[i][j];
	}
}
int main() {
	int n = 0; cin >> n;
	for (int i = 0; i < 54; i++) {
	}

	conv['U'] = U;
	conv['D'] = D;
	conv['F'] = F;
	conv['B'] = B;
	conv['L'] = L;
	conv['R'] = R;
	char init[7] = "wgrboy";
	while (n--) {
		int m; cin >> m;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 9; j++) {
				arr[i * 9 + j] = init[i];
			}
		}
		for (int i = 0; i < m; i++) {
			char side; char dir;
			cin >> side >> dir;
			int S = conv[side];

			if ('+' == dir) rotate((SIDE)S);
			else if ('-' == dir) {
				for (int i = 0; i < 3; i++) rotate((SIDE)S);
			}
		}

		for (int i = 0; i < 9; i++) {
			cout << arr[i];
			if (i % 3 == 2) cout << '\n';
		}
	}
	return 0;
}