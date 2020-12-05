#include<bits/stdc++.h>
#include<functional>

using namespace std;

int N = 0;
vector<int> A;
vector<int> op;
map<int, function<int(int, int)>> operation;
vector<int> selected;
int Max = INT_MIN;
int Min = INT_MAX;
int calc() {
	int ret = A[0];
	for (int i = 1; i < N; i++) {
		int opN = selected[i - 1];
		ret = operation[opN](ret, A[i]);
	}

	return ret;
}
void permu(int cnt) {
	if (cnt == N - 1) {
		int result = calc();
		Min = min(Min, result);
		Max = max(Max, result);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] == 0)continue;
		else {
			selected.push_back(i);
			op[i]--;
			permu(cnt + 1);
			op[i]++;
			selected.pop_back();
		}
	}
}

int main() {
	operation[0] = [](int x, int y) {return x + y; };
	operation[1] = [](int x, int y) {return x - y; };
	operation[2] = [](int x, int y) {return x * y; };
	operation[3] = [](int x, int y) {return x / y; };
	cin >> N;
	A.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	op.assign(4, 0);
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	permu(0);

	cout << Max << '\n' << Min << '\n';
	return 0;
}
