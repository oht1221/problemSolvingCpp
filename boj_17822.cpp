#include<vector>
#include<iostream>
using namespace std;
int circles[50][50] = { -1, };
int N, M, T;
#define REP(i, a, b); for (int i = a; i < b; i++)

int adj[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

void rot(int no, int d, int k) {
	vector<int> que;
	REP(i, 0, M) que.push_back(circles[no][i]);
	
	if (d == 0) {
		REP(i, 0, M) {
			circles[no][(i + k) % M] = que[i];
		}
	}
	else if (d == 1) {
		REP(i, 0, M) {
			if(i - k < 0) circles[no][(i - k) % M + M] = que[i];
			else if(i - k >= 0) circles[no][(i - k) % M] = que[i];
		}
	}
}

void func(){
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << circles[i][j] << " ";
		}
		cout << '\n';
	}
}

 int main() {
	 vector<vector<int>> xdk;
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> circles[i][j];
		}
	}

	for (int i = 0; i < T; i++) {
		int x, d, k; vector<int> temp;
		cin >> x >> d >> k;
		temp.push_back(x); temp.push_back(d); temp.push_back(k); xdk.push_back(temp);
	}

	for (int i = 0; i < T; i++) {
		int x = xdk[i][0]; int d = xdk[i][1]; int k = xdk[i][2];
		int cnt = 0;
		
		for (int j = 0; j < N; j++) {
			if ((j + 1) % x == 0) rot(j, d, k);
		}

		int temp[50][50];
		REP(n, 0, N) {
			REP(m, 0, M) {
				temp[n][m] = circles[n][m];
			}
		}

		REP(k, 0, N) {
			REP(p, 0, M) {
				REP(a, 0, 4) {
					int n = k + adj[a][0]; int m = p + adj[a][1];
					if (0 <= n && n < N) {
						if (circles[k][p] != 0 && circles[k][p] == circles[n][(m + M) % M]) {
							temp[k][p] = 0;
							temp[n][(m + M )% M] = 0;
							cnt++;
						}
					}
				}
			}
		}

		if (cnt > 0) {
			REP(n, 0, N) {
				REP(m, 0, M) {
					circles[n][m] = temp[n][m];
				}
			}
		}
		else {
			double avg = 0;
			double non_zero = 0;
			REP(n, 0, N) {
				REP(m, 0, M) {
					avg += circles[n][m];
					if(circles[n][m] != 0) non_zero += 1;
				}
			}
			avg = avg / non_zero;
			REP(n, 0, N) {
				REP(m, 0, M) {
					if (circles[n][m] == 0) continue;
					if((double) circles[n][m] > avg) circles[n][m] -= 1;
					else if((double) circles[n][m] < avg) circles[n][m] += 1;
				}
			}
		}
	}
	int ans = 0;
	REP(n, 0, N) {
		REP(m, 0, M) {
			ans += circles[n][m];
		}
	}
	cout << ans << endl;
	return 0;
}