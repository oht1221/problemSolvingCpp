#include<iostream>
#include<vector>
using namespace std;
int N; int M;
int r; int c;

int roll(int dir, vector<vector<int>>& map, vector<int> &dice) {
	int next_r = r; int next_c = c;
	if (dir == 1) {
		next_c = next_c + 1;
		if (next_c >= M) {
			return -1;
		}
		else {
			c = next_c;
			int temp_3 = dice[3]; int temp_0 = dice[0]; int temp_1 = dice[1]; int temp_2 = dice[2];
			dice[3] = temp_0; dice[1] = temp_3; dice[2] = temp_1; dice[0] = temp_2;
		}
	}
	else if (dir == 2) {
		next_c = next_c - 1;
		if (next_c < 0) {
			return -1;
		}
		else {
			c = next_c;
			int temp_3 = dice[3]; int temp_0 = dice[0]; int temp_1 = dice[1]; int temp_2 = dice[2];
			dice[2] = temp_0; dice[1] = temp_2; dice[3] = temp_1; dice[0] = temp_3;
		}
	}
	else if (dir == 4) {
		next_r = next_r + 1;
		if (next_r >= N) {
			return -1;
		}
		else {
			r = next_r;
			int temp_4 = dice[4]; int temp_0 = dice[0]; int temp_1 = dice[1]; int temp_5 = dice[5];
			dice[4] = temp_0; dice[1] = temp_4; dice[5] = temp_1; dice[0] = temp_5;
		}
	}
	else if (dir == 3) {
		next_r = next_r - 1;
		if (next_r < 0) {
			return -1;
		}
		else {
			r = next_r;
			int temp_4 = dice[4]; int temp_0 = dice[0]; int temp_1 = dice[1]; int temp_5 = dice[5];
			dice[5] = temp_0; dice[1] = temp_5; dice[4] = temp_1; dice[0] = temp_4;
		}
	}

	if (map[r][c] == 0) {
		map[r][c] = dice[1];
	}
	else {
		dice[1] = map[r][c];
		map[r][c] = 0;
	}
	return 0;
}

int main() {
	vector<int> dice;
	dice.push_back(0); dice.push_back(0); dice.push_back(0); dice.push_back(0); dice.push_back(0); dice.push_back(0);
	vector<vector<int>> map;
	vector<int> moves;
	int n_moves;

	cin >> N >> M >> r >> c >> n_moves;
	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < M; j++) {
			int input = 0; cin >> input;
			row.push_back(input);
		}
		map.push_back(row);
	}

	for (int i = 0; i < n_moves; i++) {
		int input = 0; cin >> input;
		moves.push_back(input);
	}

	for (int i = 0; i < n_moves; i++) {
		int dir = moves[i];
		int ret = roll(dir, map, dice);
		if (ret == 0) {
			cout << dice[0] << endl;
		}
	}
	return 0;
}