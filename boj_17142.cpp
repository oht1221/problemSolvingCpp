#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i < b; i++)
const char nl = '\n';
using namespace std;
int ans = -1;
int N, M = 0;
int lab[50][50] = { -1, };
int visit[50][50] = { 0, };
vector<pair<int, int>> vir;
vector<pair<int, int>> ac;

int rdir[4] = { -1, 0, 1, 0 };
int cdir[4] = { 0, 1, 0, -1 };
void check(int arr[][50]) {

	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cout << arr[i][j] << " ";
		}  
		cout << endl;
	}
}
void simulate(int arr[][50], queue<pair<int, int>>& Q, queue<int>& sec) {
	pair<int, int> v;
	int tmp = 0;
	int flag = 0;
	while (!Q.empty()) {
		v = Q.front(); Q.pop();
		int sc = sec.front(); sec.pop();
		 // 이전 조합에서 나온 ans보다 크면 더 이상 해볼 필요 없음
		if (arr[v.first][v.second] != 2) {
			tmp = sc;
			arr[v.first][v.second] = 2;
		}
		if (ans != -1 && tmp >= ans) { flag = 1; break; }

		FOR(l, 0, 4) {
			int rn = v.first + rdir[l]; int cn = v.second + cdir[l];
			if (rn >= 0 && rn < N && cn >= 0 && cn < N && arr[rn][cn] != 1 && visit[rn][cn] == 0) {
				Q.push(make_pair(rn, cn));	sec.push(sc + 1);
				visit[rn][cn] = 1;
			}
		}
	}
	if (flag) return;
	int zcnt = 0;
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (arr[i][j] == 0) { zcnt++; break; }
		}
		if (zcnt != 0) break;
	}
	if (0 == zcnt)ans = tmp;
}

void dfs(int idx) {
	if (ac.size() - M == 0) {// 활성
		int arr[50][50];
		FOR(i, 0, N) {
			FOR(j, 0, N) visit[i][j] = 0;
		}
		memcpy(arr, lab, sizeof(lab));
		queue<pair<int, int>> Q;
		queue<int> sec;

		FOR(i, 0, M) {
			Q.push(make_pair(ac[i].first, ac[i].second)); 
			sec.push(0);
			visit[ac[i].first][ac[i].second] = 1;
			arr[ac[i].first][ac[i].second] = 2;
		}
		simulate(arr, Q, sec); //cout << ans << endl;
		return;
	}
	if (idx == vir.size()) return;
	if (vir.size() - idx < M - ac.size()) return;
	ac.push_back(vir[idx]);
	dfs(idx + 1);
	ac.pop_back();
	dfs(idx + 1);
}


int main() {
	cin >> N >> M;

	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cin >> lab[i][j];
			if (lab[i][j] == 2) {
				vir.push_back(make_pair(i, j));
				lab[i][j] = 2;
			}
		}
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}

/*
int comb[5] = { 1, 2, 3, 4, 5 };
vector<int> chosen;
void dfs(int idx) {
	if (chosen.size() - M == 0) {// 활성
		FOR(i, 0, M) {
			cout << chosen[i] << " ";
		}
		cout << nl;
		return;
	}
	if (idx == 5) return;
	if (5 - idx < M - chosen.size()) return;
	chosen.push_back(comb[idx]);
	dfs(idx + 1);
	chosen.pop_back();
	dfs(idx + 1);
}
int main() {
	M = 3;
	dfs(0);
	return 0;
}
*/