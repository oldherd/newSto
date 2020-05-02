#include <bits/stdc++.h>

using namespace std;

struct node {
	int ch[2], fa, size, rev, dat;
	node() { size = fa = ch[0] = ch[1] = rev = dat = 0; }
};

vector<node> tre;
int tot = 1, root;

int chr(int x) {
	return tre[tre[x].fa].ch[1]==x;
}

void update(int x) {
	tre[x].size = tre[tre[x].ch[0]].size + tre[tre[x].ch[1]].size + 1;
}

void maintain(int x) {
	swap(tre[x].ch[0], tre[x].ch[1]);
	tre[x].rev ^= 1;
	tre[tre[x].ch[0]].rev ^= 1;
	tre[tre[x].ch[1]].rev ^= 1;
}

void rotate(int x) {
	int y = tre[x].fa, z = tre[y].fa, k = chr(x), s = tre[x].ch[k^1];
	tre[y].ch[k] = s; tre[s].fa = y;
	tre[z].ch[chr(y)] = x; tre[x].fa = z;
	tre[x].ch[k^1] = y; tre[y].fa = x;
	update(y); update(x);
}

void splay(int x, int tar = 0) {
	while(tre[x].fa != tar) {
		if(tre[tre[x].fa].fa != tar) rotate(chr(tre[x].fa)==chr(x) ? tre[x].fa : x);
		rotate(x);
	}
	if(!tar) root = x;
}

int build(int l, int r, int f) {
	int mid = (l + r) >> 1, id = tot++;
	tre[id].dat = mid;
	tre[id].fa = f;
	if(l == r) {
		tre[id].size = 1;
		return id;
	}
	if(l < mid) tre[id].ch[0] = build(l, mid-1, id);
	if(mid < r) tre[id].ch[1] = build(mid+1, r, id);
	update(id);
	return id;
}

int findkth(int k) {
	int cur = root;
	while(true) {
		if(tre[cur].rev) maintain(cur);
		if(tre[tre[cur].ch[0]].size == k) break;
		if(tre[tre[cur].ch[0]].size < k) k -= tre[tre[cur].ch[0]].size + 1, cur = tre[cur].ch[1];
		else cur = tre[cur].ch[0];
	}
	return cur;
}

void reverse(int l, int r) {
	int pre = findkth(l - 1);
	int post = findkth(r + 1);
	splay(pre);
	splay(post, pre);
	int cur = tre[post].ch[0];
//	swap(tre[cur].ch[0], tre[cur].ch[1]);
	tre[cur].rev ^= 1;
}

vector<int> stk;

void dfs(int cur) {
	if(tre[cur].rev) maintain(cur);
	if(tre[cur].ch[0]) dfs(tre[cur].ch[0]);
	stk.push_back(tre[cur].dat);
	if(tre[cur].ch[1]) dfs(tre[cur].ch[1]);
}

//void outputtre(int cur) {
//	if(tre[cur].ch[0]) outputtre(tre[cur].ch[0]);
//	cout << cur << " : " << tre[cur].dat << ' ' << tre[cur].rev << ' ' << tre[cur].ch[0] << ' ' << tre[cur].ch[1] << ' ' << tre[cur].fa << endl;
//	if(tre[cur].ch[1]) outputtre(tre[cur].ch[1]);
//}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, l, r;
	cin >> n >> m;
	tre.resize(n + 3);
	root = build(0, n+1, 0);
//	stk.clear();
//	dfs(root);
//	for(int cur: stk) cout << cur << ' ';
//	cout << endl;
	while(m--) {
		cin >> l >> r;
		reverse(l, r);
//		outputtre(root);
	}
//	stk.clear();
	dfs(root);
//	cout << "#########################" << endl; 
//	outputtre(root);
	for(int cur = 1; cur < stk.size() - 1; ++cur) cout << stk[cur] << ' ';
	cout << '\n';
	return 0;
}
