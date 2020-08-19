#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool isCrashed(queue<pair<int, int>> S, int row, int col) {  //queue 순회하는 방법
	bool ret = false;
	int rep = S.size();
	for (int i = 0; i < rep; i++) {
		if (S.front().first == row && S.front().second == col) {
			ret = true;
			break;
		}
		S.pop();
	}
	return ret;
}
bool eat_apple(vector<pair<int, int>> loc, vector<int> &exist, int row, int col) {  //수정되어야하는 것은 참조자로 넣어줘야함
	bool ret = false;
	for (int i = 0; i < loc.size(); i++) {
		if (row == loc[i].first && col == loc[i].second) {
			if (exist[i] == 1) {
				ret = true;
				exist[i] = 0;
			}
			break;
		}
	}
	return ret;
}
int main() {
	vector<pair<int, int>> apples_loc;
	vector<int> apples_exist;
	queue<pair<int, int>> snake;
	queue<pair<int, char>> changes;
	int N = 0; int K = 0; int L = 0;
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int input_r = 0;
		int input_c = 0;
		cin >> input_r;
		cin >> input_c;
		apples_loc.push_back(make_pair(input_r, input_c));
		apples_exist.push_back(1);
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int time = 0;
		char dir = 0;
		cin >> time;
		cin >> dir;
		changes.push(make_pair(time, dir));
	}
	snake.push(make_pair(1, 1));
	unsigned int dir = 1;
	int time = 0;
	while(1){
		int head_r = -1;
		int head_c = -1;
		time++;
		if (dir == 0) {
			head_r = snake.back().first - 1;
			head_c = snake.back().second;
			if (isCrashed(snake, head_r, head_c)) {
				break;
			}
			if (head_r < 1) {
				break;
			}

			snake.push(make_pair(head_r, head_c));
			if (!eat_apple(apples_loc, apples_exist, head_r, head_c)) {
				snake.pop();
			}

		}
		else if (dir == 2) {
			head_r = snake.back().first + 1;
			head_c = snake.back().second;
			if (isCrashed(snake, head_r, head_c)) {
				break;
			}
			if (head_r > N) {
				break;
			}
			snake.push(make_pair(head_r, head_c));
			if (!eat_apple(apples_loc, apples_exist, head_r, head_c)) {
				snake.pop();
			}
		}
		else if (dir == 3) {
			head_r = snake.back().first;
			head_c = snake.back().second - 1;
			if (isCrashed(snake, head_r, head_c)) {
				break;
			}
			if (head_c < 1) {
				break;
			}

			snake.push(make_pair(head_r, head_c));
			if (!eat_apple(apples_loc, apples_exist, head_r, head_c)) {
				snake.pop();
			}

			
		}
		else if (dir == 1) {
			head_r = snake.back().first;
			head_c = snake.back().second + 1;

			if (isCrashed(snake, head_r, head_c)) {
				break;
			}
			if (head_c > N) {
				break;
			}
			snake.push(make_pair(head_r, head_c));
			if (!eat_apple(apples_loc, apples_exist, head_r, head_c)) {
				snake.pop();
			}
		}
		

		if(changes.size() > 0){
			if (changes.front().first == time) {
				char change = changes.front().second;
				if (change == 'L') {
					dir = (dir - 1) % 4;
				}
				else if (change == 'D') {
					dir = (dir + 1) % 4;
				}
				changes.pop();
			}
		}
	}
	cout << time << endl;
	return 0;
}