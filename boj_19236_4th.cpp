#include<vector>
#include<climits>
#include<string.h>
#include<iostream>
#include<map>

using namespace std;
int pan[4][4];//물고기 번호, 방향
map<int, int> alive; 
map<int, int> dir;
map<int, pair<int, int>> pos;
int ans = INT_MIN;
pair<int, int> sharkPos; 
int sharkDir;
int dr[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dc[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
bool isValid(int r, int c) {
	return 0 <= r && r < 4 && 0 <= c && c < 4;
}

void fishMove(int pan[][4], int sum, map<int, int> &alive, map<int, int> &dir, map<int, pair<int, int>> &pos) {  //새 판 복사해서 줘야함

	for (int i = 1; i <= 16; i++) {
		if (alive[i] == 0) continue; //죽은 물고기 제외
		pair<int, int> p = pos[i];
		int r = p.first; int c = p.second; //현재 물고기 위치
		int d = dir[i];
		int dnext = d;
		int flag = 0;
		int rnext = -1;
		int cnext = -1;

		for (int j = 0; j < 8; j++) {
			rnext = r + dr[dnext];
			cnext = c + dc[dnext];

			if (isValid(rnext, cnext) && pan[rnext][cnext] != 17) {
				flag = 1;
				dir[i] = dnext; //찾았으면 물고기 방향 전환
				break;
			}
			dnext = (dnext + 1) % 8; //다음 방향
		}

		if (flag == 1) { //갈 곳 찾음
			int fishN = pan[rnext][cnext]; //갈 곳의 물고기 번호

			pan[r][c] = fishN;
			if (fishN != 0) {
				pos[fishN] = make_pair(r, c);
			}

			pan[rnext][cnext] = i;
			pos[i] = make_pair(rnext, cnext);
		}
	}
}
void dfs(int pan[][4], int sum, map<int ,int> alive, map<int, int> dir, map<int, pair<int, int>> pos, pair<int, int> sharkPos, int sharkDir) {


	int newPan[4][4];
	memcpy(newPan, pan, sizeof(newPan));

	fishMove(newPan, sum, alive, dir, pos);

	int r = sharkPos.first;
	int c = sharkPos.second;
	int d = sharkDir;

	int rnext = r + dr[d];
	int cnext = c + dc[d];
	int flag = 0;

	while (1) {
		if (isValid(rnext, cnext)) {
			int fishN = newPan[rnext][cnext];
			int fishD = dir[fishN];
			if (fishN != 0) { //그 자리에 물고기 있으면

				flag = 1;
				sharkPos.first = rnext;
				sharkPos.second = cnext;
				sharkDir = fishD;
				alive[fishN] = 0; //물고기 죽음
				sum += fishN;
				newPan[rnext][cnext] = 17; // 맵에 상어 표시
				newPan[r][c] = 0;
				dfs(newPan, sum, alive, dir, pos, sharkPos, sharkDir);
				newPan[r][c] = 17;
				newPan[rnext][cnext] = fishN;
				sum -= fishN;
				alive[fishN] = 1;
				sharkDir = d;
				sharkPos.first = r;
				sharkPos.second = c;

			}
			rnext += dr[d];
			cnext += dc[d];
		}
		else { //valid하지 않은 칸에 도달할 때까지
			break;
		}
	}
	if (flag == 0) {
		ans = max(ans, sum);
	}
}


int main() {
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int a; int b;
			cin >> a >> b;
			pan[i][j] = a;
			dir[a] = b - 1;
			alive[a] = 1;
			pos[a] = make_pair(i, j);
		}
	}
	
	int fishN = pan[0][0];
	int fishD = dir[fishN];

	sharkPos.first = 0;
	sharkPos.second = 0;
	sharkDir = fishD; //상어 방향 전환
	alive[fishN] = 0; //물고기 죽음
	int sum = fishN;
	pan[0][0] = 17; //죽은 자리는 상어 번호으로 채움 (0번은 무효한 번호) , 상어 이동시 빈 자리는 0

	dfs(pan, sum, alive, dir, pos, sharkPos, sharkDir);


	cout << ans << endl;
	return 0;
}
