#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

enum _DIR {
	CW,
	CCW
};
int N, M, T;
vector<vector<int>> pan;
vector<vector<int>> rot;
bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < M;
}
void Rotate(int n, int k, int d) {
	
	if (d == CW) {
		rotate(pan[n].rbegin(), pan[n].rbegin() + k, pan[n].rend());
	}
	else if (d == CCW) {
		rotate(pan[n].begin(), pan[n].begin() + k, pan[n].end());
	}
}
int Del() {
	vector < vector<int >> candid;
	candid.assign(N, vector<int>(M, 0));
	int flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int val = pan[i][j];
			if (val == 0)continue;

			if (isValid(i - 1, j) && val == pan[i - 1][j]) {  //인접 원판
				flag = 1;
				candid[i - 1][j] = 1;
			}
			if (isValid(i + 1, j) && val == pan[i + 1][j]) {  //인접 원판
				flag = 1;
				candid[i + 1][j] = 1;
			}
			if (val == pan[i][(j + 1) % M]) {  //원판 내 인접
				flag = 1;
				candid[i][(j + 1) % M] = 1;
			}
			if (val == pan[i][(j - 1 + M) % M]) {  //원판 내 인접
				flag = 1;
				candid[i][(j - 1 + M) % M] = 1;
			}
		}
	}
	if (flag == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (candid[i][j] == 1) {
					pan[i][j] = 0;
				}
			}
		}

	}
	return flag;
}
int Sum() {
	int sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum += pan[i][j];
		}
	}

	return sum;
}

double Avg() {
	double avg = 0;
	double cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			avg += pan[i][j];
			if (pan[i][j] != 0) cnt++;
		}
	}
	avg /= cnt;
	return avg;
}

int main() {
	cin >> N >> M >> T;
	pan.assign(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> pan[i][j];
		}
	}
	rot.assign(T, vector<int>(3, 0));

	for (int i = 0; i < T; i++) {
		cin >> rot[i][0] >> rot[i][1] >> rot[i][2];
	}
	int t = 0;
	while (t < T) {
		int x = rot[t][0]; int d = rot[t][1]; int k = rot[t][2];

		for (int i = 0; i < N; i++) {
			if ((i + 1) % x == 0) {//x배수
				Rotate(i, k, d);
			}
		}

		int result = Del();
		if (result == 0) {
			double avg = Avg();
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (pan[i][j] != 0) {
						if (pan[i][j] > avg) {
							pan[i][j] -= 1;
						}
						else if (pan[i][j] < avg) {
							pan[i][j] += 1;
						}
					}
				}
			}
		}

		t++;
	}

	cout << Sum() << endl;
	return 0;
}
