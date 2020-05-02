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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
//	cout.setf(ios::fixed);
//	cout.precision(6);
	int tests;
	cin>>tests;
	while(tests--) {
		int n, p, c, pi, ci;
		bool flg = true;
		cin>>n;
		--n;
		cin >> p >> c;
		if(p < c) flg = false;
		while(n--) {
			cin >> pi >> ci;
			if(pi < p || ci < c || pi - p < ci - c || pi < ci) flg = false;
			p = pi; c = ci;
		}
		if(flg) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
