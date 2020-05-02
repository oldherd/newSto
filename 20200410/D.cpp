#include <bits/stdc++.h>
//#define endl '\n'
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

const int inf = 0x3f3f3f3f, maxn = 123456;
const ll linf = 0x3f3f3f3f3f3f3f3f;

//vector< VI > edge;
ll a[maxn], b[maxn];

ll bound(ll l, ll r, ll key) {
	while(l < r) {
		int mid = (l + r + 1) >> 1;
		if(a[mid] <= key) l = mid;
		else r = mid - 1;	
	}
	return l;
}

ll tobound(ll l, ll r, ll key) {
	while(l < r) {
		int mid = (l + r) >> 1;
		if(a[mid] >= key) r = mid;
		else l = mid + 1;	
	}
	return l;
}

ll gen(ll n, ll idx) {
	if(idx == n*(n-1) + 1) return 1;
	if(idx % 2 == 1) {
		idx = idx / 2 + 1;
		return tobound(1, n - 1, idx);
	} else {
		idx /= 2;
		int blk = tobound(0, n - 1, idx);
		idx -= a[blk-1];
		return n - (a[blk] - a[blk-1]) + idx;
	}
}
int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.setf(ios::fixed);
//	cout.precision(6);
	int tests;
	cin>>tests;
	while(tests--) {
		ll n, l, r;
		cin >> n >> l >> r;
		rep(i,1,n) a[i] = n - i, a[i] += a[i-1];
//		rep(i,1,n-1) cout << a[i] << ' '; cout << endl; 
		for(ll i = l; i <= r; ++i) {
			cout << gen(n, i) << ' ';
		}
		cout << endl;
	}
	return 0;
}


