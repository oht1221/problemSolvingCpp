#include <bits/stdc++.h>
using namespace std;
enum SIDE {
	UP,
	DOWN,
	FRONT,
	BACK,
	LEFT,
	RIGHT
};

enum DIR {
	CCW,
	CW
};

void part1(char s, char d, char cube[][9]) {
	if (s == 'U') s = UP;
	if (s == 'D') s = DOWN;
	if (s == 'F') s = FRONT;
	if (s == 'B') s = BACK;
	if (s == 'L') s = LEFT;
	if (s == 'R') s = RIGHT;

	int temp = cube[s][0];
	int temp1 = cube[s][2];
	int temp3 = cube[s][1];
	cube[s][0] = cube[s][6];
	cube[s][1] = cube[s][3];
	cube[s][2] = temp;
	cube[s][3] = cube[s][7];
	cube[s][6] = cube[s][8];
	cube[s][7] = cube[s][5];
	cube[s][8] = temp1;
	cube[s][5] = temp3;
}
void rt(char s, char d, char cube[][9]) {

	if (d == CW) {
		part1(s, d, cube);
	}
	if (d == CCW) {
		for (int i = 0; i < 3; i++) {
			part1(s, d, cube);
		}
	}

	switch (s) {
		case 'U':
			if (d == CW) {
				char temp1 = cube[LEFT][0];
				char temp2 = cube[LEFT][1];
				char temp3 = cube[LEFT][2];
				cube[LEFT][0] = cube[FRONT][0];
				cube[LEFT][1] = cube[FRONT][1];
				cube[LEFT][2] = cube[FRONT][2];
				cube[FRONT][0] = cube[RIGHT][0];
				cube[FRONT][1] = cube[RIGHT][1];
				cube[FRONT][2] = cube[RIGHT][2];
				cube[RIGHT][0] = cube[BACK][0];
				cube[RIGHT][1] = cube[BACK][1];
				cube[RIGHT][2] = cube[BACK][2];
				cube[BACK][0] = temp1;
				cube[BACK][1] = temp2;
				cube[BACK][2] = temp3;
			}
			if (d == CCW) {
				for (int i = 0; i < 3; i++) {
					char temp1 = cube[LEFT][0];
					char temp2 = cube[LEFT][1];
					char temp3 = cube[LEFT][2];
					cube[LEFT][0] = cube[FRONT][0];
					cube[LEFT][1] = cube[FRONT][1];
					cube[LEFT][2] = cube[FRONT][2];
					cube[FRONT][0] = cube[RIGHT][0];
					cube[FRONT][1] = cube[RIGHT][1];
					cube[FRONT][2] = cube[RIGHT][2];
					cube[RIGHT][0] = cube[BACK][0];
					cube[RIGHT][1] = cube[BACK][1];
					cube[RIGHT][2] = cube[BACK][2];
					cube[BACK][0] = temp1;
					cube[BACK][1] = temp2;
					cube[BACK][2] = temp3;
				}
			}

			break;

		case 'D':

			if (d == CW) {
				char temp1 = cube[BACK][6];
				char temp2 = cube[BACK][7];
				char temp3 = cube[BACK][8];
				cube[BACK][6] = cube[RIGHT][6];
				cube[BACK][7] = cube[RIGHT][7];
				cube[BACK][8] = cube[RIGHT][8];
				cube[RIGHT][6] = cube[FRONT][6];
				cube[RIGHT][7] = cube[FRONT][7];
				cube[RIGHT][8] = cube[FRONT][8];
				cube[FRONT][6] = cube[LEFT][6];
				cube[FRONT][7] = cube[LEFT][7];
				cube[FRONT][8] = cube[LEFT][8];
				cube[LEFT][6] = temp1;
				cube[LEFT][7] = temp2;
				cube[LEFT][8] = temp3;
			}
			if (d == CCW) {
				for (int i = 0; i < 3; i++) {
					char temp1 = cube[BACK][6];
					char temp2 = cube[BACK][7];
					char temp3 = cube[BACK][8];
					cube[BACK][6] = cube[RIGHT][6];
					cube[BACK][7] = cube[RIGHT][7];
					cube[BACK][8] = cube[RIGHT][8];
					cube[RIGHT][6] = cube[FRONT][6];
					cube[RIGHT][7] = cube[FRONT][7];
					cube[RIGHT][8] = cube[FRONT][8];
					cube[FRONT][6] = cube[LEFT][6];
					cube[FRONT][7] = cube[LEFT][7];
					cube[FRONT][8] = cube[LEFT][8];
					cube[LEFT][6] = temp1;
					cube[LEFT][7] = temp2;
					cube[LEFT][8] = temp3;
				}
			}
			break;

		case 'F':

			if (d == CW) {
				char temp1 = cube[UP][6]; char temp2 = cube[UP][7]; char temp3 = cube[UP][8];
				cube[UP][6] = cube[LEFT][8]; cube[UP][7] = cube[LEFT][5]; cube[UP][8] = cube[LEFT][2];
				cube[LEFT][8] = cube[DOWN][2];  cube[LEFT][5] = cube[DOWN][1]; cube[LEFT][2] = cube[DOWN][0];
				cube[DOWN][0] = cube[RIGHT][6]; cube[DOWN][1] = cube[RIGHT][3]; cube[DOWN][2] = cube[RIGHT][0];
				cube[RIGHT][0] = temp1; cube[RIGHT][3] = temp2; cube[RIGHT][6] = temp3;
			}
			if (d == CCW) {
				for (int i = 0; i < 3; i++) {
					char temp1 = cube[UP][6]; char temp2 = cube[UP][7]; char temp3 = cube[UP][8];
					cube[UP][6] = cube[LEFT][8]; cube[UP][7] = cube[LEFT][5]; cube[UP][8] = cube[LEFT][2];
					cube[LEFT][8] = cube[DOWN][2];  cube[LEFT][5] = cube[DOWN][1]; cube[LEFT][2] = cube[DOWN][0];
					cube[DOWN][0] = cube[RIGHT][6]; cube[DOWN][1] = cube[RIGHT][3]; cube[DOWN][2] = cube[RIGHT][0];
					cube[RIGHT][0] = temp1; cube[RIGHT][3] = temp2; cube[RIGHT][6] = temp3;
				}
			}
			break;

		case 'B':
			if (d == CW) {
				char temp1 = cube[UP][2]; char temp2 = cube[UP][1]; char temp3 = cube[UP][0];
				cube[UP][2] = cube[RIGHT][8]; cube[UP][1] = cube[RIGHT][5]; cube[UP][0] = cube[RIGHT][2];
				cube[RIGHT][8] = cube[DOWN][6]; cube[RIGHT][5] = cube[DOWN][7]; cube[RIGHT][2] = cube[DOWN][8];
				cube[DOWN][6] = cube[LEFT][0]; cube[DOWN][7] = cube[LEFT][3]; cube[DOWN][8] = cube[LEFT][6];
				cube[LEFT][0] = temp1; cube[LEFT][3] = temp2; cube[LEFT][6] = temp3;
			}
			if (d == CCW) {
				for (int i = 0; i < 3; i++) {
					char temp1 = cube[UP][2]; char temp2 = cube[UP][1]; char temp3 = cube[UP][0];
					cube[UP][2] = cube[RIGHT][8]; cube[UP][1] = cube[RIGHT][5]; cube[UP][0] = cube[RIGHT][2];
					cube[RIGHT][8] = cube[DOWN][6]; cube[RIGHT][5] = cube[DOWN][7]; cube[RIGHT][2] = cube[DOWN][8];
					cube[DOWN][6] = cube[LEFT][0]; cube[DOWN][7] = cube[LEFT][3]; cube[DOWN][8] = cube[LEFT][6];
					cube[LEFT][0] = temp1; cube[LEFT][3] = temp2; cube[LEFT][6] = temp3;
				}
			}
			break;

		case 'L':

			if (d == CW) {
				char tmp1 = cube[UP][0]; char tmp2 = cube[UP][3]; char tmp3 = cube[UP][6];
				cube[UP][0] = cube[BACK][8]; cube[UP][3] = cube[BACK][5]; cube[UP][6] = cube[BACK][2];
				cube[BACK][2] = cube[DOWN][6]; cube[BACK][5] = cube[DOWN][3]; cube[BACK][8] = cube[DOWN][0];
				cube[DOWN][6] = cube[FRONT][6]; cube[DOWN][3] = cube[FRONT][3];  cube[DOWN][0] = cube[FRONT][0];
				cube[FRONT][0] = tmp1; cube[FRONT][3] = tmp2; cube[FRONT][6] = tmp3;
			}
			if (d == CCW) {
				for (int i = 0; i < 3; i++) {
					char tmp1 = cube[UP][0]; char tmp2 = cube[UP][3]; char tmp3 = cube[UP][6];
					cube[UP][0] = cube[BACK][8]; cube[UP][3] = cube[BACK][5]; cube[UP][6] = cube[BACK][2];
					cube[BACK][2] = cube[DOWN][6]; cube[BACK][5] = cube[DOWN][3]; cube[BACK][8] = cube[DOWN][0];
					cube[DOWN][6] = cube[FRONT][6]; cube[DOWN][3] = cube[FRONT][3];  cube[DOWN][0] = cube[FRONT][0];
					cube[FRONT][0] = tmp1; cube[FRONT][3] = tmp2; cube[FRONT][6] = tmp3;
				}
			}
			break;

		case 'R':

			if (d == CW) {
				char tmp1 = cube[UP][8]; char tmp2 = cube[UP][5]; char tmp3 = cube[UP][2];
				cube[UP][8] = cube[FRONT][8]; cube[UP][5] = cube[FRONT][5];  cube[UP][2] = cube[FRONT][2];
				cube[FRONT][8] = cube[DOWN][8]; cube[FRONT][5] = cube[DOWN][5]; cube[FRONT][2] = cube[DOWN][2];
				cube[DOWN][8] = cube[BACK][0]; cube[DOWN][5] = cube[BACK][3]; cube[DOWN][2] = cube[BACK][6];
				cube[BACK][0] = tmp1; cube[BACK][3] = tmp2; cube[BACK][6] = tmp3;
			}
			if (d == CCW) {
				for (int i = 0; i < 3; i++) {
					char tmp1 = cube[UP][8]; char tmp2 = cube[UP][5]; char tmp3 = cube[UP][2];
					cube[UP][8] = cube[FRONT][8]; cube[UP][5] = cube[FRONT][5];  cube[UP][2] = cube[FRONT][2];
					cube[FRONT][8] = cube[DOWN][8]; cube[FRONT][5] = cube[DOWN][5]; cube[FRONT][2] = cube[DOWN][2];
					cube[DOWN][8] = cube[BACK][0]; cube[DOWN][5] = cube[BACK][3]; cube[DOWN][2] = cube[BACK][6];
					cube[BACK][0] = tmp1; cube[BACK][3] = tmp2; cube[BACK][6] = tmp3;
				}
			}
			break;
	}
}

