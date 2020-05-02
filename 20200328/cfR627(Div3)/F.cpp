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
//////pr
//#define debug(...) fprintf(stderr, __VA_ARGS__)
//#define Debug("[%s] in line %d\n",__FUNCTION__,__LINE__)

using namespace std;

//typedef __int128_t lll;
typedef long long ll;
typedef pair<int,int> pii;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline void ponchline() { cout << "##################################" << endl; }
inline ll qp(ll a, ll b, ll p) { ll res = 1%p; for(;b;b>>=1) { if(b&1)res=res*a%p; a=a*a%p; } return res; }
inline ll gcd(ll a, ll b) { while(b) { int t = b; b = a%b; a=t; } return a; }
mt19937 mrand(random_device{}()); int rnd(int x) { return mrand() % x;}

vector< VI > edge;
vector<int> fa, col, dp1, dp2;

void dfs1(int pre, int cur) {
	fa[cur] = pre;
	dp1[cur]=col[cur];
	for(int ver : edge[cur]) {
		if(ver == pre) continue;
		dfs1(cur, ver);
		dp1[cur] += dp1[ver]<0?0:dp1[ver];
	}
}

void dfs2(int pre, int cur) {
	dp2[cur] = max(dp2[pre]+dp1[pre]-(dp1[cur]>0?dp1[cur]:0), 0);
	for(int ver : edge[cur]) {
		if(ver==pre) continue;
		dfs2(cur, ver);
	}
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
	int n,u,v;
	cin >> n;
	edge.rz(n+1);
	fa.rz(n+1);
	col.rz(n+1);
	dp1.rz(n+1);
	dp2.rz(n+1);
	rep(i,1,n) {
		cin>>col[i];
		if(!col[i]) col[i]=-1;
	}
	rep(i,1,n-1) {
		cin>>u>>v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	dfs1(1,1);
	dfs2(0,1);
//	ponchline();
//	rep(i,1,n) cout << dp1[i] << ' ' << dp2[i] << endl;
	rep(i,1,n) cout << dp1[i] + max(dp2[i], 0) << ' ';
	cout << endl;
	return 0;
}


