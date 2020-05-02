#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int inf = 0x3f3f3f3f, maxt = 50000, maxn = 123456;
const ll linf = 0x3f3f3f3f3f3f3f3f;
	
int dat[maxt<<2];
double k[maxn], b[maxn];
int top = 1;

inline double calc(int id, int x) {
	return k[id] * (x-1) + b[id];
}

void insert(int p, int lp, int rp, int x) {
	if(lp == rp) {
		if(calc(dat[p], lp) < calc(x, lp)) dat[p] = x;
		return;
	}
	int mid = lp + rp >> 1;
	double pre = calc(dat[p], mid), cur = calc(x, mid);
	if(k[x] < k[dat[p]]) {
		if(cur > pre) insert(p<<1|1, mid+1, rp, dat[p]), dat[p] = x;
		else insert(p<<1, lp, mid, x);
	} else if(k[x] > k[dat[p]]) {
		if(cur > pre) insert(p<<1, lp, mid, dat[p]), dat[p] = x;
		else insert(p<<1|1, mid+1, rp, x);
	} else {
		if(cur > pre) dat[p] = x;	
	}
}

double qry(int p, int lp, int rp, int x) {
	if(lp == rp) return calc(dat[p], x);
	int mid = lp + rp >> 1;
	if(x <= mid) return max(calc(dat[p], x), qry(p<<1, lp, mid, x));
	return max(calc(dat[p], x), qry(p<<1|1, mid+1, rp, x));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, tt;
	double tk, tb;
	cin >> n;
	string str;
	k[0] = b[0] = 0;
	while(n--) {
		cin >> str;
		if(str[0] == 'Q') {
			cin >> tt;
			if(top==1) cout << 0 << endl;
			else cout << (int)qry(1, 1, maxt, tt) / 100 << endl;
		} else {
			cin >> tb >> tk;
			k[top] = tk; b[top] = tb;
			insert(1, 1, maxt, top++);
		}
	}
	return 0;
}


