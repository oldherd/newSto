#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double a, b, a2;

double f(double x) {
	return 2 * b * sqrt(1 - (x*x) / a2);	
}

inline double simpson(double l, double r) {
	return (r - l) * (f(l) + f(r) + 4 * f(0.5 * (l + r))) / 6;
}

double asr(double l, double r, double eps, double la) {
	double mid = 0.5 * (l + r);
	double ls = simpson(l, mid), rs = simpson(mid, r);
	if(abs(ls + rs - la) <= 15 * eps) return ls + rs + (ls + rs - la) / 15;
	return asr(l, mid, 0.5 * eps, ls) + asr(mid, r, 0.5 * eps, rs);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(3);
	double l, r;
	int n;
	cin >> n;
	while(n--) {
		cin >> a >> b >> l >> r;
		a2 = a * a;
		cout << asr(l, r, 1e-5, simpson(l, r)) << '\n';
	}
	return 0;
}

