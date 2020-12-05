#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

enum _POLAR {
	N = '0',
	S  = '1'
};

enum _DIR {
	CCW = -1,
	CW = 1
};

vector<vector<char>> teeth;
vector<vector<int>> Rotate;
int K = 0;

void rt(int num, int dir) {
	switch(dir) {
		case 1:
			rotate(teeth[num].rbegin(), teeth[num].rbegin() + 1, teeth[num].rend());
			break;

		case -1:
			rotate(teeth[num].begin(), teeth[num].begin() + 1, teeth[num].end());
			break;
	}
}
void rtAll(int dir, int num) {
	int check[4] = { 0, 0, 0,0, };
	check[num] = dir;
	int d = dir;
	for (int i = num - 1; i >= 0; i--) {
		if (teeth[i][2] != teeth[i + 1][6]) {
			check[i] = d * (-1);
			d = d * (-1);
		}
		if (check[i] == 0) break;
	}
	d = dir;
	for (int i = num + 1; i < 4; i++) {
		if (teeth[i][6] != teeth[i - 1][2]) {
			check[i] = d * (-1);
			d = d * (-1);
		}
		if (check[i] == 0) break;
	}

	for (int i = 0; i < 4; i++) {
		if (check[i] != 0) {
			rt(i, check[i]);
		}
	}
}

int main() {
	vector<char> row(8, '0');
	teeth.assign(4, row);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> teeth[i][j];
		}
	}
	cin >> K;

	vector<int> row2(2, 0);
	Rotate.assign(K, row2);

	for (int i = 0; i < K; i++) {
		cin >> Rotate[i][0] >> Rotate[i][1];
		Rotate[i][0]--;
	}

	for (int i = 0; i < K; i++) {
		int num = Rotate[i][0];
		int dir = Rotate[i][1];

		rtAll(dir, num);
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		ans += ( teeth[i][0] - 48)* pow(2, i);
	}
	cout << ans << '\n';
	return 0;
}
