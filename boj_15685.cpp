#include<iostream>
#include<vector>

using namespace std;
vector<pair<int, int>> end_point;
vector<vector<int>> X;
vector<vector<int>> Y;
vector<vector<int>> curves;
vector<int> generation;
int table[101][101] = { 0, };

void print(int n) {
	for (int i = 0; i < n; i++) {
		cout << i << endl;
		for (int j = 0; j < X[i].size(); j++) {
			cout << X[i][j] << " " << Y[i][j] << endl;
		}
		cout << end_point[i].first << end_point[i].second << endl;
		cout << endl;
	}
}

bool isSquare(int i, int j) {

	if (table[i][j] == 1 && table[i + 1][j] == 1 && table[i][j + 1] == 1 && table[i + 1][j + 1] == 1) {

		return 1;
	}
	else {
		return 0;
	}
}
void dragon(int i) {
	int gen = generation[i];
	int x = end_point[i].first; 
	int y = end_point[i].second;

	for (int g = 0; g < gen; g++) {
		int len = curves[i].size();

		for (int j = len - 1; j >= 0; j--) {
			int dir = curves[i][j];
			if (dir == 0) {
				curves[i].push_back(1);
				y = y - 1;
			}
			else if (dir == 1) {
				curves[i].push_back(2);
				x = x - 1;
			}
			else if (dir == 2) {
				curves[i].push_back(3);
				y = y + 1;
			}
			else if (dir == 3) {
				curves[i].push_back(0);
				x = x + 1;
			}
			X[i].push_back(x); 
			Y[i].push_back(y);
		}
	}
	
	end_point[i] = make_pair(x, y);
}
int main() {
	int n = 0;
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		vector<int> arr1;
		vector<int> arrX;
		vector<int> arrY;

		int x = 0; int y = 0; int dir = 0; int gen = 0;
		cin >> x >> y >> dir >> gen;
		arr1.push_back(dir);
		
		if (dir == 0) {
			end_point.push_back(make_pair(x + 1, y));
			arrX.push_back(x); arrX.push_back(x + 1);
			arrY.push_back(y); arrY.push_back(y);
		}
		else if (dir == 1) {
			end_point.push_back(make_pair(x, y - 1));
			arrX.push_back(x); arrX.push_back(x);
			arrY.push_back(y); arrY.push_back(y - 1);
		}
		else if (dir == 2) {
			end_point.push_back(make_pair(x - 1, y));
			arrX.push_back(x); arrX.push_back(x - 1);
			arrY.push_back(y); arrY.push_back(y);
		}
		else if (dir == 3) {
			end_point.push_back(make_pair(x, y + 1));
			arrX.push_back(x); arrX.push_back(x);
			arrY.push_back(y); arrY.push_back(y + 1);
		}
		curves.push_back(arr1);
		generation.push_back(gen);
		X.push_back(arrX);
		Y.push_back(arrY);
	}

	for (int i = 0; i < n; i++) {
		dragon(i);
	}

	//print(n);

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < X[i].size(); j++){
			int x = X[i][j];
			int y = Y[i][j];
			table[x][y] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (isSquare(i, j)) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}