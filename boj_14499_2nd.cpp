#include<bits/stdc++.h>
using namespace std;

enum SIDE {
	BACK = 0,
	LEFT,
	CELING,
	RIGHT,
	FLOOR,
	FRONT
};

enum DIR {
	EAST = 1,
	WEST = 2,
	NORTH = 3,
	SOUTH = 4
};

int dice[6] = { 0, 0, 0, 0, 0, 0 };
int mp[20][20] = { 0, };
int N, M;
int x, y;
int K = 0;

queue<int> order;

void roll(int dir) {
	switch (dir) {
		case EAST:
			if (y + 1 < M) {
				y += 1;
				int temp = dice[CELING];
				dice[CELING] = dice[LEFT];
				dice[LEFT] = dice[FLOOR];
				dice[FLOOR] = dice[RIGHT];
				dice[RIGHT] = temp;
				if (mp[x][y] == 0) mp[x][y] = dice[FLOOR];
				else if (mp[x][y] != 0) {
					dice[FLOOR] = mp[x][y];
					mp[x][y] = 0;
				}
			}
			break;
		case WEST:
			if (y - 1 >= 0) {
				y -= 1;
				int temp = dice[CELING];
				dice[CELING] = dice[RIGHT];
				dice[RIGHT] = dice[FLOOR];
				dice[FLOOR] = dice[LEFT];
				dice[LEFT] = temp;
				if (mp[x][y] == 0) mp[x][y] = dice[FLOOR];
				else if (mp[x][y] != 0) {
					dice[FLOOR] = mp[x][y];
					mp[x][y] = 0;
				}
			}
			break;
		case NORTH:
			if (x - 1 >= 0) {
				x -= 1;
				int temp = dice[CELING];
				dice[CELING] = dice[FRONT];
				dice[FRONT] = dice[FLOOR];
				dice[FLOOR] = dice[BACK];
				dice[BACK] = temp;
				if (mp[x][y] == 0) mp[x][y] = dice[FLOOR];
				else if (mp[x][y] != 0) {
					dice[FLOOR] = mp[x][y];
					mp[x][y] = 0;
				}
			}
			break;
		case SOUTH:
			if (x + 1 < N) {
				x += 1;
				int temp = dice[CELING];
				dice[CELING] = dice[BACK];
				dice[BACK] = dice[FLOOR];
				dice[FLOOR] = dice[FRONT];
				dice[FRONT] = temp;

				if (mp[x][y] == 0) mp[x][y] = dice[FLOOR];
				else if (mp[x][y] != 0) {
					dice[FLOOR] = mp[x][y];
					mp[x][y] = 0;
				}
			}
			break;
	}

	
}

int main() {
	cin >> N >> M >> x >> y >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mp[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int a = 0; cin >> a;
		order.push(a);
	}


	while (!order.empty()) {
		int cpyX = x; int cpyY = y;
		roll(order.front());
		order.pop();
		if (x != cpyX || y != cpyY)	cout << dice[CELING] << '\n';
	}

	return 0;
}
