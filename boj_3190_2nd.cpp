#include<bits/stdc++.h>
using namespace std;
int mp[100][100];
int N = 0;
int K = 0;
int L = 0;
int direction = 3;

deque<pair<int, int>> snake;

int seconds = 0;
queue<pair<int, char>> turn;
int rdir[4] = { -1, 0, 1, 0 };
int cdir[4] = { 0, -1, 0, 1 };

void turnRight() {
	direction = (direction - 1 + 4) % 4;
}

void turnLeft() {
	direction = (direction + 1) % 4;
}

bool valid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}

bool move (){
	int headR = snake.front().first + rdir[direction]; //늘인 목
	int headC = snake.front().second + cdir[direction];

	if (!valid(headR, headC) || (valid(headR, headC) && mp[headR][headC] == 1)) { //충돌
		return false;
	}

	if (valid(headR, headC) && mp[headR][headC] == 0) {
		mp[snake.back().first][snake.back().second] = 0;
		snake.pop_back();
	}

	snake.push_front(make_pair(headR, headC));
	mp[snake.front().first][snake.front().second] = 1;

	return true;
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int r = 0; int c = 0;
		cin >> r >> c;
		mp[r - 1][c - 1] = 2; //사과
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int time; char dir;
		cin >> time >> dir;
		turn.push(make_pair(time, dir));
	}

	snake.push_front(make_pair(0, 0));
	mp[snake.front().first][snake.front().second] = 1;

	while (1) {
		bool result = move();
		seconds++;
		if (result == false) break;
		if (!turn.empty() && seconds == turn.front().first) {
			if (turn.front().second == 'L')	turnLeft();
			else if (turn.front().second == 'D') turnRight();
			turn.pop();
		}
	}

	cout << seconds << '\n';
	return 0;
}

