#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N = 0;
vector<vector<int>> S;
vector<vector<int>> visit;
int ans = 100;
int total_sum = 0;
bool isMember(vector<int> team, int number) {
	int count = team.size();
	for (int i = 0; i < count; i++) {
		if (number == team[i]) {
			return true;
		}
	}
	return false;
}

bool isVisited(vector<int> team, int number) {
	int count = team.size();
	for (int i = 0; i < count; i++) {
		if (visit[number][team[i]] == 1) {
			return true;
		}
	}
	return false;
}

int calcDif(vector<int> team) {
	int sum = 0;
	int op_sum = 0;
	int count = team.size();
	vector<int> op_team;
	for (int k = 0; k < N; k++) {
		if (!isMember(team, k)) {
			op_team.push_back(k);
		}
	}

	for (int i = 0; i < count; i++) {
		int r = team[i]; 
		for (int j = 0; j < count; j++) {
			int c = team[j];
			sum += S[r][c];
		}
	}

	for (int i = 0; i < count; i++) {
		int r = op_team[i];
		for (int j = 0; j < count; j++) {
			int c = op_team[j];
			op_sum += S[r][c];
		}
	}

	return abs(sum - op_sum);
}
int dfs(int depth, vector<int> team) {
	if ((N / 2) == depth) {
		ans = min(ans, calcDif(team));
		return -1;
	}
	else {
		int count = team.size();
		int start_point = 0;
		if (count == 0) {
			start_point = 0;
		}
		else {
			start_point = team[count - 1] + 1;
		}
		for (int i = start_point; i < N; i++) {
			if (isMember(team, i)) {
				continue;
			}
			else {
				team.push_back(i);
				dfs(depth + 1, team);
				team.pop_back();
			}
		}
	}
	return 0;
}
int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		vector<int> row;
		vector<int> row_v;
		for (int j = 0; j < N; j++) {
			int in = 0; cin >> in;
			total_sum += in;
			row.push_back(in);
			row_v.push_back(0);
		}
		S.push_back(row);
		visit.push_back(row_v);
	}


	vector<int> T;
	dfs(0, T);
	cout << ans << endl;
	return 0;
}