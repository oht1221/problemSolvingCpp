#include<bits/stdc++.h>
using namespace std;
int dice[10] = { 0, };
int point = 0;
int ans = 0;

typedef struct _NODE {
	int point;
	_NODE* red;
	_NODE* blue;
	
	_NODE(int p, _NODE* r, _NODE* b) : point(p), red(r), blue(b) {}
} node;

node* horse[4] = { NULL, NULL, NULL, NULL };

node* moveForward(node* n, int dist) {

	int cnt = dist;
	while (cnt != 0) {
		if (n->point == 0) {
			return n;
		}

		if (cnt == dist) {
			if (n->blue != NULL) {
				n = n->blue;
			}
			else {
				n = n->red;
			}
		}
		else {
			n = n->red;
		}
		cnt--;
	}
	if (find(horse, horse + 4, n) == horse + 4 || n->point == 0) {
		return n;
	}
	else return NULL;
}

void dfs(int idx) {
	if (idx >= 10) {
		ans = max(ans, point);
		return;
	}

	int d = dice[idx];
	for (auto &h : horse) {
		if (h->point == 0) continue; //도착한 것 제외
		node* trackBack = h;
		node* ptr = moveForward(h, d);
		if (ptr != NULL) {
			h = ptr;
			point += h->point;
		}
		else continue;
		dfs(idx + 1);

		point -= h->point;
		h = trackBack;
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}
	node* ptr = NULL;

	ptr = new node(0, NULL, NULL);
	ptr = new node(40, ptr, NULL);
	
	node* ptr38 = new node(38, ptr, NULL);
	node* ptr35 = new node(35, ptr, NULL);

	ptr = new node(36, ptr38, NULL);
	ptr = new node(34, ptr, NULL);
	ptr = new node(32, ptr, NULL);
	node* ptr30 = new node(30, ptr, NULL);
	ptr = new node(28, ptr30, NULL);
	ptr = new node(26, ptr, NULL);
	ptr = new node(24, ptr, NULL);
	ptr = new node(22, ptr, NULL);
	node* ptr20 = new node(20, ptr, NULL);
	ptr = new node(18, ptr20, NULL);
	ptr = new node(16, ptr, NULL);
	ptr = new node(14, ptr, NULL);
	ptr = new node(12, ptr, NULL);
	node* ptr10 = new node(10, ptr, NULL);
	ptr = new node(8, ptr10, NULL);
	ptr = new node(6, ptr, NULL);
	ptr = new node(4, ptr, NULL);
	ptr = new node(2, ptr, NULL);
	node* ptr0 = new node(-1, ptr, NULL);

	ptr = new node(30, ptr35, NULL);
	ptr = new node(25, ptr, NULL);
	
	node* ptr19 = new node(19, ptr, NULL);
	node* ptr24 = new node(24, ptr, NULL);
	node* ptr26 = new node(26, ptr, NULL);

	ptr = new node(16, ptr19, NULL);
	ptr = new node(13, ptr, NULL);
	ptr10->blue = ptr;

	ptr = new node(22, ptr24, NULL);
	ptr20->blue = ptr;

	ptr = new node(27, ptr26, NULL);
	ptr = new node(28, ptr, NULL);
	ptr30->blue = ptr;

	for (int i = 0; i < 4; i++) {
		horse[i] = ptr0;
	}

	if (moveForward(horse[0], dice[0]) != NULL) {
		horse[0] = moveForward(horse[0], dice[0]);
		point += horse[0]->point;
	}
	
	dfs(1);

	cout << ans << '\n';
	return 0;
}
