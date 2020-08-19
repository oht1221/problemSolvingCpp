#include<bits/stdc++.h>
using namespace std;


int PF_row[2];
int PF_count = 0;
int row_dir[4] = { -1, 0, 1, 0 };
int col_dir[4] = { 0, 1, 0, -1 };
int c_clock_row[4] = { 0, -1, 0, 1 };
int c_clock_col[4] = { 1, 0, -1, 0 };
int clock_row[4] = { 0, 1, 0, -1 };
int clock_col[4] = { 1, 0, -1, 0 };

int R, C, T;
void spread(int r, int c, int map[][50], int temp[][50]) {
	if (-1 == map[r][c]) return;
	if (0 == map[r][c]) return;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int r_spread = r + row_dir[i];
		int c_spread = c + col_dir[i];
		if (r_spread >= 0 && r_spread < R && c_spread >= 0 && c_spread < C && map[r_spread][c_spread] != -1) {
			cnt++;
			temp[r_spread][c_spread] += (int)( map[r][c] / 5);
		}
	}
	map[r][c] -= cnt * ((int)(map[r][c] / 5));

}
int main() {
	cin >> R >> C >> T;
	int map[50][50] = { -1, };

	int ans = 0;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				PF_row[PF_count++] = i;
			}
		}
	}

	while (T--) {
		int temp[50][50] = { 0, };
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				spread(i, j, map, temp);
			}
		}

		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				map[i][j] += temp[i][j];
			}
		}

		int r = PF_row[0]; int c = 1;
		int prev = 0;
		for (int i = 0; i < 4; i++) {
			while (1) {
				if (map[r][c] == -1) break;

				int r_next = r + c_clock_row[i];
				int c_next = c + c_clock_col[i];
				if (r_next >= 0 && r_next < R && c_next >= 0 && c_next < C) {
					int next = map[r][c];
					map[r][c] = prev;
					prev = next;
					r = r_next; c = c_next;
				}
				else {
					break;
				}
			}
		}

		r = PF_row[1]; c = 1;
		prev = 0;
		for (int i = 0; i < 4; i++) {
			while (1) {
				if (map[r][c] == -1) break;

				int r_next = r + clock_row[i];
				int c_next = c + clock_col[i];
				if (r_next >= 0 && r_next < R && c_next >= 0 && c_next < C) {
					int next = map[r][c];
					map[r][c] = prev;
					prev = next;
					r = r_next; c = c_next;
				}
				else {
					break;
				}
			}
		}


	
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			//cout << map[i][j] << " ";
			if (map[i][j] != -1)  ans += map[i][j];
		}
		//cout << endl;
	}

	cout << ans << endl;
	return 0;
}
