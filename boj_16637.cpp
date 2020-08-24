#include<bits/stdc++.h>
#include<climits>
using namespace std;
int N = 0;
vector<char> s;
int ans = INT_MIN;
bool isNumber(char t) {
	return '0' <= t && t <= '9';
}
void check() {
	for (vector<char> ::iterator it = s.begin(); it != s.end(); it++) cout << *it;
	cout << '\n';
}

int calc() {
	int result = 0;
	vector<int> poly;
	for (auto const x : s) {
		if (x == ')') {
			int acc = 0;
			while (*(poly.end() - 1) != '(') {
				int num1 = *(poly.end() - 1);  poly.pop_back();
				char sign = *(poly.end() - 1); poly.pop_back();
				int num2 = *(poly.end() - 1);  poly.pop_back();

				switch (sign) {
				case ('+'):
					acc = num2 + num1;
					break;
				case ('-'):
					acc = num2 - num1;
					break;
				case ('*'):
					acc = num2 * num1;
					break;
				}
			}
			poly.pop_back();
			poly.push_back(acc);
		}
		else {
			if (isNumber(x)) poly.push_back(x - '0');
			else poly.push_back(x);
		}
	}

	result += poly[0];
	for (int i = 1; i < poly.size(); i = i+ 2) {
		char sign = poly[i];
		int num = poly[i + 1];

		switch (sign) {
		case ('+'):
			result += num;
			break;
		case ('-'):
			result -= num;
			break;
		case ('*'):
			result *= num;
			break;
		}
	}
	return result;
}
void dfs(int pos) {
	int l = s.size();
	if (pos >= l - 2) {
		ans = max(ans, calc());
		//check();
		return;
	}
	else {
		s.insert(s.begin() + pos, '(');
		s.insert(s.begin() + pos + 4, ')');
		dfs(pos + 6);
		s.erase(s.begin() + pos + 4);
		s.erase(s.begin() + pos);
		dfs(pos + 2);
	}
}

int main() {
	cin >> N;
	s.assign(N, 0);
	for(int i = 0; i < N; i++) cin >> s[i];

	int pos = 0;
	dfs(pos);
	cout << ans << endl;
	return 0;
}
