#include <iostream>
#include <vector>
using namespace std;
vector<int> no;
vector<int> r;
vector<int> c;
vector<int> s;
vector<int> d;
vector<int> z;

void eat(int R, int C, int M) {
	int table[101][101] = { 0, };

	for (int i = 0; i < M; i++) {
		int size = z[i];
		if (size == -1) {
			continue;
		}
		int row = r[i];
		int col = c[i];
		int number = no[i];

		if (table[row][col] == 0) {
			table[row][col] = number;
		}
		else {
			int number_already = table[row][col];
			int size_already = z[number_already - 1];
			if (size > size_already) {
				table[row][col] = number;
				z[number_already - 1] = -1;
			}
			else {
				z[number - 1] = -1;
			}
		}
	}

	
	cout << endl;
	for (int i = 1; i < R + 1; i++) {
		for (int j = 1; j < C + 1; j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	
}
int move(int index, int R, int C) {
	int size = z[index];
	if (size == -1) {
		return 0;
	}
	int dir = d[index];
	int row = r[index];
	int col = c[index];
	int speed = s[index];
	int distance = speed;

	if (dir == 1) {
		if (distance <= row - 1) {
			row = row - distance;
		}
		else {
			distance = distance - (row - 1);

			row = 1;
			dir = 2;

			int p = distance / (R - 1);
			int q = distance % (R - 1);
			int p2 = p % 2;

			if (p2 == 0) {  // 짝수이면 방향은 그대로
				row += q;
			}
			else if (p2 == 1) {
				row = R - q;
				dir = 1;
			}
		}

		r[index] = row;
		d[index] = dir;

	}
	else if (dir == 2) {
		if (distance <= R - row) {
			row = row + distance;
		}
		else {
			distance = distance - (R - row);

			row = R;
			dir = 1;

			int p = distance / (R - 1);
			int q = distance % (R - 1);
			int p2 = p % 2;

			if (p2 == 0) {  // 짝수이면 방향은 그대로
				row = R - q;
			}
			else if (p2 == 1) {
				row = 1 + q;
				dir = 2;
			}
		}

		r[index] = row;
		d[index] = dir;
	}
	else if (dir == 3) {
		if (distance <= C - col) {
			col = col + distance;
		}
		else {
			distance = distance - (C - col);

			col = C;
			dir = 4;

			int p = distance / (C - 1);
			int q = distance % (C - 1);
			int p2 = p % 2;

			if (p2 == 0) {  // 짝수이면 방향은 그대로
				col = C - q;
			}
			else if (p2 == 1) {
				col = 1 + q;
				dir = 3;
			}
		}

		c[index] = col;
		d[index] = dir;
	}
	else if (dir == 4) {
		if (distance <= col - 1) {
			col = col - distance;
		}
		else {
			distance = distance - (col - 1);

			col = 1;
			dir = 3;

			int p = distance / (C - 1);
			int q = distance % (C - 1);
			int p2 = p % 2;

			if (p2 == 0) {  // 짝수이면 방향은 그대로
				col += q;
			}
			else if (p2 == 1) {
				col = C - q;
				dir = 4;
			}
		}
		c[index] = col;
		d[index] = dir;
	}


	return 0;
}

int fish(int R, int M, int pos) {

	int ret = 0;

	int eaten_row = R + 1;
	int eaten_number = 0;

	for (int i = 0; i < M; i++) {
		int col = c[i];
		int row = r[i];
		int size = z[i];
		int number = no[i];
		if (size == -1) {
			continue;
		}

		if (col == pos) {
			if (eaten_row > row) {
				eaten_row = row;
				eaten_number = number;
			}
		}
	}
	if (eaten_row != R + 1) {
		ret = z[eaten_number - 1];
		z[eaten_number - 1] = -1;
	}
	//cout << eaten_row << " " << ret << " " << endl;
	return ret;
}

int main() {

	int R = 0; int C = 0; int M = 0;
	cin >> R >> C >> M;
	int ans = 0;

	for (int i = 0; i < M; i++) {
		int input = 0;
		no.push_back(i + 1);
		cin >> input; r.push_back(input);
		cin >> input; c.push_back(input);
		cin >> input; s.push_back(input);
		cin >> input; d.push_back(input);
		cin >> input; z.push_back(input);
	}

	for (int j = 0; j < C; j++) {

		int king_col = j + 1; //이동

		ans += fish(R, M, king_col);

		for (int i = 0; i < M; i++) {
			move(i, R, C);
		}

		eat(R, C, M);
	}

	cout << ans << endl;


	return 0;
}