#include<vector>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int N = 0;
int pop[20][20] = { 0, };
int ans = INT_MAX;

bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}
void action5(vector<vector<int>>& pan, int x, int y, int d1, int d2) {
	for (int i = 0; i <= d1; i++) {
		pan[x + i][y - i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		pan[x + i][y + i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		pan[x + d1 + i][y - d1 + i] = 5;
	}
	for (int i = 0; i < d1; i++) {
		pan[x + d2 + i][y + d2 - i] = 5;
	}
	for (int i = x + 1; i <= x + d1; i++) {
		int j = y - (i - x);
		while (isValid(i, j + 1) && pan[i][j + 1] == 0) {
			pan[i][j + 1] = 5;
			j++;
		}
	}
	for (int i = x + d1 + 1; i < x + d1 + d2; i++) {
		int j = y - d1 + (i - (x + d1));
		while (isValid(i, j + 1) && pan[i][j + 1] == 0) {
			pan[i][j + 1] = 5;
			j++;
		}
	}
}
void action1(vector<vector<int>>& pan, int x, int y, int d1, int d2) {
	for (int i = 0; i < x + d1; i++) {
		for (int j = 0; j <= y; j++) {
			if (pan[i][j] != 5) {
				pan[i][j] = 1;
			}
		}
	}
}
void action2(vector<vector<int>>& pan, int x, int y, int d1, int d2) {
	for (int i = 0; i <= x + d2; i++) {
		for (int j = y + 1; j < N; j++) {
			if (pan[i][j] != 5) {
				pan[i][j] = 2;
			}
		}
	}
}
void action3(vector<vector<int>>& pan, int x, int y, int d1, int d2) {
	for (int i = x + d1; i < N; i++) {
		for (int j = 0; j < y - d1 + d2; j++) {
			if (pan[i][j] != 5) {
				pan[i][j] = 3;
			}
		}
	}
}
void action4(vector<vector<int>>& pan, int x, int y, int d1, int d2) {
	for (int i = x + d2 + 1; i < N; i++) {
		for (int j = y - d1 + d2; j < N; j++) {
			if (pan[i][j] != 5) {
				pan[i][j] = 4;
			}
		}
	}
}
int calcPop(int n, vector<vector<int>> const & pan) {
	
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (pan[i][j] == n) {
				sum += pop[i][j];
			}
		}
	}
	return sum;
}
void area1234(vector<vector<int>>& pan, int x, int y, int d1, int d2) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (pan[i][j] != 5) {
				if (0 <= i && i < x + d1 && 0 <= j && j <= y) pan[i][j] = 1;
				else if (0 <= i && i <= x + d2 && y < j && j < N) pan[i][j] = 2;
				else if (x + d1 <= i && i < N && 0 <= j && j < y - d1 + d2) pan[i][j] = 3;
				else if (x + d2 < i && i < N && y - d1 + d2 <= j && j < N) pan[i][j] = 4;
			}
		}
	}
}
void area5(vector<vector<int>>& pan, int x, int y, int d1, int d2) {
	for (int i = 0; i <= d1; i++) {
		pan[x + i][y - i] = 5;
		pan[x + d2 + i][y + d2 - i] = 5;
	}

	for (int i = 0; i <= d2; i++) {
		pan[x + i][y + i] = 5;
		pan[x + d1 + i][y - d1 + i] = 5;
	}

	for (int i = 1; i <= d1; i++) {
		int r = x + i;
		int c = y - i;

		while (pan[r][c + 1] != 5) {
			pan[r][c + 1] = 5;
			c = c + 1;
		}
	}

	for (int i = 1; i < d2; i++) {
		int r = x + d1 + i;
		int c = y - d1 + i;

		while (pan[r][c + 1] != 5) {
			pan[r][c + 1] = 5;
			c = c + 1;
		}
	}
}

void action(vector<vector<int>>& pan, int x, int y, int d1, int d2) {

	action5(pan, x, y, d1, d2);
	action1(pan, x, y, d1, d2);
	action2(pan, x, y, d1, d2);
	action3(pan, x, y, d1, d2);
	action4(pan, x, y, d1, d2);
}
int calcDiff(vector<int> const & population, vector<vector<int>> const& pan) {

	int Max = INT_MIN; int Min = INT_MAX;
	for (int i = 0; i < 5; i++) {
		Max = max(Max, population[i]);
		Min = min(Min, population[i]);
	}
	return Max - Min;
}

bool validD1D2(int x, int y, int d1, int d2) {
	return (
		x + d1 + d2 < N &&
		0 <= y - d1 &&
		y + d2 < N
		);
}
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> pop[i][j];
		}
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			for (int d1 = 1; d1 < N - 1; d1++) {
				for (int d2 = 1; d2 < N - 1; d2++) {
					if (!validD1D2(x, y, d1, d2)) continue;
					vector<vector<int>> pan(N, vector<int>(N, 0));
					vector<int> population; population.assign(5, 0);
					action(pan, x, y, d1, d2);
					for (int i = 0; i < 5; i++) {
						population[i] = calcPop(i + 1, pan);
					}
					ans = min(calcDiff(population, pan) , ans);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
