#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define P pair
int N = 0; int M = 0; int fuel = 0; P<int, int> taxi;
int mp[20][20];
vector<P<int, int>> psg;
vector<P<int, int>> dest;
int rdir[4] = { -1, 0, 0, 1 };
int cdir[4] = { 0, -1, 1, 0 };

void check() {
	cout << N << " " << M << " " << fuel << endl;
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cout << mp[i][j] << " ";
		}
		cout << endl;
	}

	cout << taxi.first << " " << taxi.second << endl;

	FOR(i, 0, M) {
		cout << psg[i].first << " " << psg[i].second << " " << dest[i].first << " " << dest[i].second << endl;
	}
}

int toShortest() {
	queue<P<int, int>> trace;
	queue<int> distance;
	int visit[20][20] = { 0, };
	trace.push(make_pair(taxi.first, taxi.second));
	distance.push(0);
	visit[taxi.first][taxi.second] = 1;
	int flag = 0;
	int ret = 0;
	int found = 0;
	while (!trace.empty()) {
		P<int, int> cur = trace.front(); trace.pop();
		int d = distance.front(); distance.pop();

		if (d > fuel) { // ¿¬·á µþ¸²
			flag = -1; break;
		}
		else {
			int r = cur.first; int c = cur.second;
			if (1 <= mp[r][c] && mp[r][c] <= M) { // ½Â°´ Ã£À½
				int psg_n = mp[r][c];
				mp[r][c] = 0;
				fuel -= d; //¿¬·á ¼Òºñ 
				taxi.first = r; taxi.second = c; // ½Â°´¿¡°Ô ÀÌµ¿
				queue<P<int, int>> trace_dest;
				queue<int> distance_dest;
				int visit_dest[20][20] = { 0, };

				trace_dest.push(make_pair(r, c));
				distance_dest.push(0);
				visit_dest[r][c] = 1;
				while (!trace_dest.empty()) {
					P<int, int> cur_dest = trace_dest.front(); trace_dest.pop();
					int d_dest = distance_dest.front(); distance_dest.pop();
					if (d_dest > fuel) {  // ¿¬·á µþ¸²
						flag = -1; break;
					}
					else {
						int r_dest = cur_dest.first; int c_dest = cur_dest.second;
						if (mp[r_dest][c_dest] == psg_n + M) { //µµÂøÁö Ã£À½
							fuel += d_dest;
							taxi.first = r_dest; taxi.second = c_dest;
							mp[r_dest][c_dest] = 0;
							found = 1;
							break;
						}
						else {
							FOR(i, 0, 4) {
								int nr_dest = r_dest + rdir[i]; int nc_dest = c_dest + cdir[i];
								if (0 <= nr_dest && nr_dest < N && 0 <= nc_dest && nc_dest < N && mp[nr_dest][nc_dest] != -1 && visit_dest[nr_dest][nc_dest] == 0 && d_dest <= fuel) {
									trace_dest.push(make_pair(nr_dest, nc_dest));
									distance_dest.push(d_dest + 1);
									visit_dest[nr_dest][nc_dest] = 1;
								}
							}
						}
					}
				}
				break;
			}
			else {
				FOR(i, 0, 4) {
					int nr = r + rdir[i]; int nc = c + cdir[i];
					if (0 <= nr && nr < N && 0 <= nc && nc < N && mp[nr][nc] != -1 && visit[nr][nc] == 0 && d <= fuel) {
						trace.push(make_pair(nr, nc));
						distance.push(d + 1);
						visit[nr][nc] = 1;
					}
				}
			}
		}
	}

	if (!found) ret = -1;

	return ret;
}

int main() {
	cin >> N >> M >> fuel;
	FOR(i, 0, N) FOR(j, 0, N) {
		int a; cin >> a;
		mp[i][j] = a * (-1);
	}
	cin >> taxi.first >> taxi.second;
	taxi.first--; taxi.second--;
	FOR(i, 0, M) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		mp[a - 1][b - 1] = i + 1;
		mp[c - 1][d - 1] = i + 1 + M;
		psg.push_back(make_pair(a - 1, b - 1));
		dest.push_back(make_pair(c - 1, d - 1));
	}

	FOR(i, 0, M) {
		int ret = toShortest();
		if (ret == -1) {
			fuel = -1; break;
		}
	}
	cout << fuel << endl;
}

