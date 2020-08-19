#include<iostream>
using namespace std;
int B[4][6] = { 0, };
int G[6][4] = { 0, };
int N = 0;
int type[10000] = { 0, };
#define FOR(i, a, b) for(int i = a; i < b; i++)


void check() {
	cout << "Blue" << endl;
	FOR(i, 0, 4) {
		FOR(j, 0, 6) {
			cout << B[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << "Green" << endl;
	FOR(i, 0, 6) {
		FOR(j, 0, 4) {
			cout << G[i][j] << " ";
		}
		cout << endl;
	}

}


void move(int t, int r, int c, int no) {
	int rb = r; int cb = 1; int rg = 1; int cg = c;
	switch (t) {

		case 1:
		{
			while (cb < 6 && B[rb][cb] == 0) { cb++; }
			while (rg < 6 && G[rg][cg] == 0) { rg++; }
			B[rb][cb - 1] = no; G[rg - 1][cg] = no;
			break;
		}
		case 2:
		{
			while (cb + 1 < 6 && B[rb][cb + 1] == 0) { cb++; }
			while (rg < 6 && G[rg][cg] == 0 && G[rg][cg + 1] == 0) { rg++; }
			B[rb][cb - 1] = no; B[rb][cb] = no; 
			G[rg - 1][cg] = no; G[rg - 1][cg + 1] = no;
			break; 
		}
		case 3:
		{
			while (cb < 6 && B[rb][cb] == 0 && B[rb + 1][cb] == 0 ) { cb++; }
			while (rg + 1 < 6 && G[rg + 1][cg] == 0) { rg++; }
			B[rb][cb - 1] = no; B[rb + 1][cb - 1] = no;
			G[rg - 1][cg] = no; G[rg][cg] = no;
			break;
		}
	}		
}

void slide_b(int d) {
	for (int i = 5; i >= 0 + d; i--) {
		FOR(j, 0, 4) {
			B[j][i] = B[j][i - d];
		}
	}
	
	for(int i = 1; i >= 2 - d; i--) {
		FOR(j, 0, 4) B[j][i] = 0;
	}
	
}

void slide_g(int d) {
	for (int i = 5; i >= 0 + d; i--) {
		FOR(j, 0, 4) {
			G[i][j] = G[i - d][j];
		}
	}
	
	for (int i = 1; i >= 2 - d; i--) {
		FOR(j, 0, 4) G[i][j] = 0;
	}
	
}

void fitin_b() {
	for (int j = 4; j >= 0; j--) {
		FOR(i, 0, 4) {
			if (B[i][j] != 0) {
				if (type[B[i][j] - 1] == 3) {
					if (i + 1 < 4 && B[i + 1][j] == B[i][j]) {
						for (int k = j + 1; k < 6; k++) {
							if (B[i][k] == 0 && B[i + 1][k] == 0) {
								B[i][k] = B[i][k - 1]; B[i + 1][k] = B[i + 1][k - 1];
								B[i][k - 1] = 0; B[i + 1][k - 1] = 0;
							}
							else break;
						}
					}
				}
				else {
					for (int k = j + 1; k < 6; k++) {
						if (B[i][k] == 0) {
							B[i][k] = B[i][k - 1]; B[i][k - 1] = 0;
						}
						else break;
					}
				}
			}
		}
	}
}

void fitin_g() {
	for (int j = 4; j >= 0; j--) {
		FOR(i, 0, 4) {
			if (G[j][i] != 0) {
				if(type[G[j][i] - 1] == 2){
					if (i + 1 < 4 && G[j][i + 1] == G[j][i]) {// pairÀÌ¸é
						for (int k = j + 1; k < 6; k++) {
							if (G[k][i] == 0 && G[k][i + 1] == 0) {
								G[k][i] = G[k - 1][i]; G[k][i + 1] = G[k - 1][i + 1];
								G[k - 1][i] = 0; G[k - 1][i + 1] = 0;
							}
							else break;
						}
					}
				}
				else {
					for (int k = j + 1; k < 6; k++) {
						if (G[k][i] == 0) {
							G[k][i] = G[k - 1][i]; G[k - 1][i] = 0;
						}
						else break;
					}
				}
			}
		}
	}
}


int point_b() {
	int ret = 0;
	FOR(j, 2, 6) {
		int mul = 1;
		FOR(i, 0, 4) {
			mul = mul * B[i][j];
		}
		
		if (mul) {
			FOR(i, 0, 4){B[i][j] = 0;}
			ret = j; break;
		}
		
	}
	
	return ret;
}

int point_g() {
	int ret = 0;
	FOR(j, 2, 6) {
		int mul = 1;
		FOR(i, 0, 4) {
			mul *= G[j][i];
		}
		if (mul) {
			FOR(i, 0, 4) { G[j][i] = 0; }
			ret = j; break;
		}
	}
	
	return ret;
}

int checkOfB() {
	int d = 0;
	FOR(i, 0, 2) {
		FOR(j, 0, 4) {
			if (B[j][i]) {
				d++; break;
			}
		}
	}

	FOR(i, 6 - d, 6) {
		FOR(j, 0, 4) B[j][i] = 0;
	}
	return d;
}

int checkOfG() {
	int d = 0;
	FOR(i, 0, 2) {
		FOR(j, 0, 4) {
			if (G[i][j]) {
				d++; break;
			}
		}
	}

	FOR(i, 6 - d, 6) {
		FOR(j, 0, 4) G[i][j] = 0;
	}
	return d;
}

int count_b() {
	int ret = 0;
	FOR(i, 0, 4) {
		FOR(j, 0, 6) {
			if (B[i][j]) ret++;
		}
	}
	return ret;
}

int count_g() {
	int ret = 0;
	FOR(i, 0, 6) {
		FOR(j, 0, 4) {
			if(G[i][j]) ret++;
		}
	}
	return ret;
}

int main() {
	cin >> N;
	int point = 0;
	int cnt = 0;

	for(int i =0; i < N; i++) {
		int t; int r; int c;
		cin >> t >> r >> c;
		move(t, r, c, i + 1);
		type[i] = t;
		int rt = 0; int ct = 0;
		//if (i == N - 1) check();
		while (1) {
			ct = point_b();
			if (!ct) break;
			point++;

			
			fitin_b();
		}
		while (1) {
			rt = point_g();
			if (!rt) break;
			point++;
			fitin_g();
		}
		int d = checkOfB();
		if (d) {
			//slide_b(d
			//if (i == N - 1) check();
			fitin_b();
		}
		d = checkOfG();
		if (d) {
			//slide_g(d);
			fitin_g();
		}

	}

	//check();

	cout << point << endl;
	cnt = count_b() + count_g();
	cout << cnt;
	return 0;
}

