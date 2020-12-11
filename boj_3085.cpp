#include<iostream>
#include <algorithm>
#include<string.h>
using namespace std;

char board[50][50] = { 0, };
int N = 0;
int visit[50][50] = { 0, };
int rdir[2] = { 1, 0};
int cdir[2] = { 0, 1};
int lgst = 0;

bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char temp = board[i][j];
			for (int k = 0; k < 2; k++) {
				int iRepl = i + rdir[k];
				int jRepl = j + cdir[k];
				swap(board[i][j], board[iRepl][jRepl]);
				if (isValid(iRepl, jRepl)) {
					for (int a = 0; a <= rdir[k]; a++) {
						int len = 0;
						char prev = board[i + a][0];
						for (int b = 0; b < N; b++) {
							if (prev == board[i + a][b]) {
								len++;
								lgst = max(len, lgst);
							}
							else len = 1;
							prev = board[i + a][b];
						}
					}
					for (int b = 0; b <= cdir[k]; b++) {
						int len = 0;
						char prev = board[0][j + b];
						for (int a = 0; a < N; a++) {
							if (prev == board[a][j + b]) {
								len++;
								lgst = max(len, lgst);
							}
							else len = 1;
							prev = board[a][j + b];
						}
					}
				}
				swap(board[i][j], board[iRepl][jRepl]);
			}
		}
	}

	cout << lgst << endl;
	return 0;
}
