#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,1,n) for(int i = (a); i <= (b); ++i)
#define per(i,1,n) for(int i = (a); i >= (b); --i)
#define repp(i,1,n) for(int i = (a); i < (b); ++i)
#define perr(i,1,n) for(int i = (a); i > (b); --i)
#define pb push_back
#define rz resize
#define itra std::vector<int>::iterator;
#define itra(T) std::vector<T>::iterator;

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef std::vector<int> VI;
typedef std::vector<double> VD;
typedef std::vector<ll> VL;

const int maxn = 12345;

inline void ponchline() { cout << "##################################" << endl; }

int dat[maxt], ls[maxn], rs[maxn], tot;
int a[maxn], c[maxn];
int tre[maxn], top;

void insert(int &p, int lp, int rp, int x, int v) {
	if(!p) p = tot++;
	if(lp == rp) {
		dat[p] += v;
		return ;
	}
	int mid = lp + rp >> 1;
	if(x <= mid) insert(ls[p], lp, mid, x, v);
	else insert(rs[p], mid + 1, rp, x, v);
	update(p);
}
void add(int x, int y) {
	for(; x <= n; ++x) insert(c[x], 1, maxn, y, 1);
}

int qry(int lp, int rp) {

}

int query(int l, int r) {
	top = 0;
	for(; r >= l; r -= r&-r) {
		tre[top++] = c[r];
	}
	return qry(1, n);
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	rep(i,1,n) c[i] = i;
	tot = n + 1;
	rep(i,1,n) cin >> a[i], add(i, a[i]);

	return 0;
}
