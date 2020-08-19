#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M, H;
queue<pair<short, short>> Q;
queue<short> depths;
void printState(vector<vector<int>> ladders){
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N - 1; j++) {
			cout << ladders[i][j] << " ";
		}
		cout << endl;
	}
}

bool checkComplete(vector<vector<int>> const & ladders) {
	for (int i = 0; i < N; i++) {
		int position = i;
		for (int j = 0; j < H; j++) {
			if (position - 1 >= 0) {
				if (ladders[j][position - 1] == 1) {
					position = position - 1; continue;
				}
			}

			if (position < N - 1) {
				if (ladders[j][position] == 1) {
					position = position + 1; continue;
				}
			}
		}
		if (position != i) return false;
	}
	return true;
}

int bfs(short depth, vector<vector<int>> & ladders) {
	if (depth > 3) return -1;

	vector<pair<short, short>> trace;
	int r = 0; int c = 0;
	for (short i = 0; i < depth; i++) {
		pair<short, short> point = Q.front(); Q.pop();
		r = point.first; c = point.second;
		trace.push_back(make_pair(r, c));
		ladders[r][c] = 1;
	}

	if (checkComplete(ladders)) return 1;


	for (short k = 0; k < depth; k++) {
		ladders[trace[k].first][trace[k].second] = 0;
	}

	if( depth < 3){
		for (int i = r; i < H; i++) {
			int j = 0;
			if (i == r) j = c; 
			else j = 0; 
			for (; j < N - 1; j++) {
				int ladder = ladders[i][j];
			
				if (ladder == 0) {
					if (j - 1 >= 0) {
						if(ladders[i][j - 1] == 1) continue;
					}
					if (j + 1 < N - 1) {
						if (ladders[i][j + 1] == 1) continue;
					}

				
					for (short k = 0; k < depth; k++) {
						Q.push(make_pair(trace[k].first, trace[k].second));
						ladders[trace[k].first][trace[k].second] = 0;
					}
					Q.push(make_pair((short) i, (short) j)); depths.push(depth + 1);
				}
			}
		}
	}
	return 0;
}

int main() {
	cin >> N >> M >> H;
	vector<vector<int>> L(H, vector<int>(N - 1, 0));

	for (int i = 0; i < M; i++) {
		int r, c;
		cin >> r >> c;
		L[r - 1][c - 1] = 1;
	}

	int ans = -1;
	depths.push(0);
	short depth = depths.front(); depths.pop();
	
	int ret = bfs(depth, L);
	if (ret == 1) ans = depth;


	while (!depths.empty()) {
		depth = depths.front(); depths.pop();
		ret = bfs(depth, L);
		if (ret == 1) {
			ans = depth;
			break;
		}
		else if (-1 == ret) {
			ans = -1;
			break;
		}

	}

	cout << ans << endl;
	return 0;
}