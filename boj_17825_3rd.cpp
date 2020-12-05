#include<map>
#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;
int horse[4] = { 0, }; //처음 위치 0
int point[4] = { 0, };
int dice[10] = { 0, };
int ans = INT_MIN;

map<int, pair<int, int>> redMap; //점수 and 가야할 곳
map<int, pair<int, int>> blueMap;

void dfs(int n) {

	if (n == 10) {
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			sum += point[i];
		}
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i ++ ) {
		int D = dice[n];
		if (horse[i] == 32) continue; //도착칸에 있는 것 제외

		int origin = horse[i];

		if (horse[i] == 5 || horse[i] == 10 || horse[i] == 15) { // 블루맵 있으면 블루맵으로
			horse[i] = blueMap[horse[i]].second;
			D--;
		}

		for (int j = 0; j < D; j++) { // 이동
			horse[i] = redMap[horse[i]].second;
			if (horse[i] == 32) { //도착하면 거기서 끝
				break;
			}
		}

		int flag = 0;
		for (int k = 0; k < 4; k++) {
			if (horse[i] != 32 && i != k && horse[k] == horse[i]) {//  도착지 아닌 위치에 다른 말 있으면
				horse[i] = origin; //원래 자리로
				flag = 1;
			}
		}

		if (flag == 1) continue;

		int score = redMap[horse[i]].first;
		point[i] += score; //점수 추가
		dfs(n + 1);
		point[i] -= score;
		horse[i] = origin;
	}

}

int main() {

	redMap[0] = make_pair(0, 1);
	redMap[1] = make_pair(2, 2);
	redMap[2] = make_pair(4, 3);
	redMap[3] = make_pair(6, 4);
	redMap[4] = make_pair(8, 5);
	redMap[5] = make_pair(10, 6);
	redMap[6] = make_pair(12, 7);
	redMap[7] = make_pair(14, 8);
	redMap[8] = make_pair(16, 9);
	redMap[9] = make_pair(18, 10);
	redMap[10] = make_pair(20, 11);
	redMap[11] = make_pair(22, 12);
	redMap[12] = make_pair(24, 13);
	redMap[13] = make_pair(26, 14);
	redMap[14] = make_pair(28, 15);
	redMap[15] = make_pair(30, 16);
	redMap[16] = make_pair(32, 17);
	redMap[17] = make_pair(34, 18);
	redMap[18] = make_pair(36, 19);
	redMap[19] = make_pair(38, 20);
	redMap[20] = make_pair(40, 32);
	redMap[21] = make_pair(13, 22);
	redMap[22] = make_pair(16, 23);
	redMap[23] = make_pair(19, 24);
	redMap[24] = make_pair(25, 30);
	redMap[25] = make_pair(22, 26);
	redMap[26] = make_pair(24, 24);
	redMap[27] = make_pair(26, 24);
	redMap[28] = make_pair(27, 27);
	redMap[29] = make_pair(28, 28);
	redMap[30] = make_pair(30, 31);
	redMap[31] = make_pair(35, 20);
	redMap[32] = make_pair(0, -1);

	blueMap[5] = make_pair(10, 21);
	blueMap[10] = make_pair(20, 25);
	blueMap[15] = make_pair(30, 29);

	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}

	horse[0] += dice[0];
	point[0] += redMap[horse[0]].first;

	dfs(1);

	cout << ans << endl;
	return 0;
}
