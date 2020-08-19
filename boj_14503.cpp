#include<iostream>
#include <vector>
using namespace std;
void clean(vector<vector<int>> & m, int row,  int col) {
	m[row][col] = -1;
}
int main() {
	int N = 0; int M = 0;
	int r = 0; int c = 0; unsigned int d = 0;
	vector<vector<int>> map;
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < M; j++) {
			int cell = 0;
			cin >> cell;
			row.push_back(cell);
		}
		map.push_back(row);
	}
	int ans = 0;
	int flag = 1;
	int rot_count = 0;
	while (1) {
		if (flag == 1) {
			clean(map, r, c); ans++;
		}

		unsigned int exp_dir = (d - 1) % 4;
		int exp_r = 0;
		int exp_c = 0;
		if (exp_dir == 0) {
			exp_r = r - 1;
			exp_c = c;
		}
		else if (exp_dir == 1) {
			exp_r = r;
			exp_c = c + 1;
		}
		else if (exp_dir == 2) {
			exp_r = r + 1;
			exp_c = c;
		}
		else if (exp_dir == 3) {
			exp_r = r;
			exp_c = c - 1;
		}

		if (map[exp_r][exp_c] == 0) { //a
			d = exp_dir;
			r = exp_r;
			c = exp_c; // 전진
			rot_count = 0;
			flag = 1;
			continue;
		}
		else { //b 1 or -1인 경우
			d = exp_dir;
			rot_count++;
			if (rot_count == 4) {
				int back_r = 0; int back_c = 0;
				rot_count = 0;
				if (d == 0) {
					back_r = r + 1;
					back_c = c;
				}
				else if (d == 1) {
					back_r = r;
					back_c = c - 1;
				}
				else if (d == 2) {
					back_r = r - 1;
					back_c = c;
				}
				else if (d == 3) {
					back_r = r;
					back_c = c + 1;
				}

				if (map[back_r][back_c] == 1) {
					break;
				}
				else {
					r = back_r; c = back_c;
				}
			}
			flag = 0;
			continue;
		}
	}
	cout << ans << endl;
	return 0;
}