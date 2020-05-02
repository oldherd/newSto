#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define per(i,a,b) for(int i=a;i>=(b);--i)
#define repp(i,a,b) for(int i=a;i<(b);++i)
#define perr(i,a,b) for(int i=a;i>(b);--i)

using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f, maxn = 123456, maxh = 1234567;
const ll linf = 0x3f3f3f3f3f3f3f3f;

ll h[maxn], k[maxn], b[maxn], s[maxn], f[maxn];

int dat[maxh << 2];

inline ll calc(int id, int x) {
	return k[id] * x + b[id];
}

void insert(int p, int lp, int rp, int id) {
	if(!dat[p]) { dat[p] = id; return; }
	if(lp == rp) {
		if(calc(dat[p], lp) > calc(id, lp)) dat[p] = lp;
		return;
	}
	int mid = lp + rp >> 1;
	ll pre = calc(dat[p], mid), cur = calc(id, mid);
	if(k[dat[p]] < k[id]) {
		if(cur < pre) insert(p<<1|1, mid+1, rp, dat[p]), dat[p] = id;
		else insert(p<<1, lp, mid, id);
	} else if(k[dat[p]] > k[id]) {
		if(cur < pre) insert(p<<1, lp, mid, dat[p]), dat[p] = id;
		else insert(p<<1|1, mid+1, rp, id);
	} else {
		if(cur < pre) dat[p] = id;
	}
}

ll qry(int p, int lp, int rp, int x) {
	if(lp == rp) return calc(dat[p], x);
	int mid = lp + rp >> 1;
	if(x <= mid) return min(calc(dat[p], x), qry(p<<1, lp, mid, x));
	else return min(calc(dat[p], x), qry(p<<1|1, mid+1, rp, x));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll mh = 0;
	cin >> n;
	rep(i, 1, n) cin >> h[i], mh = max(h[i], mh);
	rep(i, 1, n) cin >> s[i];
	rep(i, 2, n) s[i] += s[i-1];
	k[0] = b[0] = inf;
	f[1] = 0;
	k[1] = -2 * h[1], b[1] = -s[1] + h[1]*h[1];
	insert(1, 0, mh, 1);
	rep(i, 2, n) {
		f[i] = h[i] * h[i] + s[i-1] + qry(1, 0, mh, h[i]);
		k[i] = -2 * h[i], b[i] = f[i] + -s[i] + h[i] * h[i];
		insert(1, 0, mh, i);
	}
	cout << f[n] << endl;
	return 0;
}
