#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i = a; i < b; i++)

using namespace std;
int r, c, k;
int mat[100][100] = { 0, };

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second < b.second;
	else if (a.second == b.second) {
		return a.first < b.first;
	}
}


int rsrt(int idx, int NC) {
	int arr[101] = { 0, };
	arr[0] = -1;
	FOR(i, 0, NC) {
		++arr[mat[idx][i]];
	}

	vector<pair<int, int>> temp;
	FOR(i, 1, 101) {
		int n = i;
		int count = arr[i];
		if (count != 0) {
			temp.push_back(make_pair(n, count));
		}
	}
	sort(temp.begin(), temp.end(), compare);
	int tmp_size = temp.size();
	FOR(i, 0, tmp_size) {
		mat[idx][2 * i] = temp[i].first;
		mat[idx][2 * i + 1] = temp[i].second;
	}
	FOR(i, tmp_size, 49) {
		mat[idx][2 * i] = 0;
		mat[idx][2 * i + 1] = 0;
	}
	return tmp_size * 2;
}

int csrt(int idx, int NR) {
	int arr[101] = { 0, };
	arr[0] = -1;
	FOR(i, 0, NR) {
		++arr[mat[i][idx]];
	}

	vector<pair<int, int>> temp;
	FOR(i, 1, 101) {
		int n = i;
		int count = arr[i];
		if (count != 0) {
			temp.push_back(make_pair(n, count));
		}
	}
	sort(temp.begin(), temp.end(), compare);

	int tmp_size = min(50, (int) temp.size());
	

	FOR(i, 0, tmp_size) {
		mat[2 * i][idx] = temp[i].first;
		mat[2 * i + 1][idx] = temp[i].second;
	}
	FOR(i, tmp_size, 50) {
		mat[2 * i][idx] = 0;
		mat[2 * i + 1][idx] = 0;
	}
	return tmp_size * 2;
}

int main() {
	cin >> r >> c >> k;
	FOR(i, 0, 3) {
		FOR(j, 0, 3) {
			cin >> mat[i][j];
		}
	}
	int ans = 0;
	int NR = 3;
	int NC = 3;
	while (mat[r - 1][c - 1] != k && ans <= 100) {
		ans++;
		if (NR >= NC) {
			int nc = 0;
			FOR(r, 0, NR) {
				nc = max(nc, rsrt(r, NC));
			}
			NC = nc;
		}
		else {
			int nr = 0;
			FOR(c, 0, NC) {
				nr = max(nr, csrt(c, NR));
			}
			NR = nr;
		}
		/*
		FOR(i, 0, NR) {
			FOR(j, 0, NC) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
		*/
	}
	if (ans > 100) cout << -1 << endl;
	else cout << ans << endl;
	
	return 0;
}
