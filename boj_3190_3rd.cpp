#include<bits/stdc++.h>
using namespace std;

enum _DIR {
	UP,
	RT, 
	DN,
	LT
};

int L = 0;
int N = 0;
int pan[100][100] = { 0, };
int K = 0;
int rdir[4] = { -1, 0, 1, 0 };
int cdir[4] = { 0, 1, 0, -1 };
int dir = RT;
map<int ,char> twist;

vector<pair<int, int>> snake;

void Twist(char t) {
	if (t == 'L') dir = (dir - 1 + 4) % 4;
	else if (t == 'D') dir = (dir + 1) % 4;
}
bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}
int main(){
	cin >> N >> K;
	pan[0][0] = 1;
	snake.push_back(make_pair(0, 0));

	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		pan[r - 1][c - 1] = 2;
	}

	cin >> L;
	for (int i = 0; i < L; i++) {
		int step; char d;
		cin >> step >> d;
		twist[step] = d;
	}

	int cnt = 0;

	while (1) {
		cnt++;
		int Size = snake.size();
		int head_r = snake[Size - 1].first + rdir[dir]; //格 疵府扁
		int head_c = snake[Size - 1].second + cdir[dir];

		if (!isValid(head_r, head_c) || pan[head_r][head_c] == 1) {
			break;
		}
		else {
			if (pan[head_r][head_c] == 2) {
				pan[head_r][head_c] = 1;
				snake.push_back(make_pair(head_r, head_c));
			}
			else if(pan[head_r][head_c] == 0){
				pan[head_r][head_c] = 1;
				snake.push_back(make_pair(head_r, head_c));

				pan[snake[0].first][snake[0].second] = 0;
				snake.erase(snake.begin(), snake.begin() + 1); //部府 昏力
			}
		}


		if (twist.find(cnt) != twist.end()) {
			char t = twist[cnt];
			Twist(t);
		}
	}

	cout << cnt << '\n';
	return 0;
}
