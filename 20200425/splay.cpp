#include <bits/stdc++.h>

using namespace std;

const int maxn = 123456;

int fa[maxn], dat[maxn], val[maxn], rev[maxn], ch[maxn][2];

inline void update(int x) { val[x] = dat[x] ^ val[ch[x][0]] ^ val[ch[x][1]]; }
inline bool unroot(int x) { return ch[fa[x]][0]==x || ch[fa[x]][1] == x; }
inline int chr(int x) { return ch[fa[x]][1] == x; }
inline void maintain(int x) {
	if(rev[x]) {
		rev[x] = 0; rev[ch[x][0]] ^= 1; rev[ch[x][1]] ^= 1;
		swap(ch[x][0], ch[x][1]);
	}
}
void rotate(int x) {
	int y = fa[x], z = fa[y], k = chr(x), s = ch[x][k^1];
	if(unroot(y)) ch[z][chr(y)] = x; fa[x] = z;
	ch[y][k] = s; fa[s] = y;
	ch[x][k^1] = y; fa[y] = x;
	update(y); update(x);
}
int stk[maxn], top;
void splay(int x) {
	stk[0] = x; top = 1;
	for(int y = x; unroot(y); y = fa[y]) stk[top++] = fa[y];
	while(top) maintain(stk[--top]);
	while(unroot(x)) {
		if(unroot(fa[x])) rotate(chr(x) ^ chr(fa[x]) ? x : fa[x]);
		rotate(x);
	}
}
void access(int x) {
	for(int y = 0; x; y = x, x = fa[x]) {
		splay(x); ch[x][1] = y; update(x);
	}
}
void makeroot(int x) {
	access(x); splay(x); rev[x] ^= 1;
}
int findroot(int x) {
	access(x); splay(x);
	while(ch[x][0]) x = ch[x][0];
	return x;
}
void split(int x, int y) {
	makeroot(x); access(y); splay(y);
}
void link(int x, int y) {
	if(findroot(x) != findroot(y)) {
		makeroot(x); splay(x); fa[x] = y;
	}
}
void cut(int x, int y) {
	split(x, y);
	if(ch[y][0] == x && !ch[x][1])
		ch[y][0] = fa[x] = 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, op, x, y;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> dat[i], val[i] = dat[i];
	while(m--) {
		cin >> op >> x >> y;
		if(!op) {
			split(x, y);
			cout << val[y] << '\n';
		} else if(op == 1) {
			link(x, y);
		} else if(op == 2) {
			cut(x, y);
		} else {
			splay(x); dat[x] = y;
			update(x);
		}
	}
	return 0;
}
