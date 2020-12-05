#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
enum _COLOR {
	WH,
	RD,
	BL
};

typedef struct _HORSE {
	int row;
	int col;
	int dir;
} horse;
int N = 0;
int K = 0;
vector<horse> H;
vector < vector<vector<int>>> pan;
vector<vector<int>> panColor;
map<int, int> opDir;
int rdir[4] = { 0, 0, -1, 1 };
int cdir[4] = { 1, -1, 0 , 0 };
bool isValid(int r, int c) {
	return 0 <= r && r < N && 0 <= c && c < N;
}
bool Move() {
	int blCnt = 0;
	for (int i = 0; i < K; i++) {

		int r = H[i].row; int c = H[i].col; int d = H[i].dir;

		vector<int> chunk;
		int rnext = r + rdir[d];
		int cnext = c + cdir[d];

		auto it = find(pan[r][c].begin(), pan[r][c].end(), i); // �� ��ġ�� �ִ� �� ���� �� ���� ��ġ ã��
		if (isValid(rnext, cnext) && panColor[rnext][cnext] == WH) {
			chunk.insert(chunk.begin(), it, pan[r][c].end()); //ã�� ���� �� ���� ����
			blCnt = 0;
		}

		if (isValid(rnext, cnext) && panColor[rnext][cnext] == RD) {
			chunk.insert(chunk.begin(), it, pan[r][c].end()); //ã�� ���� �� ���� ����
			reverse(chunk.begin(), chunk.end()); //���� ����
			blCnt = 0;
		}
		else if (!isValid(rnext, cnext) || (isValid(rnext, cnext) && panColor[rnext][cnext] == BL) ) {
			blCnt++;
			if (blCnt == 1) { 
				H[i].dir = opDir[H[i].dir];
				i--; //ù ��°�� �� �� �ٽ�
			}
			else if(blCnt == 2) {
				blCnt = 0;
			}
			continue; 
		}
		
		pan[rnext][cnext].insert(pan[rnext][cnext].end(), chunk.begin(), chunk.end()); // �� �̵� ��ġ�� �̵�
		for (auto num : chunk) {
			H[num].row = rnext;
			H[num].col = cnext;
		} //��� �� �̵� �Ϸ�
		pan[r][c].erase(it, pan[r][c].end()); // �� ���� ����

		if (pan[rnext][cnext].size() >= 4) return true;
	}

	return false;
}



int main() {
	cin >> N >> K;
	pan.assign(N, vector<vector<int>>(N));
	panColor.assign(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> panColor[i][j];
		}
	}
	opDir[0] = 1;
	opDir[1] = 0;
	opDir[2] = 3;
	opDir[3] = 2;

	for (int i = 0; i < K; i++) {
		int r = 0; int c = 0; int d = 0;
		cin >> r >> c >> d;
		pan[r - 1][c - 1].push_back(i); // �� ��ȣ, �� , �� 0���� ����
		horse h;
		h.row = r - 1; h.col = c - 1; h.dir = d - 1; // ���⵵ 0���� ����
		H.push_back(h);
	}

	int T = 0;
	while (++T) {
		if (T > 1000)break;

		bool result = Move();

		if (result) break;
	}

	if (T > 1000) cout << -1 << endl;
	else cout << T << endl;

	return 0;
}
