#include<bits/stdc++.h>
using namespace std;
int camera[5][4] = { {0, 1, 0, 0}, { 0, 1, 0, 1}, { 1, 1, 0, 0}, {1, 1, 0, 1}, {1, 1, 1, 1} };
int times[5] = { 4, 2, 4, 4, 1 };
int mp[8][8];
int rdir[4] = { -1, 0, 1, 0 };
int cdir[4] = { 0, 1, 0, -1 };
int N, M;
vector<pair<int, int>> coords;
int ans = INT_MAX;

bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < M;
}

bool isBlocked(int r, int c) {
	return mp[r][c] == 6;
}

int counts(int const mp[][8]) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mp[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}

void rotate(int* arr) {
	int tmp = arr[3];
	for (int i = 2; i >= 0; i--) {
		arr[i + 1] = arr[i];
	}
	arr[0] = tmp;
}
void watch(int mp[][8], int r, int c, int* const cam) {
	for (int i = 0; i < 4; i++) {   //카메라별 보는 방향 0, 1, 2, 3 중 보는 방향으로 # 넣기
		int rStart = r;
		int cStart = c;
		if (cam[i] == 1) {
			while (isValid(rStart + rdir[i], cStart + cdir[i])) {
				if (mp[rStart + rdir[i]][cStart + cdir[i]] == 6) {
					break;
				}

				if (mp[rStart + rdir[i]][cStart + cdir[i]] == 0) {
					mp[rStart + rdir[i]][cStart + cdir[i]] = '#';
				}

				rStart = rStart + rdir[i];
				cStart = cStart + cdir[i];
			}
		}
	}
}
void dfs(int idx, int const mp[][8]) {
	if (idx == coords.size()) {
		ans = min(ans, counts(mp));
		return;
	}

	pair<int, int> coord = coords[idx];

	int num = mp[coord.first][coord.second];
	int cam[4];
	memcpy(cam, camera[num - 1], sizeof(cam));

	for (int i = 0; i < times[num - 1]; i++) {
		int mpCopy[8][8];
		memcpy(mpCopy, mp, sizeof(mpCopy));
		watch(mpCopy, coord.first, coord.second, cam);
		dfs(idx + 1, mpCopy);
		rotate(cam);
	}
	
}
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mp[i][j];
			if (mp[i][j] != 6 && mp[i][j] != 0) {
				coords.push_back(make_pair(i, j));
			}
		}
	}

	dfs(0, mp);

	cout << ans << '\n';
	return 0;
}
