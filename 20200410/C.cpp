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
//////pr
//#define debug(...) fprintf(stderr, __VA_ARGS__)
//#define Debug("[%s] in line %d\n",__FUNCTION__,__LINE__)

using namespace std;

//typedef __int128_t lll;
typedef long long ll;
typedef pair<int,int> pii;

inline void ponchline() { cout << "##################################" << endl; }
inline ll qp(ll a, ll b, ll p) { ll res = 1%p; for(;b;b>>=1) { if(b&1)res=res*a%p; a=a*a%p; } return res; }
inline ll gcd(ll a, ll b) { while(b) { int t = b; b = a%b; a=t; } return a; }
mt19937 mrand(random_device{}()); int rnd(int x) { return mrand() % x;}

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

//vector< VI > edge;

VL a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
//	cout.setf(ios::fixed);
//	cout.precision(6);

	int tests;
	cin>>tests;
	while(tests--) {
		int n;
		ll ans = 0, reg = linf;
		cin >> n;
		a.resize(n + 2);
		b.resize(n + 2);
		rep(i,1,n) cin >> a[i] >> b[i], ans += a[i];
		rep(i,1,n) {
			ans -= min(b[i], a[i%n+1]);
			reg = min(reg, min(b[i], a[i%n+1]));
		}
		ans += reg;
		cout << ans << endl;
	}

	return 0;
}


