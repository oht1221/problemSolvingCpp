#include<bits/stdc++.h>
using namespace std;
int N = 0;
long long numbers[11];
char ops[4] = { '+', '-', '*', '/' };
int numOps[4];
long long ans1 = LLONG_MIN;
long long ans2 = LLONG_MAX;
vector<char> seq;
bool empty() {
	for (int i = 0; i < 4; i++) {
		if (numOps[i] != 0) return false;
	}
	return true;
}

long long operate(long long a, int b, char op) {
	switch (op) {
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (a < 0) return (-1) * (((-1) * a) / b);
			else return a / b;
	}
}

long long calc() {
	long long ret = 0;
	char op;
	for (int i = 0; i < N; i++){
		if (i != 0) op = seq[i - 1];
		else op = '+';
		ret = operate(ret, numbers[i], op);
	}
	return ret;
}
void dfs() {
	if (empty()) {
		long long result = calc();
		ans1 = max(ans1, result);
		ans2 = min(ans2, result);
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (numOps[i] != 0) {
				seq.push_back(ops[i]);
				numOps[i]--;
				dfs();
				numOps[i]++;
				seq.pop_back();
			}
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	for (int i = 0; i < 4; i++) {
		cin >> numOps[i];
	}

	dfs();

	cout << ans1 << '\n';
	cout << ans2 << '\n';
	return 0;
}