int T = 0;
int n = 0;


int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {

		char cube[6][9] = { { 'w', 'w','w','w','w','w','w','w','w'},
							{ 'y', 'y','y','y','y','y','y','y','y'},
							{ 'r', 'r','r','r','r','r','r','r','r'},
							{ 'o', 'o','o','o','o','o','o','o','o'},
							{ 'g', 'g','g','g','g','g','g','g','g'},
							{ 'b', 'b','b','b','b','b','b','b','b'} };

		cin >> n;
		char sides[1000];
		char dirs[1000];
		for (int j = 0; j < n; j++) {
			cin >> sides[j] >> dirs[j];
			if (dirs[j] == '-') {
				dirs[j] = CCW;
			}
			else if (dirs[j] == '+') {
				dirs[j] = CW;
			}
		}

		for (int j = 0; j < n; j++) {
			rt(sides[j], dirs[j], cube);
		}


		for (int j = 0; j < 9; j++) {
			cout << cube[UP][j] << " ";
			if ((j + 1) % 3 == 0) cout << '\n';
		}
	}


	return 0;
}
#include <bits/stdc++.h>
using namespace std;
enum SIDE {
	UP,
	DOWN,
	FRONT,
	BACK,
	LEFT,
	RIGHT
};

enum DIR {
	CCW,
	CW
};

