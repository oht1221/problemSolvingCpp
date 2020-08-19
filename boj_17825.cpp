#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; i++)
typedef struct _node {
	int point;
	_node* red;
	_node* blue;

	void setNode(int p, _node* r, _node* b) {
		this->point = p;
		this->red = r;
		this->blue = b;
	}
} node;

typedef struct _hrs {
	int point;
	_node* pos;
	bool isOver;
} hrs;

node nodes[33];
hrs hrses[4];
int dcs[10];
int ans = 0;

bool isLast(node* n) {
	return (n->red == NULL) && (n->blue == NULL);
}

node* move(hrs* h, int dc) {
	node* cur = h->pos;
	FOR(i, 0, dc) {
		node* nr = cur->red;
		node* nb = cur->blue;
		int flag = 0;
		if (0 != i) {
			if (nr) {
				cur = nr; flag = 1;
			}
		}
		else {
			if (nb) { // 출발지에서 blue 있으면
				cur = nb; flag = 1;
			} 
			else if (nr) {
				cur = nr; flag = 1;
			}
		}
		if (flag == 0) break;
	}
	return cur;
}

bool isOcpd(node* target) {
	bool ret = false;
	FOR(i, 0, 4) {
		if (hrses[i].pos == target && !hrses[i].isOver) {
			ret = true;
			break;
		}
	}
	return ret;
}
void dfs(int stage, int sum) {

	if (stage == 10) {
		ans = max(ans, sum);
		return;
	}

	int dc = dcs[stage];

	FOR(i, 0, 4) {
		hrs* h = hrses + i;
		if (h->isOver) continue; //도착한 말

		node* rollbackP = h->pos;
		bool rollbackO = h->isOver;

		node* target = move(h, dc);
		int plus = target->point;

		if (isOcpd(target)) continue;
		else {
			h->pos = target;
			if (isLast(target)) h->isOver = true;
		}
		sum += plus;
		dfs(stage + 1, sum);
		sum -= plus; h->pos = rollbackP; h->isOver = rollbackO;
	}
}

void check() {
	for (int i = 0; i < 33; i++) {
		cout << (nodes+i)->point << " ";
		if ((nodes + i)->red != NULL)	cout << (nodes + i)->red->point << " ";
		if ((nodes + i)->blue != NULL) cout << (nodes + i)->blue->point << " ";
		cout << endl;
	}
}

int main() {
	nodes[0].setNode(0, nodes + 1, NULL);
	nodes[1].setNode(2, nodes + 2, NULL);
	nodes[2].setNode(4, nodes + 3, NULL);
	nodes[3].setNode(6, nodes + 4, NULL);
	nodes[4].setNode(8, nodes + 5, NULL);

	nodes[5].setNode(10, nodes + 6, nodes + 21);
	nodes[6].setNode(12, nodes + 7, NULL);
	nodes[7].setNode(14, nodes + 8, NULL);
	nodes[8].setNode(16, nodes + 9, NULL);
	nodes[9].setNode(18, nodes + 10, NULL);
	nodes[10].setNode(20, nodes + 11, nodes + 31);
	nodes[11].setNode(22, nodes + 12, NULL);
	nodes[12].setNode(24, nodes + 13, NULL);
	nodes[13].setNode(26, nodes + 14, NULL);
	nodes[14].setNode(28, nodes + 15, NULL);
	nodes[15].setNode(30, nodes + 16, nodes + 27);
	nodes[16].setNode(32, nodes + 17, NULL);
	nodes[17].setNode(34, nodes + 18, NULL);
	nodes[18].setNode(36, nodes + 19, NULL);
	nodes[19].setNode(38, nodes + 20, NULL);
	nodes[20].setNode(40, nodes + 32, NULL);

	nodes[21].setNode(13, nodes + 22, NULL);
	nodes[22].setNode(16, nodes + 23, NULL);
	nodes[23].setNode(19, nodes + 24, NULL);
	nodes[24].setNode(25, nodes + 29, NULL);

	nodes[25].setNode(26, nodes + 24, NULL);
	nodes[26].setNode(27, nodes + 25, NULL);
	nodes[27].setNode(28, nodes + 26, NULL);
	nodes[28].setNode(35, nodes + 20, NULL);
	nodes[29].setNode(30, nodes + 28, NULL);
	nodes[30].setNode(24, nodes + 24, NULL);
	nodes[31].setNode(22, nodes + 30, NULL);
	nodes[32].setNode(0, NULL, NULL);


	FOR(i, 0, 4) {
		hrses[i].point = 0;
		hrses[i].pos = nodes;
		hrses[i].isOver = false;
	}

	FOR(i, 0, 10) cin >> dcs[i];

	dfs(0, 0);
	cout << ans;
	return 0;

}