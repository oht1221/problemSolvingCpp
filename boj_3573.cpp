#include<iostream>
#include<vector>
using namespace std;
void fun1(vector<vector<char>>& side, char dir) {
	if ('+' == dir) {
		char temp1 = side[0][1]; side[0][1] = side[1][0]; side[1][0] = side[2][1]; side[2][1] = side[1][2]; side[1][2] = temp1;
		temp1 = side[0][0];  side[0][0] = side[2][0]; side[2][0] = side[2][2]; side[2][2] = side[0][2]; side[0][2] = temp1;
	}
	else if ('-' == dir) {
		for (int i = 0; i < 3; i++) {
			char temp1 = side[0][1]; side[0][1] = side[1][0]; side[1][0] = side[2][1]; side[2][1] = side[1][2]; side[1][2] = temp1;
			temp1 = side[0][0];  side[0][0] = side[2][0]; side[2][0] = side[2][2]; side[2][2] = side[0][2]; side[0][2] = temp1;
		}
	}

}
void fun2(char** s1, char** s2, char** s3, char** s4, char dir) {
	if('+' == dir){
		char temp[3] = { *s1[0], *s1[1], *s1[2] };
		*s1[0] = *s4[0], * s1[1] = *s4[1], * s1[2] = *s4[2];
		*s4[0] = *s3[0], * s4[1] = *s3[1], * s4[2] = *s3[2];
		*s3[0] = *s2[0], * s3[1] = *s2[1], * s3[2] = *s2[2];
		*s2[0] = temp[0], * s2[1] = temp[1], * s2[2] = temp[2];
	}
	else if ('-' == dir) {
		for (int i = 0; i < 3; i++) {
			char temp[3] = { *s1[0], *s1[1], *s1[2] };
			*s1[0] = *s4[0], * s1[1] = *s4[1], * s1[2] = *s4[2];
			*s4[0] = *s3[0], * s4[1] = *s3[1], * s4[2] = *s3[2];
			*s3[0] = *s2[0], * s3[1] = *s2[1], * s3[2] = *s2[2];
			*s2[0] = temp[0], * s2[1] = temp[1], * s2[2] = temp[2];
		}
		//char temp[3] = { *s1[0], *s1[1], *s1[2] };
		//*s1[0] = *s2[0], *s1[1] = *s2[1], *s1[2] = *s2[2];
		//*s2[0] = *s3[0], *s2[1] = *s3[1], *s2[2] = *s3[2];
		//*s3[0] = *s4[0], *s3[1] = *s4[1], *s3[2] = *s4[2];
		//*s4[0] = temp[0], *s4[1] = temp[1], *s4[2] = temp[2];
	}
}
void rotate(vector<vector<char>>& U, vector<vector<char>>& L, vector<vector<char>>& F, vector<vector<char>>& R, vector<vector<char>>& B, vector<vector<char>>& D, char side, char dir) {

	switch (side) {
	case 'U': {
		char* s1[3] = { &B[0][2], &B[0][1], &B[0][0] }; char* s2[3] = { &R[0][2], &R[0][1], &R[0][0] };
		char* s3[3] = { &F[0][2], &F[0][1], &F[0][0] }; char* s4[3] = { &L[0][2], &L[0][1], &L[0][0] };
		fun1(U, dir);
		fun2(s1, s2, s3, s4, dir);
		break;
	}
	case 'L': {
		char* s1[3] = { &U[0][0], &U[1][0], &U[2][0] }; char* s2[3] = { &F[0][0], &F[1][0], &F[2][0] };
		char* s3[3] = { &D[0][0], &D[1][0], &D[2][0] }; char* s4[3] = { &B[2][2], &B[1][2], &B[0][2] };
		fun1(L, dir);
		fun2(s1, s2, s3, s4, dir);
		break;
	}
	case 'F': {
		fun1(F, dir);
		char* s1[3] = { &U[2][0], &U[2][1], &U[2][2] }; char* s2[3] = { &R[0][0], &R[1][0], &R[2][0] };
		char* s3[3] = { &D[0][2], &D[0][1], &D[0][0] }; char* s4[3] = { &L[2][2], &L[1][2], &L[0][2] };

		fun2(s1, s2, s3, s4, dir);
		break;
	}
	case 'R': {
		fun1(R, dir);
		char* s1[3] = { &U[2][2], &U[1][2], &U[0][2] }; char* s2[3] = { &B[0][0], &B[1][0], &B[2][0] };
		char* s3[3] = { &D[2][2], &D[1][2], &D[0][2] }; char* s4[3] = { &F[2][2], &F[1][2], &F[0][2] };

		fun2(s1, s2, s3, s4, dir);
		break;
	}
	case 'B': {
		fun1(B, dir);
		char* s1[3] = { &U[0][2], &U[0][1], &U[0][0] }; char* s2[3] = { &L[0][0], &L[1][0], &L[2][0] };
		char* s3[3] = { &D[2][2], &D[2][1], &D[2][0] }; char* s4[3] = { &R[2][2], &R[1][2], &R[0][2] };

		fun2(s1, s2, s3, s4, dir);
		break;
	}
	case 'D':
		fun1(D, dir);
		char* s1[3] = { &F[2][0], &F[2][1] , &F[2][2] }; char* s2[3] = { &R[2][0], &R[2][1] , &R[2][2] };
		char* s3[3] = { &B[2][0], &B[2][1] , &B[2][2] }; char* s4[3] = { &L[2][0], &L[2][1] , &L[2][2] };
		fun2(s1, s2, s3, s4, dir);
		break;
	}

}
int main() {
	vector<char> ans;
	int N = 0; cin >> N;

	for (int i = 0; i < N; i++) {
		int M = 0; cin >> M;

		vector<vector<char>> U = { {'w', 'w','w'},{'w', 'w','w'}, {'w', 'w','w'} };
		vector<vector<char>> L = { {'g', 'g','g'}, {'g', 'g','g'}, {'g', 'g','g'} };
		vector<vector<char>> F = { {'r', 'r','r'}, {'r', 'r','r'}, {'r', 'r','r'} };
		vector<vector<char>> R = { {'b', 'b','b'}, {'b', 'b','b'},  {'b', 'b','b'} };
		vector<vector<char>> B = { {'o', 'o', 'o'}, {'o', 'o', 'o'},{'o', 'o', 'o'} };
		vector<vector<char>> D = { {'y','y','y'}, {'y','y','y'},{'y','y','y'} };

		for (int j = 0; j < M; j++) {
			char side = 0; char dir = 0;
			cin >> side >> dir;
			rotate(U, L, F, R, B, D, side, dir);
		}

		for (int k = 0; k < 3; k++) {
			for (int l = 0; l < 3; l++) {
				//cout << U[k][l];
				ans.push_back(U[k][l]);
			}
			//cout << endl;
		}
	}
	int num = ans.size();
	for (int m = 0; m < num; m++) {
		if (m % 3 == 0 && m != 0) cout << endl;
		cout << ans[m];
	}
	return 0;

}