void part1(char s, char d, char cube[][9]) {
	if (s == 'U') s = UP;
	if (s == 'D') s = DOWN;
	if (s == 'F') s = FRONT;
	if (s == 'B') s = BACK;
	if (s == 'L') s = LEFT;
	if (s == 'R') s = RIGHT;

	int temp = cube[s][0];
	int temp1 = cube[s][2];
	int temp3 = cube[s][1];
	cube[s][0] = cube[s][6];
	cube[s][1] = cube[s][3];
	cube[s][2] = temp;
	cube[s][3] = cube[s][7];
	cube[s][6] = cube[s][8];
	cube[s][7] = cube[s][5];
	cube[s][8] = temp1;
	cube[s][5] = temp3;
}
void rt(char s, char d, char cube[][9]) {

	if (d == CW) {
		part1(s, d, cube);
	}
	if (d == CCW) {
		for (int i = 0; i < 3; i++) {
			part1(s, d, cube);
		}
	}

	switch (s) {
	case 'U':
		if (d == CW) {
			char temp1 = cube[LEFT][0];
			char temp2 = cube[LEFT][1];
			char temp3 = cube[LEFT][2];
			cube[LEFT][0] = cube[FRONT][0];
			cube[LEFT][1] = cube[FRONT][1];
			cube[LEFT][2] = cube[FRONT][2];
			cube[FRONT][0] = cube[RIGHT][0];
			cube[FRONT][1] = cube[RIGHT][1];
			cube[FRONT][2] = cube[RIGHT][2];
			cube[RIGHT][0] = cube[BACK][0];
			cube[RIGHT][1] = cube[BACK][1];
			cube[RIGHT][2] = cube[BACK][2];
			cube[BACK][0] = temp1;
			cube[BACK][1] = temp2;
			cube[BACK][2] = temp3;
		}
		if (d == CCW) {
			for (int i = 0; i < 3; i++) {
				char temp1 = cube[LEFT][0];
				char temp2 = cube[LEFT][1];
				char temp3 = cube[LEFT][2];
				cube[LEFT][0] = cube[FRONT][0];
				cube[LEFT][1] = cube[FRONT][1];
				cube[LEFT][2] = cube[FRONT][2];
				cube[FRONT][0] = cube[RIGHT][0];
				cube[FRONT][1] = cube[RIGHT][1];
				cube[FRONT][2] = cube[RIGHT][2];
				cube[RIGHT][0] = cube[BACK][0];
				cube[RIGHT][1] = cube[BACK][1];
				cube[RIGHT][2] = cube[BACK][2];
				cube[BACK][0] = temp1;
				cube[BACK][1] = temp2;
				cube[BACK][2] = temp3;
			}
		}

		break;

	case 'D':

		if (d == CW) {
			char temp1 = cube[BACK][6];
			char temp2 = cube[BACK][7];
			char temp3 = cube[BACK][8];
			cube[BACK][6] = cube[RIGHT][6];
			cube[BACK][7] = cube[RIGHT][7];
			cube[BACK][8] = cube[RIGHT][8];
			cube[RIGHT][6] = cube[FRONT][6];
			cube[RIGHT][7] = cube[FRONT][7];
			cube[RIGHT][8] = cube[FRONT][8];
			cube[FRONT][6] = cube[LEFT][6];
			cube[FRONT][7] = cube[LEFT][7];
			cube[FRONT][8] = cube[LEFT][8];
			cube[LEFT][6] = temp1;
			cube[LEFT][7] = temp2;
			cube[LEFT][8] = temp3;
		}
		if (d == CCW) {
			for (int i = 0; i < 3; i++) {
				char temp1 = cube[BACK][6];
				char temp2 = cube[BACK][7];
				char temp3 = cube[BACK][8];
				cube[BACK][6] = cube[RIGHT][6];
				cube[BACK][7] = cube[RIGHT][7];
				cube[BACK][8] = cube[RIGHT][8];
				cube[RIGHT][6] = cube[FRONT][6];
				cube[RIGHT][7] = cube[FRONT][7];
				cube[RIGHT][8] = cube[FRONT][8];
				cube[FRONT][6] = cube[LEFT][6];
				cube[FRONT][7] = cube[LEFT][7];
				cube[FRONT][8] = cube[LEFT][8];
				cube[LEFT][6] = temp1;
				cube[LEFT][7] = temp2;
				cube[LEFT][8] = temp3;
			}
		}
		break;

	case 'F':

		if (d == CW) {
			char temp1 = cube[UP][6]; char temp2 = cube[UP][7]; char temp3 = cube[UP][8];
			cube[UP][6] = cube[LEFT][8]; cube[UP][7] = cube[LEFT][5]; cube[UP][8] = cube[LEFT][2];
			cube[LEFT][8] = cube[DOWN][2];  cube[LEFT][5] = cube[DOWN][1]; cube[LEFT][2] = cube[DOWN][0];
			cube[DOWN][0] = cube[RIGHT][6]; cube[DOWN][1] = cube[RIGHT][3]; cube[DOWN][2] = cube[RIGHT][0];
			cube[RIGHT][0] = temp1; cube[RIGHT][3] = temp2; cube[RIGHT][6] = temp3;
		}
		if (d == CCW) {
			for (int i = 0; i < 3; i++) {
				char temp1 = cube[UP][6]; char temp2 = cube[UP][7]; char temp3 = cube[UP][8];
				cube[UP][6] = cube[LEFT][8]; cube[UP][7] = cube[LEFT][5]; cube[UP][8] = cube[LEFT][2];
				cube[LEFT][8] = cube[DOWN][2];  cube[LEFT][5] = cube[DOWN][1]; cube[LEFT][2] = cube[DOWN][0];
				cube[DOWN][0] = cube[RIGHT][6]; cube[DOWN][1] = cube[RIGHT][3]; cube[DOWN][2] = cube[RIGHT][0];
				cube[RIGHT][0] = temp1; cube[RIGHT][3] = temp2; cube[RIGHT][6] = temp3;
			}
		}
		break;

	case 'B':
		if (d == CW) {
			char temp1 = cube[UP][2]; char temp2 = cube[UP][1]; char temp3 = cube[UP][0];
			cube[UP][2] = cube[RIGHT][8]; cube[UP][1] = cube[RIGHT][5]; cube[UP][0] = cube[RIGHT][2];
			cube[RIGHT][8] = cube[DOWN][6]; cube[RIGHT][5] = cube[DOWN][7]; cube[RIGHT][2] = cube[DOWN][8];
			cube[DOWN][6] = cube[LEFT][0]; cube[DOWN][7] = cube[LEFT][3]; cube[DOWN][8] = cube[LEFT][6];
			cube[LEFT][0] = temp1; cube[LEFT][3] = temp2; cube[LEFT][6] = temp3;
		}
		if (d == CCW) {
			for (int i = 0; i < 3; i++) {
				char temp1 = cube[UP][2]; char temp2 = cube[UP][1]; char temp3 = cube[UP][0];
				cube[UP][2] = cube[RIGHT][8]; cube[UP][1] = cube[RIGHT][5]; cube[UP][0] = cube[RIGHT][2];
				cube[RIGHT][8] = cube[DOWN][6]; cube[RIGHT][5] = cube[DOWN][7]; cube[RIGHT][2] = cube[DOWN][8];
				cube[DOWN][6] = cube[LEFT][0]; cube[DOWN][7] = cube[LEFT][3]; cube[DOWN][8] = cube[LEFT][6];
				cube[LEFT][0] = temp1; cube[LEFT][3] = temp2; cube[LEFT][6] = temp3;
			}
		}
		break;

	case 'L':

		if (d == CW) {
			char tmp1 = cube[UP][0]; char tmp2 = cube[UP][3]; char tmp3 = cube[UP][6];
			cube[UP][0] = cube[BACK][8]; cube[UP][3] = cube[BACK][5]; cube[UP][6] = cube[BACK][2];
			cube[BACK][2] = cube[DOWN][6]; cube[BACK][5] = cube[DOWN][3]; cube[BACK][8] = cube[DOWN][0];
			cube[DOWN][6] = cube[FRONT][6]; cube[DOWN][3] = cube[FRONT][3];  cube[DOWN][0] = cube[FRONT][0];
			cube[FRONT][0] = tmp1; cube[FRONT][3] = tmp2; cube[FRONT][6] = tmp3;
		}
		if (d == CCW) {
			for (int i = 0; i < 3; i++) {
				char tmp1 = cube[UP][0]; char tmp2 = cube[UP][3]; char tmp3 = cube[UP][6];
				cube[UP][0] = cube[BACK][8]; cube[UP][3] = cube[BACK][5]; cube[UP][6] = cube[BACK][2];
				cube[BACK][2] = cube[DOWN][6]; cube[BACK][5] = cube[DOWN][3]; cube[BACK][8] = cube[DOWN][0];
				cube[DOWN][6] = cube[FRONT][6]; cube[DOWN][3] = cube[FRONT][3];  cube[DOWN][0] = cube[FRONT][0];
				cube[FRONT][0] = tmp1; cube[FRONT][3] = tmp2; cube[FRONT][6] = tmp3;
			}
		}
		break;

	case 'R':

		if (d == CW) {
			char tmp1 = cube[UP][8]; char tmp2 = cube[UP][5]; char tmp3 = cube[UP][2];
			cube[UP][8] = cube[FRONT][8]; cube[UP][5] = cube[FRONT][5];  cube[UP][2] = cube[FRONT][2];
			cube[FRONT][8] = cube[DOWN][8]; cube[FRONT][5] = cube[DOWN][5]; cube[FRONT][2] = cube[DOWN][2];
			cube[DOWN][8] = cube[BACK][0]; cube[DOWN][5] = cube[BACK][3]; cube[DOWN][2] = cube[BACK][6];
			cube[BACK][0] = tmp1; cube[BACK][3] = tmp2; cube[BACK][6] = tmp3;
		}
		if (d == CCW) {
			for (int i = 0; i < 3; i++) {
				char tmp1 = cube[UP][8]; char tmp2 = cube[UP][5]; char tmp3 = cube[UP][2];
				cube[UP][8] = cube[FRONT][8]; cube[UP][5] = cube[FRONT][5];  cube[UP][2] = cube[FRONT][2];
				cube[FRONT][8] = cube[DOWN][8]; cube[FRONT][5] = cube[DOWN][5]; cube[FRONT][2] = cube[DOWN][2];
				cube[DOWN][8] = cube[BACK][0]; cube[DOWN][5] = cube[BACK][3]; cube[DOWN][2] = cube[BACK][6];
				cube[BACK][0] = tmp1; cube[BACK][3] = tmp2; cube[BACK][6] = tmp3;
			}
		}
		break;
	}
}

int T = 0;
int n = 0;


int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {

		char cube[6][9] = { { 'w', 'w','w','w','w','w','w','w','w'},
							{ 'y', 'y','y','y','y','y','y','y','y'},
							{ 'r', 'r','r','r','r','r','r','r','r'},
							{ 'o', 'o','o','o','o','o','o','o','o'},
							{ 'g', 'g','g','g','g','g','g','g','g'},
							{ 'b', 'b','b','b','b','b','b','b','b'} };

		cin >> n;
		char sides[1000];
		char dirs[1000];
		for (int j = 0; j < n; j++) {
			cin >> sides[j] >> dirs[j];
			if (dirs[j] == '-') {
				dirs[j] = CCW;
			}
			else if (dirs[j] == '+') {
				dirs[j] = CW;
			}
		}

		for (int j = 0; j < n; j++) {
			rt(sides[j], dirs[j], cube);
		}


		for (int j = 0; j < 9; j++) {
			cout << cube[UP][j] << " ";
			if ((j + 1) % 3 == 0) cout << '\n';
		}
	}


	return 0;
}
