#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double a;
inline double f(double x) {
	return pow(x, a / x - x); 
}

inline double simpson(double l, double r) {
	return (f(l) + 4 * f(0.5*(l+r)) + f(r)) * (r - l) / 6;
}

double asr(double l, double r, double eps, double la) {
	double mid = 0.5 * (l + r);
	double ls = simpson(l, mid), rs = simpson(mid, r);
	if(abs(ls + rs - la) <= 15 * eps) return ls + rs;
	return asr(l, mid, eps * 0.5, ls) + asr(mid, r, eps * 0.5, rs);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a;
	if(a < 0) cout << "orz\n";
	else {
		cout.setf(ios::fixed);
		cout.precision(5);
		cout << asr(1e-8, 20, 1e-8, simpson(1e-8, 30)) << '\n';
	}
	return 0;
}
