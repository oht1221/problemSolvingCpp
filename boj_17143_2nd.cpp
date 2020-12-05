#include<bits/stdc++.h>

using namespace std;
int R, C = 0;
int mp[100][100] = { 0 , };

int M = 0;
vector<vector<int>> sharks;
int ans = 0;
int man = 0;
int rdir[4] = { -1, 0, 1, 0 };
int cdir[4] = { 0, 1, 0, -1 };


bool isValid(int r, int c) {
	return 0 <= r && r < R && 0 <= c && c < C;
}
enum Property {
	row,
	col,
	vel,
	dir,
	siz
};

void sharkMove(int x) {
	int r = sharks[x][row];
	int c = sharks[x][col];
	int v = sharks[x][vel];
	int d = sharks[x][dir];
	int s = sharks[x][siz];
	
	int loop = 0;
	switch (d) {
	case 0:
		loop = R * 2 - 2;
		v = v % loop;

		break;
	case 1:
		loop = C * 2 - 2;
		v = v % loop;
		break;
	case 2:
		loop = R * 2 - 2;
		v = v % loop;
		break;
	case 3:
		loop = C * 2 - 2;
		v = v % loop;
		break;
	}

	for (int i = 0; i < v; i++) {
		if (!isValid(r + rdir[d], c + cdir[d])) {
			sharks[x][dir] = (d + 2) % 4;
			d = sharks[x][dir];
		}
		r = r + rdir[d]; c = c + cdir[d];
	}

	sharks[x][row] = r; sharks[x][col] = c;
	
	if (mp[r][c] == 0) {
		mp[r][c] = x;
	}
	else {
		if (sharks[mp[r][c]][siz] < s) {
			sharks[mp[r][c]][siz] = 0;
			mp[r][c] = x;
		}
		else {
			sharks[x][siz] = 0;
		}
	}
}
void move() {
	for (int i = 1; i <= M; i++) {
		mp[sharks[i][row]][sharks[i][col]] = 0;
	}

	for (int i = 1; i <= M; i++) {
		if(sharks[i][siz] != 0) sharkMove(i);
	}
	
}

void fishing() {
	int target = 0;

	for (int i = 1; i <= M; i++) {
		if (sharks[i][siz] != 0 && sharks[i][col] == man) {
			if (target == 0) target = i;
			else {
				if (sharks[target][row] > sharks[i][row]) {
					target = i;
				}
			}
		}
	}
	if (target != 0) {
		ans += sharks[target][siz];
		sharks[target][siz] = 0;
	}
}

bool noFish() {
	for (int i = 1; i <= M; i++) {
		if (sharks[i][siz] != 0) return false;
	}
	return true;
}

int main() {
	cin >> R >> C >> M;

	sharks.push_back({ -1, -1, -1, -1, -1 });

	for (int i = 0; i < M; i++) {
		int r, c, s, d, z = 0;
		cin >> r >> c >> s >> d >> z;
		
		if (d == 1) d = 0;
		else if (d == 2) d = 2;
		else if (d == 3) d = 1;
		else if (d == 4) d = 3;

		vector<int> shark = { r - 1, c - 1, s, d, z };
		sharks.push_back(shark);
		mp[r - 1][c - 1] = i + 1;
	}
	
	while (man < C) {

		if (noFish()) break;
		fishing();
		move();

		man++;
	}
	cout << ans << '\n';

	return 0;
}




