#include <iostream>
#include <algorithm>
#include <vector>
#include<queue>
#include<map>
using namespace std;

#define lli long long int;
int ans = 0;
int M;
int N;
int fuel;
int pan[20][20];
vector<vector<int>> psg;
pair<int, int> taxi;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1 ,1 };
map<pair<int, int>, int> table1;
map<int, pair<int, int>> table2;

bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}
void bfs(vector<pair<int, int>> &found) {
	queue<pair<int, int>>Q;
	queue<int> Qdist;
	int r = taxi.first;
	int c = taxi.second;
	Q.push(make_pair(r, c));
	Qdist.push(0);
	int visit[20][20] = { 0, };
	visit[r][c] = 1;
	int current  = -1;

	while (!Q.empty()) {
		pair<int, int> pos = Q.front(); Q.pop();
		int dist = Qdist.front(); Qdist.pop();
		int x = pos.first; int y = pos.second;

		if (current < dist) {
			if (found.size() != 0) {
				break;
			}
			current = dist;
		}

		if (pan[x][y] != 0) {
			found.push_back(make_pair(x, y)); //찾았으면 후보에 추가
		}


		for (int i = 0; i < 4; i++) {
			int xnext = x + dx[i];
			int ynext = y + dy[i];
			if (isValid(xnext, ynext)) {
				if (visit[xnext][ynext] == 0 && pan[xnext][ynext] != -1) {
					visit[xnext][ynext] = 1;
					Q.push(make_pair(xnext, ynext));
					Qdist.push(dist + 1);
				}
			}
		}
	}

	if (found.size() != 0) {
		if ((fuel - current) <= 0) {//손님 출발지에서 연료 0보다 작으면 끝 (목적지랑 출발지 무조건 다름)
			found.clear();
		}
		else {
			fuel -= (current);  //아니면 거리만큼 연료 소비
		}
	}
}

void toDest(pair<int, int> dest) {

	queue<pair<int, int>>Q;
	queue<int> Qdist;
	int r = taxi.first;
	int c = taxi.second;
	Q.push(make_pair(r, c));
	Qdist.push(0);
	int visit[20][20] = { 0, };
	visit[r][c] = 1;
	int Dist = -1;
	int flag = 0;

	while (!Q.empty()) {
		pair<int, int> pos = Q.front(); Q.pop();
		int dist = Qdist.front(); Qdist.pop();
		int x = pos.first; int y = pos.second;
		for (int i = 0; i < 4; i++) {
			int xnext = x + dx[i];
			int ynext = y + dy[i];
			if (isValid(xnext, ynext)) {
				if (visit[xnext][ynext] == 0 && pan[xnext][ynext] != -1) {
					visit[xnext][ynext] = 1;
					Q.push(make_pair(xnext, ynext));
					Qdist.push(dist + 1);
					if (xnext == dest.first && ynext == dest.second) { //목적지 찾았다
						Dist = dist + 1;
						flag = 1;
						break;
					}
				}
			}
		}
		if (flag == 1) break; // 찾았으면 그만
	}

	if (flag == 1) {
		if ((fuel - Dist) < 0) { // 도착지 까지 도착 못하는 연료면 
			fuel -= Dist;
		}
		else {
			fuel -= Dist;  //아니면 거리만큼 연료 소비
			fuel += 2 * Dist;
		}
	}
	else fuel = -1;
}
int main() {
	cin >> N >> M >> fuel;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> pan[i][j];
			if (pan[i][j] == 1) pan[i][j] = -1;
		}
	}

	cin >> taxi.first >> taxi.second;
	taxi.first--; taxi.second--;

	psg.assign(M, vector<int>(4, 0));
	for (int i = 0; i < M; i++) {
		cin >> psg[i][0] >> psg[i][1] >> psg[i][2] >> psg[i][3]; 
		psg[i][0]--;
		psg[i][1]--;
		psg[i][2]--;
		psg[i][3]--;
		table1[make_pair(psg[i][0], psg[i][1])] = i + 1;
		table2[i + 1] = make_pair(psg[i][2], psg[i][3]);
		pan[psg[i][0]][psg[i][1]] = i + 1;
	}

	for (int i = 0; i < M; i++) {
		vector<pair<int, int>> found;
		bfs(found);
		if (found.size() > 0) {
			sort(found.begin(), found.end());
			pair<int, int> target = found[0];
			taxi.first = target.first; taxi.second = target.second; //택시 이동
			pan[target.first][target.second] = 0;
			int psgN = table1[target];
			pair<int, int> dest = table2[psgN];
			toDest(dest);
			if (fuel < 0) {
				ans = -1;
				break;
			}
			else {
				taxi.first = dest.first; taxi.second = dest.second; //택시 이동
			}
		}
		else {
			ans = -1;
			break;
		}
	}

	if (ans == -1) cout << ans << endl;
	else cout << fuel << endl;
	return 0;
}
