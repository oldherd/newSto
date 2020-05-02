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

//typedef __int128 lll;
typedef long long ll;
typedef pair<int,int> pii;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 234567;

inline ll qp(ll a, ll b, ll p) { ll res = 1%p; for(;b;b>>=1) { if(b&1)res=res*a%p; a=a*a%p; } return res; }
inline ll gcd(ll a, ll b) { while(b) { int t = b; b = a%b; a=t; } return a; }
mt19937 mrand(random_device{}()); int rnd(int x) { return mrand() % x;}

//vector< VI > edge;

int pos[maxn],upos[maxn],a[maxn],b[maxn],t1=0,t2=0;

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
	int n;
	cin>>n;
	rep(i,1,n) cin>>a[i];
	rep(i,1,n) cin>>b[i];
	rep(i,1,n) {
		if(a[i]-b[i]>0) pos[t1++]=a[i]-b[i];
		else upos[t2++]=b[i]-a[i];
	}
//	sort(pos,pos+t1,[&](int a, int b){return a<b;});
	sort(upos,upos+t2,[&](int a, int b){return a<b;});
	ll ans=0;
	repp(i,0,t1)
		ans += lower_bound(upos,upos+t2,pos[i])-upos+i;
	cout<<ans<<endl;
	return 0;
}



