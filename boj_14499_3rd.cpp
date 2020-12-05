#include <bits/stdc++.h>
using namespace std;

int rdir[4] = { 0, 0, -1, 1 };
int cdir[4] = { 1, -1, 0, 0 };
vector<vector<int>> pan;
vector<int> dice(6, 0);
int N, M, x, y, K = 0;
vector<int> dirs;

void slide(int dir) {
	int temp;
	switch (dir) {
		case 0:
			temp = dice[2];
			dice[2] = dice[0];
			dice[0] = dice[3];
			dice[3] = dice[5];
			dice[5] = temp;
			break;
		case 1:
			temp = dice[0];
			dice[0] = dice[2];
			dice[2] = dice[5];
			dice[5] = dice[3];
			dice[3] = temp;
			break;
		case 2:
			temp = dice[4];
			dice[4] = dice[0];
			dice[0] = dice[1];
			dice[1] = dice[5];
			dice[5] = temp;
			break;
		case 3:
			temp = dice[0];
			dice[0] = dice[4];
			dice[4] = dice[5];
			dice[5] = dice[1];
			dice[1] = temp;
			break;
	}
}
bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < M;
}
int main() {
	cin >> N >> M >> x >> y >> K;
	vector<int> a(M, 0);
	pan.assign(N, a);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pan[i][j];
		}
	}
	dirs.assign(K, 0);
	for (int i = 0; i < K; i++) {
		cin >> dirs[i];
		dirs[i]--;
	}

	while (!dirs.empty()) {
		int dir = dirs[0];
		if (isValid(x + rdir[dir], y + cdir[dir])) {
			slide(dir);
			x = x + rdir[dir];
			y = y + cdir[dir];
			if (pan[x][y] == 0) {
				pan[x][y] = dice[5];
			}
			else if(pan[x][y] != 0){
				dice[5] = pan[x][y];
				pan[x][y] = 0;
			}
			cout << dice[0] << '\n';
		}
		dirs.erase(dirs.begin(), dirs.begin() + 1);
	}

	return 0;
}
