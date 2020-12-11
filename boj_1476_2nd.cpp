#include<iostream>
using namespace std;

int main() {
	int e;
	int s;
	int m;
	cin >> e >> s >> m;
	int year = 1;
	while (1) {
		if ((year - 1) % 15 + 1 == e && (year - 1) % 28 + 1 == s && (year - 1) % 19 + 1 == m) {
			break;
		}
		else year++;
	}
	cout << year << endl;
	return 0;

}
