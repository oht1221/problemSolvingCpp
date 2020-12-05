#include<bits/stdc++.h>
using namespace std;
int N, M;
int mp[50][50];
vector<pair<int, int>> houses;
vector<pair<int, int>> chks;
vector<int> choice;
int rdir[4] = { -1, 0, 1, 0 };
int cdir[4] = { 0, 1, 0, -1 };
int ans = INT_MAX;

int isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

int dist(int r1, int c1, int r2, int c2) {
	return abs(r1 - r2) + abs(c1 - c2);
}
int countDist() {
	int sum = 0;
	for (auto h : houses) {
		int dis = INT_MAX;
		for (auto x : choice) {
			dis = min(dis, dist(h.first, h.second, chks[x].first, chks[x].second));
		}
		sum += dis;
		if (sum >= ans) break;
	}
	return sum;
}

void comb(int n) {
	if (choice.size() == M) {
		ans = min(ans, countDist());
		return;
	}

	if (M - choice.size() > chks.size() - n) {
		return;
	}

	if (n == chks.size()) {
		return;
	}

	pair<int, int> chk = chks[n];
	choice.push_back(n);
	mp[chk.first][chk.second] = 2;
	comb(n + 1);
	mp[chk.first][chk.second] = 0;
	choice.pop_back();
	comb(n + 1);
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 2) {
				chks.push_back(make_pair(i, j));
				mp[i][j] = 0;
			}
			else if (mp[i][j] == 1) {
				houses.push_back(make_pair(i, j));
			}
		}
	}

	comb(0);
	cout << ans << endl;
	return 0;
}
