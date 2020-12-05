#include<bits/stdc++.h>
using namespace std;
int arr[50][9] = { 0, };
int N = 0;
int order[9]; //타순
int visit[9]; //선수 등번호
int ans = 0;

int hit(int* arr, int type) {
	int run = 0;
	for (int i = 2; i >= 0; i--) {
		if (arr[i] == 0) continue;

		int moved = i + type;

		if (moved >= 3)	run++;
		else arr[moved] = 1;

		arr[i] = 0;
	}
	arr[type - 1] = 1;

	return run;
}

int homerun(int* arr) {
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		cnt += arr[i];
		arr[i] = 0;
	}
	return cnt + 1;
}

int score() {
	int inning = 1;
	int run = 0;
	int cur = 0;
	while (inning <= N) {
		int out = 0;
		int bases[3] = { 0, 0, 0};

		while (1) {
			int batter = order[cur];
			int play = arr[inning - 1][batter - 1];
			switch (play) {
				case 0:
					out++;
					break;
				case 1:
					run += hit(bases, 1);
					break;
				case 2:
					run += hit(bases, 2);
					break;
				case 3:
					run += hit(bases, 3);
					break;
				case 4: 
					run += homerun(bases);
					break;
			}
			cur = (cur + 1) % 9;
			if (out == 3) {
				break;
			}
		}

		inning++;
	}

	return run;
}

void comb(int idx) {
	if (idx >= 9) {
		ans = max(ans, score());
		return;
	}

	for (int i = 1; i < 10; i++) {
		if (visit[i - 1] == 1) continue;
		
		order[idx] = i;
		visit[i - 1] = 1;

		if (idx == 2) comb(idx + 2);
		else comb(idx + 1);

		visit[i - 1] = 0;
		order[idx] = 0;
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
		}
	}

	order[3] = 1;
	visit[0] = 1;

	comb(0);

	cout << ans << '\n';
	return 0;
}
