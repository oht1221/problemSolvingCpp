#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int N = 0;
int pan[101][101] = { 0, };
vector<vector < pair<int, int> >> curves;
vector<int> gen;
int xdir[4] = { 1, 0, -1, 0 };
int ydir[4] = { 0, -1, 0, 1};
vector<pair<int, int>> square;

void spread(int n) {

	vector<pair<int, int>> & c = curves[n];
	int Size = c.size();
	pair<int, int> end = c[Size - 1];
	
	for (int i = Size - 2; i >= 0; i--) {
		int dx = c[i].first - end.first;
		int dy = c[i].second - end.second;

		swap(dx, dy);
		dx *= -1;

		int xnext = end.first + dx;
		int ynext = end.second + dy;

		c.push_back(make_pair(xnext, ynext));
		pan[ynext][xnext] = 1;
	}

}

int checkSquares() {
	int cnt = 0;
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			int ret = 1;
			for (auto p : square) {
				ret *= pan[y + p.second][x + p.first];
			}
			if (ret) cnt++;
		}
	}
	return cnt;
}
int main() {
	cin >> N;
	vector<pair<int, int>> p;
	curves.assign(N, p);
	square.push_back(make_pair(0, 0));
	square.push_back(make_pair(0, 1));
	square.push_back(make_pair(1, 0));
	square.push_back(make_pair(1, 1));

	for (int i = 0; i < N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		curves[i].push_back(make_pair(x, y));
		pan[y][x] = 1;
		curves[i].push_back(make_pair(x + xdir[d], y + ydir[d]));
		pan[y + ydir[d]][x + xdir[d]] = 1;

		gen.push_back(g);
	}

	for (int i = 0; i < curves.size(); i++) {
		for (int g = 0; g < gen[i]; g++) {
			spread(i);
		}
	}

	cout << checkSquares() << endl;

	return 0;
}
