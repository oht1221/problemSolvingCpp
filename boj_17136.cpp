#include<bits/stdc++.h>

using namespace std;
int mp[10][10] = { 0, };

int cnt = 25;
int num[5] = { 5, 5, 5, 5, 5 }; 
vector<pair<int, int>> slots;


int findSquare(int r, int c){
	int size = 1;
	int flag = 0;
	for (int i = 1; (r + i) < 10 && mp[r + i][c] == 1; i++) {
		if (size == 5) break;
		for (int j = 0; j <= i; j++) {
			if ((c + j >= 10) || (r + i >= 10) || mp[r + i][c + j] == 0) {
				flag = 1;
				break;
			}
			if ((r + j >= 10) || (c + i >= 10) || mp[r + j][c + i] == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
		size++;
	}
	return size;
}

void putPaper(int r, int c, int size) {
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			mp[i][j] = 0;
		}
	}
	return;
}

void removePaper(int r, int c, int size) {
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			mp[i][j] = 1;
		}
	}
	return;
}

bool isDone() { 
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (mp[i][j] == 1) return false;
		}
	}
	return true;
}

int counting() {
	int counting = 0;
	for (int i = 0; i < 5; i++) {
		counting += (5 - num[i]);
	}
	return counting;
}

int chooseNext(int curIdx) {
	int nextIdx = curIdx;
	int total = slots.size();

	while (nextIdx < total && mp[slots[nextIdx].first][slots[nextIdx].second] == 0) nextIdx++;

	return nextIdx;
}

void dfs(int idx) {
	if (isDone()) {
		cnt = min(cnt, counting());
		return;
	}

	else if (idx >= slots.size()) return;
	else if (counting() >= cnt) return;

	int i = slots[idx].first;
	int j = slots[idx].second;

	int maxSize = findSquare(i, j);

	for (int s = maxSize; s >= 1; s--) {
		if (num[s - 1] <= 0) continue; // 0개 이하로 남은건 pass
		putPaper(i, j, s);
		num[s - 1]--;

		int nextIdx = chooseNext(idx);
		dfs(nextIdx);

		num[s - 1]++;
		removePaper(i, j, s);
	}

}

int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> mp[i][j];
			if (mp[i][j] == 1) slots.push_back(make_pair(i, j));
		}
	}

	dfs(0);

	if (cnt == 25) cout << -1 << '\n';
	else cout << cnt << '\n';
	return 0;
}
