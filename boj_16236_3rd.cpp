#include<set>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int rdir[4] = { -1, 0, 0, 1 };
int cdir[4] = { 0, -1, 1, 0 };
int N = 0;
int sharkR;
int sharkC;
int pan[20][20] = { 0, };
int sharkSize = 2;
int eaten = 0;
int ans = 0;
int targetDist = 0;

bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

set<pair<int, int>> findFish() {

	vector<vector<int>> visit(N, vector<int>(N, 0));
	set<pair<int, int>> candid;
	queue<pair<int, int>> Q;
	queue<int> Qdist;

	Q.push(make_pair(sharkR, sharkC));
	Qdist.push(0);

	int current = -1;
	visit[sharkR][sharkC] = 1;
	while (!Q.empty()) {

		int r = Q.front().first;
		int c = Q.front().second;
		Q.pop();
		int dist = Qdist.front();
		Qdist.pop();

		if (current < dist) {
			current++;
			if (candid.size() > 0) break;
		}

		for (int i = 0; i < 4; i++) {
			int rnext = r + rdir[i];
			int cnext = c + cdir[i];
			if (isValid(rnext, cnext)) {
				if (visit[rnext][cnext] == 0) {
					if (pan[rnext][cnext] == 0 || pan[rnext][cnext] == sharkSize) { //0 이거나 같은 크기 물고기면 탐색 가능
						Q.push(make_pair(rnext, cnext));
						visit[rnext][cnext] = 1;
						Qdist.push(dist + 1);
					}
					else if (pan[rnext][cnext] < sharkSize) { //작으면 먹음
						candid.insert(make_pair(rnext, cnext));
						targetDist = dist + 1;
						visit[rnext][cnext] = 1;
					}
				}
			}
		}
	}
	return candid;
}
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> pan[i][j];
			if (pan[i][j] == 9) {
				sharkR = i;
				sharkC = j;
				pan[i][j] = 0;
			}
		}
	}

	while (1) {
		set<pair<int, int>> Candid = findFish();

		if (Candid.size() == 0) break;
		else {
			pair<int, int> target = *Candid.begin();
			sharkR = target.first; //상어 이동
			sharkC = target.second;
			pan[target.first][target.second] = 0; // 먹음
			eaten++;
			if (sharkSize == eaten) {
				sharkSize++;
				eaten = 0;
			}
			ans += targetDist;
			targetDist = 0;
		}
	}

	cout << ans << endl;

	return 0;
}
