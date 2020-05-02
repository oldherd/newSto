#include <bits/stdc++.h>
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

ll tag[maxn<<2];
int a[maxn];
double s[maxn<<2], c[maxn<<2];

inline void update(int p) {
	s[p] = s[p<<1] + s[p<<1|1];
	c[p] = c[p<<1] + c[p<<1|1];	
}

void maintain(int p) {
	ll v = tag[p]; tag[p] = 0;
	double sn, cn, sv = sin(v), cv = cos(v);
	sn = s[p<<1] * cv + c[p<<1] * sv;
	cn = c[p<<1] * cv - s[p<<1] * sv;
	s[p<<1] = sn, c[p<<1] = cn;
	sn = s[p<<1|1] * cv + c[p<<1|1] * sv;
	cn = c[p<<1|1] * cv - s[p<<1|1] * sv;
	s[p<<1|1] = sn, c[p<<1|1] = cn;
	tag[p<<1] += v; tag[p<<1|1] += v;
}

void build(int p, int lp, int rp) {
	if(lp == rp) {
		s[p] = sin(a[lp]);
		c[p] = cos(a[lp]);
		return;
	}
	int mid = (lp + rp) >> 1;
	build(p<<1, lp, mid);
	build(p<<1|1, mid + 1, rp);
	update(p);
}

void change(int p, int lp, int rp, int l, int r, int v) {
	if(l <= lp && rp <= r) {
		double sn = s[p] * cos(v) + c[p] * sin(v);
		double cn = c[p] * cos(v) - s[p] * sin(v);
		s[p] = sn, c[p] = cn;
		tag[p] += v;
		return;
	}
	int mid = (lp + rp) >> 1;
	if(tag[p]) maintain(p);
	if(l <= mid) change(p<<1, lp, mid, l, r, v);
	if(r > mid) change(p<<1|1, mid + 1, rp, l, r, v);
	update(p);
}

double qry(int p, int lp, int rp, int l, int r) {
	if(l <= lp && rp <= r) return s[p];
	int mid = (lp + rp) >> 1;
	if(tag[p]) maintain(p);
	double ans = 0;
	if(l <= mid) ans = qry(p<<1, lp, mid, l, r);
	if(r > mid) ans += qry(p<<1|1, mid + 1, rp, l, r);
	return ans;
}

int main() {
	int n, m, op, l, r, v;
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", a+i);
	build(1, 1, n);
	scanf("%d", &m);
	while(m--) {
		scanf("%d %d %d", &op, &l, &r);	
		if(op == 1) {
			scanf("%d", &v);
			change(1, 1, n, l, r, v);
		} else {
			printf("%.1f\n", qry(1, 1, n, l, r));
		}
	}
	return 0;
}
