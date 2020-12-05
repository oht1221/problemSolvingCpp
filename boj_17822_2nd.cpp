#include<bits/stdc++.h>
using namespace std;
int N = 0;
int M = 0;
int T = 0;
int mp[50][50];
int sum = 0;
int cnt = 0;

void move(int n, int d, int k) {
	if (d == 0) {
		for (int i = 0; i < k; i++) {
			
			int temp = mp[n][0];
			for (int j = M - 1; j > 0; j--) {
				mp[n][(j + 1) % M] = mp[n][j];
			}
			mp[n][1] = temp;

		}
	}
	else if (d == 1) {
		for (int i = 0; i < M - k; i++) {

			int temp = mp[n][0];
			for (int j = M - 1; j > 0; j--) {
				mp[n][(j + 1) % M] = mp[n][j];
			}
			mp[n][1] = temp;

		}
	}
}

void moveAll(int x, int d, int k) {
	for (int i = 0; i < N; i++) {
		if ((i + 1) % x == 0) {
			move(i, d, k);
		}
	}
}
bool validN(int n) {
	return 0 <= n && n < N;
}

int del() {
	int pan[50][50];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			pan[i][j] = 1;
		}
	}

	int flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mp[i][j] != 0) {
				cnt++;
				sum += mp[i][j];

				if (mp[i][j] == mp[i][(j - 1 + M) % M]) {
					pan[i][j] = 0; pan[i][(j - 1 + M) % M] = 0;
					flag = 1;
				}
				if (mp[i][j] == mp[i][(j + 1) % M]) {
					pan[i][j] = 0; pan[i][(j + 1) % M] = 0;
					flag = 1;
				}
				if (validN(i - 1) && mp[i][j] == mp[i - 1][j]) {
					pan[i][j] = 0; pan[i - 1][j] = 0;
					flag = 1;
				}
				if (validN(i + 1) && mp[i][j] == mp[i + 1][j]) {
					pan[i][j] = 0; pan[i + 1][j] = 0;
					flag = 1;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			mp[i][j] *= pan[i][j];
		}
	}

	return flag;
}

int total() {
	int s = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			s += mp[i][j];
		}
	}

	return s;
}

void flat(double avg) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mp[i][j] != 0 && mp[i][j] > avg) mp[i][j]--;
			else if (mp[i][j] != 0 && mp[i][j] < avg) mp[i][j]++;
		}
	}
}
int main() {
	cin >> N >> M >> T;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mp[i][j];
		}
	}



	for (int i = 0; i < T; i++) {
		int x, d, k;
		cin >> x >> d >> k;

		moveAll(x, d, k);
		
		if (!del()) {
			double avg = (double) sum / (double) cnt;
			flat(avg);
		}
		sum = 0; cnt = 0;
	}


	cout << total() << '\n';

	return 0;
}
