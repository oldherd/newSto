#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct star {
	int x, w;
	star() {}
	star(int X, int W) : x(X), w(W) {}
	bool operator < (const star& o) const { return x < o.x; }
};

int main() {
	int n, w, tx, ty;
	scanf("%d %d", &n, &w);
	vector<star> vn(n);
	vector<ll> sum(n, 0);
	for(int i = 0; i < n; ++i) {
		scanf("%d %d", &tx, &ty);
		vn[i] = star(tx, ty);
	}
	if(w == 0) {
		printf("0\n");
		return 0;	
	}
	sort(vn.begin(), vn.end());
	int l = 0;
	ll ans = sum[0] = vn[0].w;
	for(int i = 1; i < n; ++i) {
		sum[i] = sum[i - 1] + vn[i].w;
		while(vn[i].x - vn[l].x + 1 > w && l <= i) ++l;
		ans = max(ans, sum[i] - sum[l] + vn[l].w);
	}
	printf("%lld\n", ans);
	return 0;
}
