#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,a,b) for(int i=a;i<=(b);++i)
#define per(i,a,b) for(int i=a;i>=(b);--i)
#define repp(i,a,b) for(int i=a;i<(b);++i)
#define perr(i,a,b) for(int i=a;i>(b);--i)
#define pb push_back
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

inline ll qp(ll a, ll b, ll p) { ll res = 1%p; for(;b;b>>=1) { if(b&1)res=res*a%p; a=a*a%p; } return res; }
inline ll gcd(ll a, ll b) { while(b) { int t = b; b = a%b; a=t; } return a; }
mt19937 mrand(random_device{}()); int rnd(int x) { return mrand() % x;}

//vector< VI > edge;

const int maxn = 2345;
int dp[maxn][maxn];
inline int check(int v, int i, int j) { return v>=i&&v<=j; }

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
	int n, h, l, r, a;
	cin >> n >> h >> l >> r;
	memset(dp,-inf,sizeof(dp));
	dp[0][0] = 0;
	rep(i,1,n) {
		cin >> a;
		repp(j,0,h)	dp[i][j] = max(dp[i-1][(j-a+h)%h] + check(j,l,r), dp[i-1][(j-a+1+h)%h] + check(j,l,r));
		
	}
	int ans = 0;
	repp(i,0,h) ans = max(ans, dp[n][i]);
	cout << ans << endl;
	return 0;
}

