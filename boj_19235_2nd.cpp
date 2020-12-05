#include<bits/stdc++.h>
using namespace std;

int N = 0;
int blocks[10000][3] = {  };
int green[6][4];
int blue[6][4];
int ans = 0;
bool isValid(int x, int y) {
	return 0 <= x && x < 6 && 0 <= y && y < 4;
}
void move(vector<pair<int, int>> b, int pan[][4], int val) {

	int crash = 0;

	while (crash == 0) {
		for (auto& e : b) {
			int xnext = e.first + 1;
			int ynext = e.second;
			if (!isValid(xnext, ynext) || pan[xnext][ynext] != 0) {
				crash = 1;
				break;
			}
		}
		if (crash == 0) {
			for (auto& e : b) e.first++;
		}
	}

	for (auto const e : b) {
		pan[e.first][e.second] = val;
	}

}
int score(int pan[][4]) {
	int ret = 0;
	for (int i = 5; i >= 2; i--) {
		int mul = 1;
		for (int j = 0; j < 4; j++) {
			mul *= pan[i][j];
		}

		if (mul != 0) {
			ans++;
			ret = i;
			for (int j = 0; j < 4; j++) {
				pan[i][j] = 0;
			}
		}
	}
	return ret;
}

void checkPeak(int pan[][4]) {
	int p = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			if (pan[i][j] != 0) {
				p++; break;
			}
		}
	}

	if (p != 0){
		for (int i = 5 - p; i >= 0; i--) {
			copy(pan[i], pan[i] + 4, pan[i + p]);
		}
		fill(pan[0] + 0, pan[0] + 4 * (p - 1) + 4, 0);
	}
}

int cnt() {
	int sum = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (green[i][j] != 0)sum++;
			if (blue[i][j] != 0) sum++;
		}
	}
	return sum;
}
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> blocks[i][0] >> blocks[i][1] >> blocks[i][2];
	}

	for (int i = 0; i < N; i++) {
		int t = blocks[i][0];
		int x = blocks[i][1];
		int y = blocks[i][2];
		vector<pair<int, int>> blockG;
		vector<pair<int, int>> blockB;
		switch (t) {
		case 1:
			blockG.push_back(make_pair(0, y));
			blockB.push_back(make_pair(0, 3 - x));
			break;
		case 2:
			blockG.push_back(make_pair(0, y));
			blockG.push_back(make_pair(0, y + 1));

			blockB.push_back(make_pair(0, 3 - x));
			blockB.push_back(make_pair(1, 3 - x));
			break;
		case 3:
			blockG.push_back(make_pair(0, y));
			blockG.push_back(make_pair(0 + 1, y));

			blockB.push_back(make_pair(0, 3 - x));
			blockB.push_back(make_pair(0, 3 - (x + 1)));
			break;
		}

		move(blockG, green, i + 1);
		move(blockB, blue, i + 1);

		int deletedRow = 0;
		while (deletedRow = score(green)) {
			if (deletedRow != 0) {
				for (int i = deletedRow - 1; i >= 0; i--) {
					for (int j = 0; j < 4; j++) {
						if (green[i][j] != 0) {
							int val = green[i][j];
							green[i][j] = 0;
							vector<pair<int, int>> moveable;
							moveable.push_back(make_pair(i, j));
							if (isValid(i, j + 1) && val == green[i][j + 1]) {
								green[i][j + 1] = 0;
								moveable.push_back(make_pair(i, j + 1));
								j += 1;
							}
							move(moveable, green, val);
						}
					}
				}
			}
		}

		deletedRow = 0;
		while (deletedRow = score(blue)) {
			if (deletedRow != 0) {
				for (int i = deletedRow - 1; i >= 0; i--) {
					for (int j = 0; j < 4; j++) {
						if (blue[i][j] != 0) {
							int val = blue[i][j];
							blue[i][j] = 0;
							vector<pair<int, int>> moveable;
							moveable.push_back(make_pair(i, j));
							if (isValid(i, j + 1) && val == blue[i][j + 1]) {
								blue[i][j + 1] = 0;
								moveable.push_back(make_pair(i, j + 1));
								j += 1;
							}
							move(moveable, blue, val);
						}
					}
				}
			}
		}

		checkPeak(green);
		checkPeak(blue);
	}
	cout << ans << '\n' << cnt();
	return 0;
}
