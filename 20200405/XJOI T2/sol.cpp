#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define per(i,a,b) for(int i=a;i>=(b);--i)
#define repp(i,a,b) for(int i=a;i<(b);++i)
#define perr(i,a,b) for(int i=a;i>(b);--i)
#define pb push_back
#define rz resize

using namespace std;

typedef long long ll;

const int maxn = 56789, inf = 0x3f3f3f3f;

int head[maxn], vr[maxn<<1], nex[maxn<<1], tot;
inline void addedge(int u, int v) {
	vr[tot] = v; nex[tot] = head[u]; head[u] = tot++;
}

int a[maxn], d1[maxn], d2[maxn], d3[maxn];
ll ans = 0;

inline void update(int &x1, int &x2, int y) {
	if(y > x1) x2 = x1, x1 = y;
	else if(y > x2) x2 = y;
}

void dfs1(int pre, int cur) {
	for(int i = head[cur], ver = vr[i]; ~i; i = nex[i], ver = vr[i])
		if(ver != pre) {
			dfs1(cur, ver);
			update(d1[cur], d2[cur], d1[ver] + 1);
		}
}

void dfs2(int pre, int cur) {
	if(d1[cur] + 1 == d1[pre]) d3[cur] = d2[pre] + 1;
	else d3[cur] = d1[pre] + 1;
	d3[cur] = max(d3[cur], d3[pre] + 1);
	ans = max(ans, (ll)max(d3[cur],d1[cur]) * a[cur]);
	for(int i = head[cur], ver = vr[i]; ~i; i = nex[i], ver = vr[i])
		if(ver != pre)
			dfs2(cur, ver);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
//	cout.setf(ios::fixed);
//	cout.precision(6);

//	int tests;
//	cin>>tests;
//	while(tests--) {
//
//	}
	memset(head, -1, sizeof(head));
	int n, u, v;
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	if(n==0 || n==1) {
		cout << 0 << endl;
		return 0; 
	} else if(n == 2) {
		cout << max(a[1], a[2]) << endl;
		return 0;	
	}
	rep(i, 1, n - 1) {
		cin >> u >> v;
		addedge(u, v);
		addedge(v, u);
	}
	dfs1(1, 1);
	dfs2(0, 1);
//	rep(i, 1, n) cout << d1[i] << ' ' << d2[i] << ' ' << d3[i] << endl;
	cout << ans << endl;
	return 0;
}


