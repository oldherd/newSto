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
};

vector<circ> circs, tmp;
vector<bool> isen;

double f(double x) {
	vector<seg> v;
	for(circ cur : circs)
		if(cur.x - cur.r < x && cur.x + cur.r > x) {
			double dl = sqrt(cur.r * cur.r - (cur.x-x) * (cur.x-x));
			v.push_back(seg(cur.y - dl, cur.y + dl));
		}
	if(v.empty()) return 0;
	sort(v.begin(), v.end(), [&](seg a, seg b){ return a.l < b.l; });
	double ans = v[0].r - v[0].l, nr = v[0].r;
	for(int i = 1; i < v.size(); ++i)
		if(v[i].r > nr) ans += v[i].r - max(nr, v[i].l), nr = v[i].r;
	return ans;
}

inline double simpson(double l, double r, double fl, double fmid, double fr) {
	return (r - l) * (fl + fr + 4 * fmid) / 6;
}

double asr(double l, double r, double eps, double fl, double fmid, double fr, double la) {
	double mid = 0.5 * (l + r);
	double flmid = f(0.5*(l+mid)), frmid = f(0.5*(mid+r));
	double ls = simpson(l, mid, fl, flmid, fmid), rs = simpson(mid, r, fmid, frmid, fr);
	if(abs(ls + rs - la) <= 15 * eps) return ls + rs + (ls + rs - la) / 15;
	return asr(l, mid, 0.5*eps, fl, flmid, fmid, ls) + asr(mid, r, 0.5*eps, fmid, frmid, fr, rs);
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
	double l = 1234, r = -1234;
	double tx, ty, tr;
	cin >> n;
	isen.assign(n, true);
	tmp.resize(n);
	circs.resize(n);
	for(int i = 0; i < n; ++i) {
		cin >> tx >> ty >> tr;
		tmp[i] = circ(tx, ty, tr);
		l = min(l, tx - tr);
		r = max(r, tx + tr);
	}
	for(int i = 0; i < n; ++i)
		for(int j = i + 1; j < n; ++j) 
			if(dis2(tmp[i].x, tmp[i].y, tmp[j].x, tmp[j].y) <= (tmp[i].r-tmp[j].r)*(tmp[i].r-tmp[j].r)) {
				if(tmp[i].r < tmp[j].r) isen[i] = false;
				else isen[j] = false;
				break;
			}
	for(int i = 0; i < n; ++i) if(isen[i]) circs.push_back(tmp[i]);
//	sort(circs.begin(), circs.end(), [&](circ a, circ b){ return a.x - a.r < b.x - b.r; });
	double fl = f(l), fmid = f(0.5*(l+r)), fr = f(r);
	cout << asr(l, r, 1e-5, fl, fmid, fr, simpson(l, r, fl, fmid, fr)) << '\n';
	return 0;
}
