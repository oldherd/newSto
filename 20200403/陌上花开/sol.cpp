#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define per(i,a,b) for(int i=a;i>=(b);--i)
#define repp(i,a,b) for(int i=a;i<(b);++i)
#define perr(i,a,b) for(int i=a;i>(b);--i)
#define pb push_back
#define rz resize
#define itra(T) vector<T>::iterator
#define VI vector<int>
#define VL vector<long long>
#define VD vector<double>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 234567;

int n, k;

struct point {
	int a, b, c, id, ans;
} p[maxn];

int pss[maxn], top = 0;
int ls[maxn<<7], rs[maxn<<7], dat[maxn<<7], tot;
int c[maxn], ans[maxn];

inline void update(int p) {
	dat[p] = dat[ls[p]] + dat[rs[p]];	
}

void insert(int &p, int lp, int rp, int v) {
	if(!p) p = ++tot;
	if(lp == rp) {
		++dat[p];
		return;
	}
	int mid = (lp + rp) >> 1;
	if(v <= mid) insert(ls[p], lp, mid, v);
	else insert(rs[p], mid+1, rp, v);
	update(p);
}

int query(int lp, int rp, int w) {
	if(lp == rp) {
		int res = 0;
		repp(i, 0, top) res += dat[pss[i]];
		return res;
	}
	int mid = lp + rp >> 1;
	if(w <= mid) {
		rep(i, 0, top) pss[i] = ls[pss[i]];
		return query(lp, mid, w);
	} else {
		int res = 0;
		rep(i, 0, top) res += dat[ls[pss[i]]], pss[i] = rs[pss[i]];
		return res + query(mid+1, rp, w);
	}
}

void add(int x, int v) {
	for(; x<=k; x += x&-x) insert(c[x], 1, k, v);
}
int qryit(int tx, int ty) {
	top = 0;
	for(; tx; tx -= tx&-tx) pss[top++] = c[tx];
	return query(1, k, ty);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	rep(i, 1, n) cin >> p[i].a >> p[i].b >> p[i].c, p[i].id = i, c[i] = ++tot;
	sort(p + 1, p + n + 1, [&](point &o1, point &o2){ return o1.a < o2.a || o1.a == o2.a && o1.b < o2.b || o1.a == o2.a && o1.b==o2.b && o1.c < o2.c; } );
	for(int i = 1; i <= n; ) {
		add(p[i].b, p[i].c); int j = i + 1;
		while(j <= n && p[j].a == p[j-1].a) add(p[j].b, p[j].c), ++j;
		repp(k, i, j)
			++ans[qryit(p[k].b, p[k].c)-1];
		i = j;
	}
	repp(i, 0, n) cout << ans[i] << endl;
	return 0;
}
