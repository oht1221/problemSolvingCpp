#include<bits/stdc++.h>
using namespace std;

int t = 0;
int sm, sc, si = 0;
unsigned char dt[100000];
char codes[4096] = { 0, };
char inputs[4096] = { 0, };
int pt = 0;
int iPt = 0;

vector<pair<int, int>> loops;
vector<int> loopStatus;
vector<int> loopClsCnt;

void initiate() {
	fill_n(dt, 100000, 0);
	fill_n(codes, 4096, 0);
	fill_n(inputs, 4096, 0);
	pt = 0;
	iPt = 0;
	loops = {};
	loopStatus = {};
	loopClsCnt = {};
}

int findFair(int idx, char type) {

	if(type == '['){
		for (int i = 0; i < loops.size(); i++) {
			if (loops[i].first == idx) return loops[i].second;
		}
	}		
	else if(type == ']') {
		for (int i = 0; i < loops.size(); i++) {
			if (loops[i].second == idx) return loops[i].first;
		}
	}
}

int findLoopNum(int open) {
	for (int i = 0; i < loops.size(); i++) {
		if (loops[i].first == open) return i;
	}
}

bool dtEqual(unsigned char* arr1, unsigned char* arr2) {
	for (int i = 0; i < sm; i++) {
		if (arr1[i] != arr2[i]) return false;
	}
	return true;
}
int interpret(int idx) {
	char code = codes[idx];
	int loopNum;
	int idxLoopOpen;

	switch (code) {
		case '-':
			dt[pt] = dt[pt] - 1;
			idx++;
			break;
		case '+':
			dt[pt] = dt[pt] + 1;
			idx++;
			break;
		case '<':
			pt = (pt - 1 + sm) % sm;
			idx++;
			break;
		case '>':
			pt = (pt + 1) % sm;
			idx++;
			break;
		case '[':
			loopNum = findLoopNum(idx);
			loopStatus[loopNum] = 1;

			if (dt[pt] == 0) {
				idx = findFair(idx, '[');
			}
			else idx++;
			break;
		case ']':
			idxLoopOpen = findFair(idx, ']');
			loopNum = findLoopNum(idxLoopOpen);
			loopStatus[loopNum] = 0;
			loopClsCnt[loopNum]++;

			if (dt[pt] != 0) {
				idx = findFair(idx, ']');
			}
			else idx++;
			break;
		case '.':
			idx++;
			break;
		case ',':
			if (iPt < si) {
				dt[pt] = inputs[iPt];
			}
			else {
				dt[pt] = 255;
			}
			iPt++;
			idx++;
			break;
	}
	return idx;
}

int main() {

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> sm >> sc >> si;
		initiate();
		stack<int> stk;
		for (int i = 0; i < sc; i++) {
			cin >> codes[i];
			if (codes[i] == '[') {
				stk.push(i);
			}
			else if (codes[i] == ']') {
				int idxLoopOpen = stk.top(); stk.pop();
				loops.push_back(make_pair(idxLoopOpen, i));
				loopStatus.push_back(0); 
				loopClsCnt.push_back(0);
			}
		}

		for (int i = 0; i < si; i++) {
			cin >> inputs[i];
		}

		int cPt = 0;
		int cnt = 0;

		while (cPt < sc && cnt < 50000000) {
			cPt = interpret(cPt);
			cnt++;
		}

		if (cPt >= sc) cout << "Terminates" << '\n';
		else {
			cout << "Loops" << '\n';
			int infinite1 = sc; int total = loopStatus.size();
			int infinite2 = 0;
			for (int i = 0; i < total; i++) {
				if (loopStatus[i] == 1 && loopClsCnt[i] != 0) {
					if (infinite1 > loops[i].first) {
						infinite1 = loops[i].first;
						infinite2 = loops[i].second;
					}
				}
			}
			
			if (infinite1 == sc) {
				infinite1 = cPt;			infinite2 = findFair(cPt, '[');
			}
			cout << infinite1 << " " << infinite2 << '\n';
		}
	}	
	return 0;

}

