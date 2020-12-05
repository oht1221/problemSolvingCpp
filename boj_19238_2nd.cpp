
#include<bits/stdc++.h>>
using namespace std;
int N;
int M;
int f;
int mp[20][20];
pair<int, int> start;
vector<pair<int, int>> psg;
vector<pair<int, int>> dest;
int rdir[4] = { 0, 0, 1, -1 };
int cdir[4] = { -1, 1, 0, 0 };

bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}


pair<int, int> findPsg() {
	queue<pair<int, int>> Q;
	queue <int> distQ;
	int visit[20][20] = { 0, };
	Q.push(start);
	visit[start.first][start.second] = 1;
	distQ.push(0);
	int current = -1;
	int flag = 0;
	int initFuel = f;
	vector<pair<int, int>> candidates;
	pair<int, int> p;

	while (!Q.empty()) {
		pair<int, int> now = Q.front(); Q.pop();
		int dist = distQ.front(); distQ.pop();

		if (current < dist) {
			if (flag == 1) {
				//f = f - current;
				sort(candidates.begin(), candidates.end());
				break;
			}
			else {
				current = dist;
				f = initFuel - current;
				if (f == 0) break;
			}
		}

		if (mp[now.first][now.second] != 0 && mp[now.first][now.second] != 1) {
			candidates.push_back(make_pair(now.first, now.second));
			flag = 1;
		}

		for (int i = 0; i < 4; i++) {
			int rnext = now.first + rdir[i];
			int cnext = now.second + cdir[i];
			if (isValid(rnext, cnext) && mp[rnext][cnext] != 1 && visit[rnext][cnext] == 0) {
				Q.push(make_pair(rnext, cnext));
				visit[rnext][cnext] = 1;
				distQ.push(dist + 1);
			}
		}
	}

	if (candidates.size() > 0) return candidates.at(0);
	else {
		f = -1;
		return pair<int, int>(20, 20);
	}
}

bool same(int r1, int c1, int r2, int c2) {
	return r1 == r2 && c1 == c2;
}
int goToDest(pair<int, int> const& dstn) {
	queue<pair<int, int>> Q;
	queue <int> distQ;
	int visit[20][20] = { 0, };
	Q.push(start);
	visit[start.first][start.second] = 1;
	distQ.push(0);
	int dist;
	int flag = 0;
	int initFuel = f;
	int current = -1;

	while (!Q.empty()) {
		pair<int, int> now = Q.front(); Q.pop();
		dist = distQ.front(); distQ.pop();

		if (current < dist) {
			current = dist;
			f = initFuel - current;
			if (f < 0) break;
		}

		if (same(now.first, now.second, dstn.first, dstn.second)) {
			//f = f - dist;
			start.first = now.first;
			start.second = now.second;
			flag = 1;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int rnext = now.first + rdir[i];
			int cnext = now.second + cdir[i];
			if (isValid(rnext, cnext) && mp[rnext][cnext] != 1 && visit[rnext][cnext] == 0) {
				Q.push(make_pair(rnext, cnext));
				visit[rnext][cnext] = 1;
				distQ.push(dist + 1);
			}
		}
	}

	if (Q.empty() && flag == 0) f = -1;
	return dist;
}


int main() {
	cin >> N >> M >> f;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mp[i][j];
		}
	}
	cin >> start.first >> start.second;
	start.first -= 1;
	start.second -= 1;

	for (int i = 0; i < M; i++) {
		int sr, sc, er, ec;
		cin >> sr >> sc >> er >> ec;

		psg.push_back(make_pair(sr - 1, sc - 1));
		mp[sr - 1][sc - 1] = i + 2;
		dest.push_back(make_pair(er - 1, ec - 1));
	}

	int fail = 0;

	for (int i = 0; i < M; i++) {
		pair<int, int> psg = findPsg();
		if (f <= 0) { fail = 1; break; }

		int psgN = mp[psg.first][psg.second] - 2;
		mp[psg.first][psg.second] = 0;
		pair<int, int> destination = dest[psgN];

		start.first = psg.first;
		start.second = psg.second;

		int d = goToDest(destination);
		if (f < 0) {
			fail = 1;
			break;
		}
		f += 2 * d;
	}

	if (fail) cout << -1 << '\n';
	else cout << f << '\n';

	return 0;
}
