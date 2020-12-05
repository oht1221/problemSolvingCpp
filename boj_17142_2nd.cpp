#include<bits/stdc++.h>
using namespace std;

int mp[50][50] = { 0, };
int N = 0;
int M = 0;
int ans = INT_MAX;

vector<pair<int, int>> inactives;
vector<int> choice;

int rdir[4] = { -1, 1, 0, 0 };
int cdir[4] = { 0, 0, -1, 1 };

bool finished(int const mpcpy[][50]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (mpcpy[i][j] == 0) return false;
		}
	}
	return true;
}

bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}
void spread() {
	int mpCopy[50][50];
	int visit[50][50] = { 0, };
	memcpy(mpCopy, mp, sizeof(mpCopy));
	queue<pair<int, int>> Q;
	queue<int> secQ;
	int current = -1;
	int lastModified = 0;

	for (auto const c : choice) {
		pair<int, int> v = inactives[c];
		Q.push(make_pair(v.first, v.second));
		secQ.push(0);
		visit[v.first][v.second] = 1;
	}

	while (!Q.empty()) {
		pair<int, int> a = Q.front(); Q.pop();
		int sec = secQ.front(); secQ.pop();


		for (int i = 0; i < 4; i++) {
			int rnext = a.first + rdir[i];
			int cnext = a.second + cdir[i];

			if ( isValid(rnext, cnext) && mpCopy[rnext][cnext] != 1 && visit[rnext][cnext] == 0) {
				if (mpCopy[rnext][cnext] == 0) {
					lastModified = sec + 1;
				}
				mpCopy[rnext][cnext] = 3;
				visit[rnext][cnext] = 1;
				Q.push(make_pair(rnext, cnext));
				secQ.push(sec + 1);
			}

			//if (sec + 1 >= ans) return;
		}
	}

	if (finished(mpCopy)) ans = min(ans, lastModified);
}
void comb(int idx) {
	if (ans == 0) return;

	if (inactives.size() - idx < M - choice.size()) return;

	if (choice.size() == M) {
		spread();
		return;
	}

	if (idx == inactives.size()) return;

	else {
		pair<int, int> v = inactives[idx];
		choice.push_back(idx);
		mp[v.first][v.second] = 3;
		comb(idx + 1);

		mp[v.first][v.second] = 2;
		choice.pop_back();
		comb(idx + 1);
	}
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 2) inactives.push_back(make_pair(i, j));
		}
	}

	comb(0);

	if (ans == INT_MAX) cout << -1 << '\n';
	else cout << ans << '\n';

	return 0;
}

