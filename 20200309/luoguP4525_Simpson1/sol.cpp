#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double a, b, c, d;
inline double f(double x) {
	return (c * x + d) / (a * x + b);	
}

inline double simpson(double l, double r) {
	return (f(l) + 4 * f(0.5*(l+r)) + f(r)) * (r - l) / 6;
}

double asr(double l, double r, double eps, double la) {
	double mid = 0.5 * (l + r);
	double ls = simpson(l, mid), rs = simpson(mid, r);
	if(abs(ls + rs - la) <= 15 * eps) return ls + rs + (ls + rs - la) / 15;
	return asr(l, mid, eps * 0.5, ls) + asr(mid, r, eps * 0.5, rs);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	double l, r;
	cin >> a >> b >> c >> d >> l >> r;
	cout.setf(ios::fixed);
	cout.precision(6);
	cout << asr(l, r, 1e-6, simpson(l, r)) << '\n';
	return 0;
}
