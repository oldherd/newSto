#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct circ {
	double x, y, r;
	circ(){}
	circ(int X, int Y, int R) : x(X), y(Y), r(R) {}
};

struct seg {
	double l, r;
	seg() {}
	seg(double L, double R) : l(L), r(R) {}
}sgs[1010];

circ circs[1010], tmp[1010];
int isen[1010], ed = 0;

double f(double x) {
	vector<seg> v;
	for(int i = 0; i < ed; ++i) {
		circ& cur = circs[i]; 
		if(cur.x - cur.r < x && cur.x + cur.r > x) {
			double dl = sqrt(cur.r * cur.r - (cur.x-x) * (cur.x-x));
			v.push_back(seg(cur.y - dl, cur.y + dl));
		}
	} 
	if(v.empty()) return 0;
	sort(v.begin(), v.end(), [&](seg a, seg b){ return a.l < b.l; });
	double ans = v[0].r - v[0].l, nr = v[0].r;
	int vs = v.size(); 
	for(int i = 1; i < vs; ++i)
		if(v[i].r > nr) ans += v[i].r - max(nr, v[i].l), nr = v[i].r;
	return ans;
}

inline double simpson(double l, double r, double fl, double fmid, double fr) {
	return (r - l) * (fl + fr + 4 * fmid) / 6;
}

double asr(double l, double r, double fl, double fmid, double fr, double la, int d) {
	double mid = 0.5 * (l + r);
	double flmid = f(0.5*(l+mid)), frmid = f(0.5*(mid+r));
	double ls = simpson(l, mid, fl, flmid, fmid), rs = simpson(mid, r, fmid, frmid, fr);
	if(abs(ls + rs - la) <= 1e-8 && d > 10) return la;
	return asr(l, mid, fl, flmid, fmid, ls, d+1) + asr(mid, r, fmid, frmid, fr, rs, d+1);
}

inline double dis2(double x1, double y1, double x2, double y2) {
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(3);
	int n;
	double tx, ty, tr;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> tx >> ty >> tr;
		tmp[i] = circ(tx, ty, tr);
	}
	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j) 
			if(dis2(tmp[i].x, tmp[i].y, tmp[j].x, tmp[j].y) <= (tmp[i].r-tmp[j].r)*(tmp[i].r-tmp[j].r)) {
				if(tmp[i].r < tmp[j].r) isen[i] = 1;
				else isen[j] = 1;
				break;
			}
	for(int i = 0; i < n; ++i)
		if(!isen[i])
			circs[ed] = tmp[i], sgs[ed++] = seg(tmp[i].x-tmp[i].r, tmp[i].x+tmp[i].r);
	sort(sgs, sgs+ed, [&](seg x, seg y){ return x.l < y.l; });
	double l = sgs[0].l, r = sgs[0].r, ans;
	for(int i = 1; i < ed; ++i) {
		if(sgs[i].l > r) {
			double fl = f(l), fr = f(r), fmid = f(0.5*(l+r));
			ans	+= asr(l, r, fl, fmid, fr, simpson(l, r, fl, fmid, fr), 0);
			l = sgs[i].l, r = sgs[i].r;
		} else r = max(sgs[i].r, r);
	}
	double fl = f(l), fr = f(r), fmid = f(0.5*(l+r));
	ans	+= asr(l, r, fl, fmid, fr, simpson(l, r, fl, fmid, fr), 0);
	cout << ans << '\n';
	return 0;
}
