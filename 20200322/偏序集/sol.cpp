#include <bits/stdc++.h>
//#define endl '\n'

using namespace std;

typedef long long ll;

const int maxn = 123456;

struct node {
	int x, y, z;
	node() {}
	node(int X, int Y, int Z): x(X), y(Y), z(Z) {}
	bool operator == (const node &o) const {
		return x==o.x && y==o.y && z==o.z;
	}
}a[maxn];

int dat[maxn << 2], b[maxn<<1], dp[maxn][2], ed = 0;

void update(int p, int l, int r, int x, int v) {
	if(l == r) {
		dat[p] = max(dat[p], v);
		return;
	}
	int mid = (l + r) >> 1;
	if(x <= mid) update(p<<1, l, mid, x, v);
	else update(p<<1|1, mid + 1, r, x, v);
	dat[p] = max(dat[p<<1], dat[p<<1|1]);
}

int query(int p, int lp, int rp, int l, int r) {
	if(lp <= l && r <= r) return dat[p];
	int mid = (lp + rp) >> 1;
	int ans = 0;
	if(l <= mid) ans = query(p<<1, lp, mid, l, r);
	if(r > mid) ans = max(ans, query(p<<1|1, mid+1, rp, l, r));
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
//	cout.setf(ios::fixed);
//	cout.precision(6);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].x >> a[i].y >> a[i].z,
		b[ed++] = a[i].x;
		b[ed++] = a[i].y;
	}
	sort(b, b+ed, [&](int &a, int &b){ return a < b; });
	ed = unique(b, b+ed) - b;
	for(int i = 1; i <= n; ++i) {
		a[i].x = lower_bound(b, b+ed, a[i].x) - b;
		a[i].y = lower_bound(b, b+ed, a[i].y) - b;
		--a[i].z;
	}
	sort(a+1, a+n+1, [&](node &a, node &b){ return a.x < b.x || a.x == b.x && a.y < b.y || a.x == b.x && a.y == b.y && a.z < b.z; });
	dp[i][0] = a[i].z==0?1:0;
	update(1, 0, ed-1, a[i].y, dp[i][0]);
	int pon = dp[i][0];
	for(int i = 1; i <= n; ++i) {
		if(a[i].z) {
			dp[i][0] = dp[i-1][0];
			continue;
		}
		int suf = query(1, 0, ed-1, 0, a[i].y) + 1;
		update(1, 0, ed-1, a[i].y, suf);
		
	}
	memset(dat, 0, sizeof(dat));
	dp[n][1] = a[i].z==1?1:0;
	update(1, 0, ed-1, a[i].y, dp[i][0]);
	for(int i = n; i; --i) {
		if(!a[i].z) continue;
	}
	return 0;
}
