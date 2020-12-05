#include<bits/stdc++.h>
using namespace std;

enum Polar {
	N = '0',
	S = '1'
};

enum DIR {
	RIGHT = 2,
	LEFT = 6
};

bool validNum(int n) {
	return 0 <= n && n < 4;
}

char mp[4][8];
int K = 0;

void rt(int tooth, int dir) {
	if (dir == 1) {
		char temp = mp[tooth][7];
		for (int i = 7; i > 0; i--) {
			mp[tooth][i] = mp[tooth][i - 1];
		}
		mp[tooth][0] = temp;
	}
	else if (dir == -1) {
		char temp = mp[tooth][0];
		for (int i = 0; i < 7; i++) {
			mp[tooth][i] = mp[tooth][i + 1];
		}
		mp[tooth][7] = temp;
	}
}

void func(int* arr) {
	for (int i = 0; i < 3; i++) {
		if (mp[i][RIGHT] == mp[i + 1][LEFT]) {
			arr[i] = 0;
		}
		else {
			arr[i] = 1;
		}
	}
}

void rotateAll(int init, int dir) {
	int unMatch[3];
	func(unMatch);

	rt(init, dir);
	int cur = init;
	int d = dir;
	while (validNum(cur)) {
		if (cur - 1 >= 0 && unMatch[cur - 1] == 1) {
			d *= -1;
			rt(cur - 1, d);
		}
		else break;
		cur--;
	}
	cur = init;
	d = dir;
	while (validNum(cur)) {
		if (cur + 1 < 4 && unMatch[cur] == 1) {
			d *= -1;
			rt(cur + 1, d);
		}
		else break;
		cur++;
	}
}
int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> mp[i][j];
		}
	}
	cin >> K;


	for (int i = 0; i < K; i++) {
		int num = 0; int dir = 0;
		cin >> num >> dir;
		num -= 1;
		rotateAll(num, dir);
	}

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (mp[i][0] == S) {
			ans += pow(2, i);
		}
	}
	cout << ans << '\n';
	return 0;
}
