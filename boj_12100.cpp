#include <iostream>
#include<vector>
#include<algorithm>


using namespace std;

int ans = 0;
int N = 0;

int getLargest(vector<vector<int>> table) {
	int largest = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			largest = max(largest, table[i][j]);
		}
	}
	return largest;
}


void print(vector<vector<int>> table) {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

void up(vector<vector<int>> &table) {
	int changed[20][20] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (table[i][j] != 0) {
				int new_row = i;
				while (1) {
					new_row += -1;
					if (new_row >= 0) {
						if (table[new_row][j] == 0)	continue;
						else {
							if (table[new_row][j] == table[i][j] && changed[new_row][j] == 0) {
								table[i][j] = 0;
								table[new_row][j] = table[new_row][j] * 2;
								changed[new_row][j] = 1;
								break;
							}
							else {
								int temp = table[i][j];
								table[i][j] = 0;
								table[new_row + 1][j] = temp;
								break;
							}
						}
					}
					else {
						int temp = table[i][j];
						table[i][j] = 0;
						table[new_row + 1][j] = temp;
						break;
					}
				}
			}
		}
	}
}
void down(vector<vector<int>> &table) {
	int changed[20][20] = { 0, };
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (table[i][j] != 0) {
				int new_row = i;
				while (1) {
					new_row += 1;
					if (new_row < N) {
						if (table[new_row][j] == 0)	continue;
						else {
							if (table[new_row][j] == table[i][j] && changed[new_row][j] == 0) {
								table[i][j] = 0;
								table[new_row][j] = table[new_row][j] * 2;
								changed[new_row][j] = 1;
								break;
							}
							else {
								int temp = table[i][j];
								table[i][j] = 0;
								table[new_row - 1][j] = temp;
								break;
							}
						}
					}
					else {
						int temp = table[i][j];
						table[i][j] = 0;
						table[new_row - 1][j] = temp;
						break;
					}
				}
			}
		}
	}
}
void left(vector<vector<int>> &table) {
	int changed[20][20] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (table[i][j] != 0) {
				int new_col = j;
				while (1) {
					new_col += -1;
					if (new_col >= 0) {
						if (table[i][new_col] == 0)	continue;
						else {
							if (table[i][new_col] == table[i][j] && changed[i][new_col] == 0) {
								table[i][j] = 0;
								table[i][new_col] = table[i][new_col] * 2;
								changed[i][new_col] = 1;
								break;
							}
							else {
								int temp = table[i][j];
								table[i][j] = 0;
								table[i][new_col + 1] = temp;
								break;
							}
						}
					}
					else {
						int temp = table[i][j];
						table[i][j] = 0;
						table[i][new_col + 1] = temp;
						break;
					}
				}
			}
		}
	}
}
void right(vector<vector<int>> &table) {
	int changed[20][20] = { 0, };
	for (int i = 0; i < N; i++) {
		for (int j = N - 1; j >= 0; j--) {
			if (table[i][j] != 0) {
				int new_col = j;
				while (1) {
					new_col += 1;
					if (new_col < N) {
						if (table[i][new_col] == 0)	continue;
						else {
							if (table[i][new_col] == table[i][j] && changed[i][new_col] == 0) {
								table[i][j] = 0;
								table[i][new_col] = table[i][new_col] * 2;
								changed[i][new_col] = 1;
								break;
							}
							else {
								int temp = table[i][j];
								table[i][j] = 0;
								table[i][new_col - 1] = temp;
								break;
							}
						}
					}
					else {
						int temp = table[i][j];
						table[i][j] = 0;
						table[i][new_col - 1] = temp;
						break;
					}
				}
			}
		}
	}
}

int dfs(int count, int direction, vector<vector<int>> current_state) {

	
	if (count == 0) {
		dfs(1, 1, current_state);
		dfs(1, 2, current_state);
		dfs(1, 3, current_state);
		dfs(1, 4, current_state);
	}
	else if (count <= 5) {

		vector<vector<int>> table = current_state;
		if (direction == 1) {
			up(table);
		}
		else if (direction == 2) {
			down(table);
		}
		else if (direction == 3) {
			left(table);
		}
		else if (direction == 4) {
			right(table);
		}

		if (count < 5) {
			dfs(count + 1, 1, table);
			dfs(count + 1, 2, table);
			dfs(count + 1, 3, table);
			dfs(count + 1, 4, table);
		}
		else if (count == 5) {
			ans = max(ans, getLargest(table));
		}
	}
	return 0;
}
int main() {
	cin >> N;
	vector<int> block_row;
	vector<int> block_col;
	vector<int> block_value;

	vector<vector<int>> table;

	for (int i = 0; i < N; i++) {
		vector<int> row; 
		for (int j = 0; j < N; j++) {
			int input = 0;
			cin >> input;
			row.push_back(input);
		}
		table.push_back(row); 
	}

	dfs(0, -1, table);
	//down(table);
	//print(table);
	cout << ans << endl;

	return 0;
	
}