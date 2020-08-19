#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<vector<char>> table;
queue<int> B_ROW;
queue<int> B_COL;
queue<int> R_ROW;
queue<int> R_COL;
queue<int> stage;
int hole_r = 0;
int hole_c = 0;
int N = 0; int M = 0;
int r_visit[10][10][10][10] = { 0, };

void right(int b_row, int b_col, int r_row, int r_col, int stg) {
	int new_bc = 0; int new_rc = 0;
	for (int i = b_col; i < M; i++) {
		if (table[b_row][i + 1] == 'O') {
			new_bc = i + 1;
			break;
		}
		else if (table[b_row][i + 1] == '#') {
			new_bc = i;
			break;
		}
	}
	for (int j = r_col; j < M; j++) {
		if (table[r_row][j + 1] == 'O') {
			new_rc = j + 1;
			break;
		}
		else if (table[r_row][j + 1] == '#') {
			new_rc = j;
			break;
		}
	}

	if (table[b_row][new_bc] != 'O') {
		if (b_row == r_row && new_bc == new_rc) {
			if (b_col > r_col) {
				new_rc = new_rc - 1;
			}
			else if (b_col < r_col) {
				new_bc = new_bc - 1;
			}
		}
	}
	
	B_ROW.push(b_row); B_COL.push(new_bc);
	R_ROW.push(r_row); R_COL.push(new_rc);
	stage.push(stg + 1);
	
}
void left(int b_row, int b_col, int r_row, int r_col, int stg) {
	int new_bc = 0; int new_rc = 0;
	for (int i = b_col; i >= 0; i--) {
		if (table[b_row][i - 1] == 'O') {
			new_bc = i - 1;
			break;
		}
		else if (table[b_row][i - 1] == '#') {
			new_bc = i;
			break;
		}
	}
	for (int j = r_col; j >= 0; j--) {
		if (table[r_row][j - 1] == 'O') {
			new_rc = j - 1;
			break;
		}
		else if (table[r_row][j - 1] == '#') {
			new_rc = j;
			break;
		}
	}

	if (table[b_row][new_bc] != 'O') {
		if (b_row == r_row && new_bc == new_rc) {
			if (b_col > r_col) {
				new_bc = new_bc + 1;
			}
			else if (b_col < r_col) {
				new_rc = new_rc + 1;
			}
		}
	}
	
	B_ROW.push(b_row); B_COL.push(new_bc);
	R_ROW.push(r_row); R_COL.push(new_rc);
	stage.push(stg + 1);

}
void up(int b_row, int b_col, int r_row, int r_col, int stg) {
	int new_br = 0; int new_rr = 0;
	for (int i = b_row; i >= 0; i--) {
		if (table[i - 1][b_col] == 'O') {
			new_br = i - 1;
			break;
		}
		else if (table[i - 1][b_col] == '#') {
			new_br = i;
			break;
		}
	}
	for (int j = r_row; j >= 0; j--) {
		if (table[j - 1][r_col] == 'O') {
			new_rr = j - 1;
			break;
		}
		else if (table[j - 1][r_col] == '#') {
			new_rr = j;
			break;
		}
	}
	if (table[new_br][b_col] != 'O') {
		if (new_br == new_rr && b_col == r_col) {
			if (b_row > r_row) {
				new_br = new_br + 1;
			}
			else if (b_row < r_row) {
				new_rr = new_rr + 1;
			}
		}
	}
	
	B_ROW.push(new_br); B_COL.push(b_col);
	R_ROW.push(new_rr); R_COL.push(r_col);
	stage.push(stg + 1);
	
}
void down(int b_row, int b_col, int r_row, int r_col, int stg) {
	int new_br = 0; int new_rr = 0;
	for (int i = b_row; i < N; i++) {
		if (table[i + 1][b_col] == 'O') {
			new_br = i + 1;
			break;
		}
		else if (table[i + 1][b_col] == '#') {
			new_br = i;
			break;
		}
	}
	for (int j = r_row; j < N; j++) {
		if (table[j + 1][r_col] == 'O') {
			new_rr = j + 1;
			break;
		}
		else if (table[j + 1][r_col] == '#') {
			new_rr = j;
			break;
		}
	}

	if (table[new_br][b_col] != 'O') {
		if (new_br == new_rr && b_col == r_col) {
			if (b_row > r_row) {
				new_rr = new_rr - 1;
			}
			else if (b_row < r_row) {
				new_br = new_br - 1;
			}
		}
	}

	B_ROW.push(new_br); B_COL.push(b_col);
	R_ROW.push(new_rr); R_COL.push(r_col);
	stage.push(stg + 1);

}
int bfs(int br, int bc, int rr, int rc, int s) {

	if (table[br][bc] == 'O') {
		return 0;
	}

	if (s > 10) {
		return 0;
	}

	if (r_visit[br][bc][rr][rc] == 1) {
		return 0;
	}

	if (table[rr][rc] == 'O') {
		return s;
	}

	r_visit[br][bc][rr][rc] = 1;

	right(br, bc, rr, rc, s);
	left(br, bc, rr, rc, s);
	up(br, bc, rr, rc, s);
	down(br, bc, rr, rc, s);

	return 0;
}

void printStatus() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << table[i][j];
		}
		cout << endl;
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<char> arr;
		for (int j = 0; j < M; j++) {
			char cell = 0;
			cin >> cell;
			arr.push_back(cell);
			if (cell == 'B') {
				B_ROW.push(i); B_COL.push(j);
			}
			else if (cell == 'R') {
				R_ROW.push(i); R_COL.push(j);
				
			}
			else if (cell == 'O') {
				hole_r = i; hole_c = j;
			}

		}
		table.push_back(arr);
	}
	stage.push(0);
	int ans = -1;
	while (stage.size() != 0) {
		int BR = B_ROW.front(); B_ROW.pop();
		int BC = B_COL.front(); B_COL.pop();
		int RR = R_ROW.front(); R_ROW.pop();
		int RC = R_COL.front(); R_COL.pop();
		int S = stage.front(); stage.pop();
		ans = bfs(BR, BC, RR, RC, S);
		if (ans != 0) {
			break;
		}
	}

	if (stage.size() == 0  && ans == 0) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
	}
	return 0;
}