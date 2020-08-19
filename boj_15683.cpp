#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>

using namespace std;
vector<vector<char>> MAP;
queue<char> CAMS_NO;
queue<pair<int, int>> CAMS_IDX;
int N = 0; int M = 0;
int ans = 0;
int total = 0;
int sec = 0;
int sec_areas(vector<vector<char>> map) {
	int ret = 0;
	//cout << ++sec << endl;
	//cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//cout << map[i][j] << " ";
			if (map[i][j] == '#') {
				ret++;
			}
		}
		//cout << endl;
	}
	return ret;
}

void dfs(queue<char> cams_no, queue<pair<int, int>> cams_idx, vector<vector<char>> map) {
	if (cams_no.size() == 0) {
		ans = max(ans, sec_areas(map));
		return;
	}

	char no = cams_no.front(); cams_no.pop();
	int r = cams_idx.front().first; int c = cams_idx.front().second; cams_idx.pop();

	if (no == '1') {
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				vector<vector<char>> new_map = map;
				int r_sec = r - 1;
				while (r_sec >= 0 && new_map[r_sec][c] != '6') {
					if (new_map[r_sec][c] != '0') {
						r_sec--;
						continue;
					}
					new_map[r_sec][c] = '#';
					r_sec--;
				}
				dfs(cams_no, cams_idx, new_map);
			}
			else if (i == 1) {
				vector<vector<char>> new_map = map;
				int c_sec = c + 1;
				while (c_sec < M && new_map[r][c_sec] != '6') {
					if (new_map[r][c_sec] != '0') {
						c_sec++;
						continue;
					}
					new_map[r][c_sec] = '#';
					c_sec++;
				}
				dfs(cams_no, cams_idx, new_map);
			}
			else if (i == 2) {
				vector<vector<char>> new_map = map;
				int r_sec = r + 1;
				while (r_sec < N && new_map[r_sec][c] != '6') {
					if (new_map[r_sec][c] != '0') {
						r_sec++;
						continue;
					}
					new_map[r_sec][c] = '#';
					r_sec++;
				}
				dfs(cams_no, cams_idx, new_map);
			}
			else if (i == 3) {
				vector<vector<char>> new_map = map;
				int c_sec = c - 1;
				while (c_sec >= 0 && new_map[r][c_sec] != '6') {
					if (new_map[r][c_sec] != '0') {
						c_sec--;
						continue;
					}
					new_map[r][c_sec] = '#';
					c_sec--;
				}
				dfs(cams_no, cams_idx, new_map);
			}
		}
	}
	else if (no == '2') {
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				vector<vector<char>> new_map = map;
				int r_sec_down = r + 1;
				while (r_sec_down < N && new_map[r_sec_down][c] != '6') {
					if (new_map[r_sec_down][c] != '0') {
						r_sec_down++; 
						continue;
					}
					new_map[r_sec_down][c] = '#';
					r_sec_down++;
				}

				int r_sec_up = r - 1;
				while (r_sec_up >= 0 && new_map[r_sec_up][c] != '6') {
					if (new_map[r_sec_up][c] != '0') {
						r_sec_up--; 
						continue;
					}
					new_map[r_sec_up][c] = '#';
					r_sec_up--;
				}
				dfs(cams_no, cams_idx, new_map);
			}
			if (i == 1) {
				vector<vector<char>> new_map = map;
				int c_sec_up = c - 1;
				while (c_sec_up >= 0 && new_map[r][c_sec_up] != '6') {
					if (new_map[r][c_sec_up] != '0') {
						c_sec_up--;
						continue;
					}
					new_map[r][c_sec_up] = '#';
					c_sec_up--;
				}

				int c_sec_down = c + 1;
				while (c_sec_down < M && new_map[r][c_sec_down] != '6') {
					if (new_map[r][c_sec_down] != '0') {
						c_sec_down++;
						continue;
					}
					new_map[r][c_sec_down] = '#';
					c_sec_down++;
				}

				dfs(cams_no, cams_idx, new_map);
			}
		}
	}
	else if (no == '3') {
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				vector<vector<char>> new_map = map;
				int r_sec_up = r - 1;
				while (r_sec_up >= 0 && new_map[r_sec_up][c] != '6') {
					if (new_map[r_sec_up][c] != '0') {
						r_sec_up--;
						continue;
					}
					new_map[r_sec_up][c] = '#';
					r_sec_up--;
				}
				int c_sec_down = c + 1;
				while (c_sec_down < M && new_map[r][c_sec_down] != '6') {
					if (new_map[r][c_sec_down] != '0') {
						c_sec_down++;
						continue;
					}
					new_map[r][c_sec_down] = '#';
					c_sec_down++;
				}

				dfs(cams_no, cams_idx, new_map);

			}
			else if (i == 1) {
				vector<vector<char>> new_map = map;
				int c_sec_down = c + 1;
				while (c_sec_down < M && new_map[r][c_sec_down] != '6') {
					if (new_map[r][c_sec_down] != '0') {
						c_sec_down++;
						continue;
					}
					new_map[r][c_sec_down] = '#';
					c_sec_down++;
				}
				int r_sec_down = r + 1;
				while (r_sec_down < N && new_map[r_sec_down][c] != '6') {
					if (new_map[r_sec_down][c] != '0') {
						r_sec_down++;
						continue;
					}
					new_map[r_sec_down][c] = '#';
					r_sec_down++;
				}
				dfs(cams_no, cams_idx, new_map);
			}
			else if (i == 2) {
				vector<vector<char>> new_map = map;
				int r_sec_down = r + 1;
				while (r_sec_down < N && new_map[r_sec_down][c] != '6') {
					if (new_map[r_sec_down][c] != '0') {
						r_sec_down++;
						continue;
					}
					new_map[r_sec_down][c] = '#';
					r_sec_down++;
				}
				int c_sec_up = c - 1;
				while (c_sec_up >= 0 && new_map[r][c_sec_up] != '6') {
					if (new_map[r][c_sec_up] != '0') {
						c_sec_up--;
						continue;
					}
					new_map[r][c_sec_up] = '#';
					c_sec_up--;
				}
				dfs(cams_no, cams_idx, new_map);
			}
			else if (i == 3) {
				vector<vector<char>> new_map = map;
				int c_sec_up = c - 1;
				while (c_sec_up >= 0 && new_map[r][c_sec_up] != '6') {
					if (new_map[r][c_sec_up] != '0') {
						c_sec_up--;
						continue;
					}
					new_map[r][c_sec_up] = '#';
					c_sec_up--;
				}
				int r_sec_up = r - 1;
				while (r_sec_up >= 0 && new_map[r_sec_up][c] != '6') {
					if (new_map[r_sec_up][c] != '0') {
						r_sec_up--;
						continue;
					}
					new_map[r_sec_up][c] = '#';
					r_sec_up--;
				}
				dfs(cams_no, cams_idx, new_map);
			}
		}
	}
	else if (no == '4') {
	for (int i = 0; i < 4; i++) {
		if (i == 0) {
			vector<vector<char>> new_map = map;
			int r_sec_up = r - 1;
			while (r_sec_up >= 0 && new_map[r_sec_up][c] != '6') {
				if (new_map[r_sec_up][c] != '0') {
					r_sec_up--;
					continue;
				}
				new_map[r_sec_up][c] = '#';
				r_sec_up--;
			}
			int c_sec_down = c + 1;
			while (c_sec_down < M && new_map[r][c_sec_down] != '6') {
				if (new_map[r][c_sec_down] != '0') {
					c_sec_down++;
					continue;
				}
				new_map[r][c_sec_down] = '#';
				c_sec_down++;
			}
			int c_sec_up = c - 1;
			while (c_sec_up >= 0 && new_map[r][c_sec_up] != '6') {
				if (new_map[r][c_sec_up] != '0') {
					c_sec_up--;
					continue;
				}
				new_map[r][c_sec_up] = '#';
				c_sec_up--;
			}
			dfs(cams_no, cams_idx, new_map);

		}
		else if (i == 1) {
			vector<vector<char>> new_map = map;
			int c_sec_down = c + 1;
			while (c_sec_down < M && new_map[r][c_sec_down] != '6') {
				if (new_map[r][c_sec_down] != '0') {
					c_sec_down++;
					continue;
				}
				new_map[r][c_sec_down] = '#';
				c_sec_down++;
			}
			int r_sec_down = r + 1;
			while (r_sec_down < N && new_map[r_sec_down][c] != '6') {
				if (new_map[r_sec_down][c] != '0') {
					r_sec_down++;
					continue;
				}
				new_map[r_sec_down][c] = '#';
				r_sec_down++;
			}
			int r_sec_up = r - 1;
			while (r_sec_up >= 0 && new_map[r_sec_up][c] != '6') {
				if (new_map[r_sec_up][c] != '0') {
					r_sec_up--;
					continue;
				}
				new_map[r_sec_up][c] = '#';
				r_sec_up--;
			}

			dfs(cams_no, cams_idx, new_map);
		}
		else if (i == 2) {
			vector<vector<char>> new_map = map;
			int r_sec_down = r + 1;
			while (r_sec_down < N && new_map[r_sec_down][c] != '6') {
				if (new_map[r_sec_down][c] != '0') {
					r_sec_down++;
					continue;
				}
				new_map[r_sec_down][c] = '#';
				r_sec_down++;
			}
			int c_sec_up = c - 1;
			while (c_sec_up >= 0 && new_map[r][c_sec_up] != '6') {
				if (new_map[r][c_sec_up] != '0') {
					c_sec_up--;
					continue;
				}
				new_map[r][c_sec_up] = '#';
				c_sec_up--;
			}
			int c_sec_down = c + 1;
			while (c_sec_down < M && new_map[r][c_sec_down] != '6') {
				if (new_map[r][c_sec_down] != '0') {
					c_sec_down++;
					continue;
				}
				new_map[r][c_sec_down] = '#';
				c_sec_down++;
			}
			dfs(cams_no, cams_idx, new_map);
		}
		else if (i == 3) {
			vector<vector<char>> new_map = map;
			int c_sec_up = c - 1;
			while (c_sec_up >= 0 && new_map[r][c_sec_up] != '6') {
				if (new_map[r][c_sec_up] != '0') {
					c_sec_up--;
					continue;
				}
				new_map[r][c_sec_up] = '#';
				c_sec_up--;
			}
			int r_sec_up = r - 1;
			while (r_sec_up >= 0 && new_map[r_sec_up][c] != '6') {
				if (new_map[r_sec_up][c] != '0') {
					r_sec_up--;
					continue;
				}
				new_map[r_sec_up][c] = '#';
				r_sec_up--;
			}
			int r_sec_down = r + 1;
			while (r_sec_down < N && new_map[r_sec_down][c] != '6') {
				if (new_map[r_sec_down][c] != '0') {
					r_sec_down++;
					continue;
				}
				new_map[r_sec_down][c] = '#';
				r_sec_down++;
			}
			dfs(cams_no, cams_idx, new_map);
		}
	}
	}
	else if (no == '5') {
		vector<vector<char>> new_map = map;
		int r_sec_down = r + 1;
		while (r_sec_down < N && new_map[r_sec_down][c] != '6') {
			if (new_map[r_sec_down][c] != '0') {
				r_sec_down++;
				continue;
			}
			new_map[r_sec_down][c] = '#';
			r_sec_down++;
		}

		int r_sec_up = r - 1;
		while (r_sec_up >= 0 && new_map[r_sec_up][c] != '6') {
			if (new_map[r_sec_up][c] != '0') {
				r_sec_up--;
				continue;
			}
			new_map[r_sec_up][c] = '#';
			r_sec_up--;
		}

		int c_sec_up = c - 1;
		while (c_sec_up >= 0 && new_map[r][c_sec_up] != '6') {
			if (new_map[r][c_sec_up] != '0') {
				c_sec_up--;
				continue;
			}
			new_map[r][c_sec_up] = '#';
			c_sec_up--;
		}

		int c_sec_down = c + 1;
		while (c_sec_down < M && new_map[r][c_sec_down] != '6') {
			if (new_map[r][c_sec_down] != '0') {
				c_sec_down++;
				continue;
			}
			new_map[r][c_sec_down] = '#';
			c_sec_down++;
		}

		dfs(cams_no, cams_idx, new_map);
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<char> row;
		for (int j = 0; j < M; j++) {
			char in = 0; cin >> in;
			row.push_back(in);
			if (in != '0' && in != '6') {
				CAMS_IDX.push(make_pair(i, j));
				CAMS_NO.push(in);
			}
			if (in == '0') {
				total++;
			}
		}
		MAP.push_back(row);
	}
	
	dfs(CAMS_NO, CAMS_IDX, MAP);

	cout << total - ans << endl;
	return 0;
}