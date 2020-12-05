#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int r = 0;
int c = 0;
int k = 0;
int pan[100][100] = { 0, };

int R = 3;
int C = 3;
int ans = 0;

void action() {

	int newPan[100][100] = { 0 , };  //0으로 재배치된 새 판
	if (R >= C) {
		int newC = 0;
		for (int i = 0; i < R; i++) {
			vector<pair<int, int>> row;
			int table[101] = { 0, };
			for (int j = 0; j < C; j++) { //갯수 세기
				if (pan[i][j] != 0) {
					int val = pan[i][j];
					table[val]++;
				}
			}

			for (int l = 0; l < 101; l++) {
				if (table[l] != 0) {
					row.push_back(make_pair(table[l], l));
				}
			}

			sort(row.begin(), row.end());
			
			int cnt = 0;
			for (int k = 0; k < row.size() && k < 50; k++) { //100개 넘어가면 무시
				newPan[i][k * 2] = row[k].second;
				newPan[i][k * 2 + 1] = row[k].first;
				cnt += 2;
			}
			newC = max(cnt, newC);
		}
		C = newC;
	}
	else if (R < C) {
		int newR = 0;
		for (int i = 0; i < C; i++) {  //열 차례대로
			vector<pair<int, int>> col;
			int table[101] = { 0, };
			for (int j = 0; j < R; j++) { //갯수 세기
				if (pan[j][i] != 0) {
					int val = pan[j][i];
					table[val]++;
				}
			}

			for (int l = 0; l < 101; l++) {
				if (table[l] != 0) {
					col.push_back(make_pair(table[l], l));
				}
			}

			sort(col.begin(), col.end());

			int cnt = 0;
			for (int k = 0; k < col.size() && k < 50; k++) { //100개 넘어가면 무시
				newPan[k * 2][i] = col[k].second;
				newPan[k * 2 + 1][i] = col[k].first;
				cnt += 2;
			}
			newR = max(cnt, newR);
		}
		R = newR;
	}
	memcpy(pan, newPan, sizeof(pan));
}

int main() {
	cin >> r >> c >> k;
	r = r - 1;
	c = c - 1;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> pan[i][j];
		}
	}

	while (pan[r][c] != k && (++ans) < 101) {

		action();
	}

	if (ans > 100) cout << -1 << endl;
	else cout << ans << endl;

	return 0;
}
