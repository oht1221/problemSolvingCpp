#include<bits/stdc++.h>
using namespace std;

typedef struct HORSE {
	int dir;
	int no;
} horse;

enum COLOR {
	WH,
	RD,
	BL
};

int rdir[4] = { -1, 0, 1, 0 };
int cdir[4] = { 0, 1, 0, -1 };
int N = 0;
int K = 0;
int ans = 1;
int mp[12][12];
vector<horse> mpHorse[12][12];
pair<int, int> hidx[10];

bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

void moveAll(int r, int c, vector<horse>& horseVector) {
	for (auto h : horseVector) {
		hidx[h.no].first = r;
		hidx[h.no].second = c;
	}
}

int main() {
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mp[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int r, c, d;
		cin >> r >> c >> d;

		horse h;
		h.no = i;
		if (d == 3) {
			h.dir = 0;
		}
		else if (d == 1) {
			h.dir = 1;
		}
		else if (d == 4) {
			h.dir = 2;
		}
		else if (d == 2) {
			h.dir = 3;
		}
		mpHorse[r - 1][c - 1].push_back(h);
		hidx[i] = make_pair(r - 1, c - 1);
	}

	while (ans <= 1000) {
		int flag = 0;
		int times = 1;

		for (int i = 0; i < K; i++) {
			pair<int, int> hc = hidx[i];
			vector<horse>& vh = mpHorse[hc.first][hc.second];
			int vIdx = 0;

			for (int j = 0; j < vh.size(); j++) { //vector내에서의 위치 찾기
				if (vh[j].no == i) vIdx = j;
			}

			int rnext = hc.first + rdir[vh[vIdx].dir];
			int cnext = hc.second + cdir[vh[vIdx].dir];

			if (!isValid(rnext, cnext) || (isValid(rnext, cnext) && mp[rnext][cnext] == BL)) {
				if (times == 2) {
					times = 1;
					continue;
				}
				else if (times == 1) {
					vh[vIdx].dir = (vh[vIdx].dir + 2) % 4;  //방향 바꾸기
					times++;
					i = i - 1; continue;
				}
			}

			vector<horse> newHorseVector(vh.begin() + vIdx, vh.end()); // 다 같이 이동할 말들
			
			if (isValid(rnext, cnext) && mp[rnext][cnext] == WH) {
				mpHorse[rnext][cnext].insert(mpHorse[rnext][cnext].end(), newHorseVector.begin(), newHorseVector.end());
				vh.erase(vh.begin() + vIdx, vh.end()); // 뒷 삭제
				moveAll(rnext, cnext, newHorseVector);
			}
			else if (isValid(rnext, cnext) && mp[rnext][cnext] == RD) {
				reverse(newHorseVector.begin(), newHorseVector.end());
				mpHorse[rnext][cnext].insert(mpHorse[rnext][cnext].end(), newHorseVector.begin(), newHorseVector.end());
				vh.erase(vh.begin() + vIdx, vh.end()); // 뒷 삭제
				moveAll(rnext, cnext, newHorseVector);
			}

			times = 1;
			if (mpHorse[rnext][cnext].size() >= 4) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
		ans++;
	}

	if (ans > 1000) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}
