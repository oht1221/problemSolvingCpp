#include<iostream>
#include<algorithm>

using namespace std;
int ans = 0;

int rTetro[5][4] = {
	{ 0, 0, 0, 0 },
	{ 0, 0, 1, 1 },
	{ 0, 1, 2, 2 },
	{ 0, 1, 1, 2 },
	{ 0, 0, 0, 1 }
};

int cTetro[5][4] = {
	{ 0, 1, 2, 3 },
	{ 0, 1, 0, 1 },
	{ 0, 0, 0, 1 },
	{ 0, 0, 1, 1 },
	{ 0, 1, 2, 1 }
};

int N = 0; 
int M = 0;
int board[8][500][500];

bool isValid(int i, int j) {
	return 0 <= i && i < N && 0 <= j && j < M;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a = 0;
			cin >> a;
			board[0][i][j] = a;
			board[1][i][M - j] = a;
			board[2][N - i][j] = a;
			board[3][N - i][M - j] = a;

			board[4][M - j][i] = a;
			board[5][M - j][N - i] = a;
			board[6][j][i] = a;
			board[7][j][N - i] = a;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				for (int t = 0; t < 5; t++) {
					int sum = 0;
					for (int k = 0; k < 4; k++) {
						int R = r + rTetro[t][k];
						int C = c + cTetro[t][k];
						sum += board[i][R][C];
						ans = max(ans, sum);
					}
				}
			}
		}
	}

	for (int i = 4; i < 8; i++) {
		int sum = 0;
		for (int r = 0; r < M; r++) {
			for (int c = 0; c < N; c++) {
				for (int t = 0; t < 5; t++) {
					int sum = 0;
					for (int k = 0; k < 4; k++) {
						int R = r + rTetro[t][k];
						int C = c + cTetro[t][k];
						sum += board[i][R][C];
						ans = max(ans, sum);
					}
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}
