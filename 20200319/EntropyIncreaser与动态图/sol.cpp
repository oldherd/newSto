#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

namespace le {
	struct node {
		int dat, val, fa, rev;
		union { int ch[2]; struct{int ls, rs;}; };
		node() : dat(0), val(0), fa(0), ls(0), rs(0) {}
	};

	node tre[size];
	inline bool unroot(int x) { return tre[tre[x].fa].ls==x || tre[tre[x].fa].rs==x; }
	inline void update(int x) { tre[x].val = tre[tre[x].ls].val ^ tre[tre[x].rs].val ^ tre[x].dat; }
	void maintain(int x) {
		if(!tre[x].rev) return;
		tre[x].rev ^= 1;
		if(tre[x].ls) tre[tre[x].ls].rev ^= 1;
		if(tre[x].rs) tre[tre[x].rs].rev ^= 1;
		swap(tre[x].ls, tre[x].rs);
	}

	int stk[size], top;
	void rotate(int x) {
		int y = tre[x].fa, z = tre[y].fa, k = tre[y].rs==x, s = tre[x].ch[k^1];
		if(unroot(y)) tre[z].ch[tre[z].rs==y] = x; tre[x].fa = z;
		tre[y].ch[k] = s; tre[s].fa = y;
		tre[x].ch[k^1] = y; tre[y].fa = x;
		update(y); update(x); 
	}
	void splay(int x) {
		top = 0; stk[top++] = x;
 	   for(int y = x; unroot(y); y = tre[y].fa) stk[top++] = tre[y].fa;
  	  while(top) maintain(stk[--top]);
		while(unroot(x)) {
			if(unroot(tre[x].fa)) rotate((tre[tre[x].fa].ls==x) ^ (tre[tre[tre[x].fa].fa].ls==tre[x].fa) ? x : tre[x].fa);
			rotate(x);
		}
	}

	void access(int x) {
		for(int y = 0; x; y=x, x=tre[x].fa) {
			splay(x); tre[x].rs = y; update(x);
		}
	}

	void makeroot(int x) {
		access(x); splay(x); tre[x].rev ^= 1;	
	}

	void split(int x, int y) {
		makeroot(x); access(y); splay(y);	
	}

	int findroot(int x) {
		access(x); splay(x);
		while(tre[x].ls) x = tre[x].ls;
		return x;	
	}

	void link(int x, int y) {
		makeroot(x);
		tre[x].fa = y;
	}

	void cut(int x, int y) {
		split(x, y);
		if(tre[y].ls == x && !tre[x].rs) {
			tre[y].ls = tre[x].fa = 0;
			update(y);
		}
	}
};

namespace rv {
	struct node {
		int dat, val, fa, rev;
		union { int ch[2]; struct{int ls, rs;}; };
		node() : dat(0), val(0), fa(0), ls(0), rs(0) {}
	};

	node tre[size];
	inline bool unroot(int x) { return tre[tre[x].fa].ls==x || tre[tre[x].fa].rs==x; }
	inline void update(int x) { tre[x].val = tre[tre[x].ls].val ^ tre[tre[x].rs].val ^ tre[x].dat; }
	void maintain(int x) {
		if(!tre[x].rev) return;
		tre[x].rev ^= 1;
		if(tre[x].ls) tre[tre[x].ls].rev ^= 1;
		if(tre[x].rs) tre[tre[x].rs].rev ^= 1;
		swap(tre[x].ls, tre[x].rs);
	}

	int stk[size], top;
	void rotate(int x) {
		int y = tre[x].fa, z = tre[y].fa, k = tre[y].rs==x, s = tre[x].ch[k^1];
		if(unroot(y)) tre[z].ch[tre[z].rs==y] = x; tre[x].fa = z;
		tre[y].ch[k] = s; tre[s].fa = y;
		tre[x].ch[k^1] = y; tre[y].fa = x;
		update(y); update(x); 
	}
	void splay(int x) {
		top = 0; stk[top++] = x;
 	   for(int y = x; unroot(y); y = tre[y].fa) stk[top++] = tre[y].fa;
  	  while(top) maintain(stk[--top]);
		while(unroot(x)) {
			if(unroot(tre[x].fa)) rotate((tre[tre[x].fa].ls==x) ^ (tre[tre[tre[x].fa].fa].ls==tre[x].fa) ? x : tre[x].fa);
			rotate(x);
		}
	}

	void access(int x) {
		for(int y = 0; x; y=x, x=tre[x].fa) {
			splay(x); tre[x].rs = y; update(x);
		}
	}

	void makeroot(int x) {
		access(x); splay(x); tre[x].rev ^= 1;	
	}

	void split(int x, int y) {
		makeroot(x); access(y); splay(y);	
	}

	int findroot(int x) {
		access(x); splay(x);
		while(tre[x].ls) x = tre[x].ls;
		return x;	
	}

	void link(int x, int y) {
		makeroot(x);
		tre[x].fa = y;
	}

	void cut(int x, int y) {
		split(x, y);
		if(tre[y].ls == x && !tre[x].rs) {
			tre[y].ls = tre[x].fa = 0;
			update(y);
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	return 0;
}


