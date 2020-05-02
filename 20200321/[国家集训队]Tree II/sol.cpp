#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 123456;
const int mod = 51061;

struct node {
	ll dat, rev, tags, tagm, val;
	node* fa;
	union {
		node* ch[2];
		struct { node *ls, *rs; };	
	};
	node() : dat(1), rev(0), tags(0), tagm(1), val(1), ls(nullptr), rs(nullptr) {}

};

node tre[maxn];

ostream& operator << (ostream& cout, const node &os) {
	cout << "(node) [ ";
	cout << "dat = " << os.dat;
	cout << ", rev = " << os.rev;
	cout << ", tags = " << os.tags;
	cout << ", tagm = " << os.tagm;
	cout << ", val = " << os.val;
	cout << ", ls = ";
	if(os.ls==nullptr)
		cout << 0;
	else cout << os.ls - tre;
	cout << ", rs = ";
	if(os.rs==nullptr)
		cout << 0;
	else cout << os.rs - tre;
	cout << ", fa = ";
	if(os.fa==nullptr)
		cout << 0;
	else cout << os.fa - tre;
	cout << " ]";
	return cout;
}

int ttt;

void outputtre() {
	cout << "#####################" << endl;
	for(int i = 1; i <= ttt; ++i) {
		cout << i << " : " << tre[i] << endl;;
	}
	cout << "#####################" << endl;
}

inline void update(node* cur) {
	cur->val = cur->dat;
	if(cur->ls != nullptr) cur->val = (cur->val + cur->ls->val) % mod;
	if(cur->rs != nullptr) cur->val = (cur->val + cur->rs->val) % mod;
}
inline void flip(node *cur) { cur->rev ^= 1; swap(cur->ls, cur->rs); }
inline bool unroot(node *cur) {
	return cur != nullptr && cur->fa != nullptr && (cur->fa->ls==cur || cur->fa->rs==cur);
}
inline int chr(node* x) { return x->fa->rs==x; }

inline void pushtagm(node *cur, ll tgm) {
	cur->tagm = cur->tagm * tgm % mod;
	cur->tags = cur->tags * tgm % mod;
	cur->val = cur->val * tgm % mod;
	cur->dat = cur->dat * tgm % mod;
}
inline void pushtags(node* cur, ll tgs) {
	cur->tags = (cur->tags + tgs) % mod;
	cur->dat = (cur->dat + tgs) % mod;
	cur->val = (cur->val + tgs) % mod;
}
void maintain(node *cur) {
	if(cur->rev) {
		if(cur->ls != nullptr) flip(cur->ls);
		if(cur->rs != nullptr) flip(cur->rs);
		cur->rev ^= 1;
	}
	if(cur->tagm) {
		if(cur->ls != nullptr) pushtagm(cur->ls, cur->tagm);
		if(cur->rs != nullptr) pushtagm(cur->rs, cur->tagm);
		cur->tagm = 1;
	}
	if(cur->tags) {
		if(cur->ls != nullptr) pushtags(cur->ls, cur->tags);
		if(cur->rs != nullptr) pushtags(cur->rs, cur->tags);
		cur->tags = 0;
 	}
}

void rotate(node *x) {
	int k = chr(x);
	node *y = x->fa, *z = y->fa, *s = x->ch[k^1];
	if(unroot(y)) z->ch[chr(y)] = x; x->fa = z;
	y->ch[k] = s; if(s != nullptr) s->fa = y;
	x->ch[k^1] = y; y->fa = x;
	update(y); update(x);
}

node* stk[maxn];
int top = 0;
void splay(node *x) {
	stk[top++] = x;
	for(node* y = x; unroot(y); y = y->fa) stk[top++] = y;
	while(top) maintain(stk[--top]);
	while(unroot(x)) {
		if(unroot(x->fa)) rotate(chr(x)^chr(x->fa)?x:x->fa);
		rotate(x);
	}
}

void access(node *x) {
	for(node *y = nullptr; x != nullptr; y = x, x = x->fa) {
		splay(x); x->rs = y; update(x);
	}
}

void makeroot(node *x) {
	access(x); splay(x); flip(x);
}

void split(node *x, node *y) {
	makeroot(x);
	outputtre();
	 access(y); 
	 outputtre();
	 splay(y);
}

node* findroot(node *x) {
	access(x); splay(x);
	while(x->ls != nullptr) x = x->ls;
	return x;
}

void link(node *x, node *y) {
//	if(findroot(x) == findroot(y)) return;
	makeroot(x); x->fa = y;	
}

void cut(node *x, node *y) {
	split(x, y);
	if(y->ls == x && x->rs == nullptr) {
		x->fa = nullptr; y->ls = nullptr;
		update(y);
	}
}



int main() {
	int n, q, u, v, w, x;
	char op[2];
	scanf("%d %d", &n, &q);                             ttt = n;
	for(int i = 1; i < n; ++i) {
		scanf("%d %d", &u, &v); 
		link(tre + u, tre + v);
	}
	outputtre();
	while(q--) {
		scanf("%s %d %d", op, &u, &v);
		if(op[0] == '+') {
			scanf("%d", &w);
			split(tre + u, tre + v);
			pushtags(tre + v, w);
		} else if(op[0] == '-') {
			scanf("%d %d", &w, &x);
			cut(tre + u, tre + v);
			link(tre + w, tre + x);
		} else if(op[0] == '*') {
			scanf("%d", &w);
			split(tre + u, tre + v);
			outputtre();
			pushtagm(tre + v, w);
		} else {
			split(tre + u, tre + v);
			outputtre();
			printf("%lld\n", tre[v].val);
		}
	}
	return 0;
}
