#include<iostream>
using namespace std;

int E = 0;
int S = 0;
int M = 0;
bool check(int e, int s, int m) {
	return e == E && s == S && m == M;
}

int main() {
	cin >> E >> S >> M;

	int year = 0;
	int e = 0;
	int s = 0;
	int m = 0;
	while (1) {
		year++;
		e = (e + 1) % 16 ;
		if (e == 0) e = 1;
		s = (s + 1) % 29;
		if (s == 0) s = 1;
		m = (m + 1) % 20;
		if (m == 0) m = 1;

		if (check(e, s, m)) break;
	}

	cout << year << endl;
	return 0;
}
