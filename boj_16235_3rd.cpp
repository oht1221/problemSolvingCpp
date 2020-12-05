
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int N; int M;
int K = 0;
int A[10][10] = { 0, };

vector<vector<vector<int>>> feild;
vector < vector < int>> nutrition;
vector <vector<int>> deadNut;

int rdir[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int cdir[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}
void spring() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			vector<int>& trees = feild[i][j];
			int Size = trees.size();
			if (Size> 0) {
				int &cellNut = nutrition[i][j];

				auto it = trees.begin();
				while(it != trees.end()) {
					if (*it <= cellNut) {
						cellNut -= *it;
						(*it)++;
						it++;
					}
					else {
						deadNut[i][j] += (*it) / 2;
						it = trees.erase(it);
					}
				}

			}
		}
	}
}

void summer(){

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			nutrition[i][j] += deadNut[i][j];
		}
	}
}

void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			vector<int>& trees = feild[i][j];
			int Size = trees.size();
			
			for (auto it = trees.begin(); it != trees.end(); it++) {
				if ((*it) % 5 == 0) {
					for (int l = 0; l < 8; l++) {
						int rnext = i + rdir[l];
						int cnext = j + cdir[l];
						if (isValid(rnext, cnext)) {
							feild[rnext][cnext].insert(feild[rnext][cnext].begin(), 1);
						}
					}
				}
			}
		}
	}
}


void winter() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			nutrition[i][j] += A[i][j];
		}
	}
}

int main() {


	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}

	nutrition.assign(N, vector<int>(N, 5));
	vector<vector<int>> a(N, vector<int>(N, 0));
	feild.assign(N, vector <vector<int>> (N));

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		feild[x - 1][y - 1].insert(feild[x - 1][y - 1].begin(), z);
	}


	while (K--) {
		deadNut.assign(N, vector<int>(N, 0));
		spring();
		summer();
		fall();
		winter();
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ans += feild[i][j].size();
		}
	}

	cout << ans << endl;
	return 0;
}
