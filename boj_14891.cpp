#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> saws;
int K = 0;
vector<pair<int, int>> rot;
bool isSame(int number_left, int number_right) {
	if (number_left - 1 < 0) return true;
	if (number_right - 1 >= 4) return true;

	vector<int> left = saws[number_left - 1];
	vector<int> right = saws[number_right - 1];

	return left[2] == right[6];
}
void rotation(int number, int dir) {
	if (dir == 1) {
		vector<int>& saw = saws[number - 1];
		int temp = saw[7];
		for (int i = 7; i >= 0; i--) {
			unsigned int idx = i;
			saw[idx] = saw[(idx - 1) % 8];
		}
		saw[0] = temp;
	}

	else if (dir == -1) {
		vector<int>& saw = saws[number - 1];
		int temp = saw[0];
		for (unsigned int i = 0; i < 8; i++) {
			saw[i] = saw[(i + 1) % 8];
		}
		saw[7] = temp;
	}
}

int main() {

	for (int i = 0; i < 4; i++) {
		vector<int> row;
		for (int j = 0; j < 8; j++) {
			int in = 0;
			scanf_s("%1d", &in);
			row.push_back(in);
		}
		saws.push_back(row);
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		int saw = 0; int dir = 0;
		cin >> saw >> dir;
		rot.push_back(make_pair(saw, dir));
	}


	for (int i = 0; i < K; i++) {
		vector<int> visit = { 0, 0, 0, 0 };
		int saw_no = rot[i].first;
		int direction = rot[i].second;
		queue<int> target; 
		queue<int> dirQ;
		target.push(saw_no);
		dirQ.push(direction);
		visit[saw_no - 1] = 1;

		while (target.size() != 0) {
			int no = target.front(); target.pop();
			int d = dirQ.front(); dirQ.pop();

			if (!isSame(no - 1, no)) {
				if (visit[no - 1 - 1] == 0) {
					visit[no - 1 - 1] = 1;
					target.push(no - 1);
					dirQ.push(d * (-1));
				}
			}

			if (!isSame(no, no + 1)) {
				if (visit[no + 1 - 1] == 0) {
					visit[no + 1 - 1] = 1;
					target.push(no + 1);
					dirQ.push(d * (-1));
				}
			}

			rotation(no, d);
		}

	}
	int ans = 0;
	cout << endl;
	/*for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cout << saws[i][j] << " ";
		}
		cout << endl;
	}*/
	for (int i = 0; i < 4; i++) {
		int twelve = saws[i][0];
		if (twelve == 0) ans += 0;
		else if (twelve == 1) ans += pow(2, i);
	}
	cout << ans << endl;
	return 0;
}