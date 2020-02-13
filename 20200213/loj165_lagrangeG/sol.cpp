#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
const int maxn = 3456, p = 998244353;
vector<ll> g, x, y;

ll inv(ll x, ll p) {
    ll ans = 1 % p;
    for(ll b = p - 2; b; b >>= 1) {
        if(b % 2) ans = ans * x % p;
        x = x * x % p;
    }
    return ans;
}

void addpoint(int tx, int ty) {
    int n = g.size();
    ll gn = 1;
    for(int i = 0; i < n; ++i) {
        gn = gn * (tx - x[i]) % p;
        g[i] = g[i] * (x[i] - tx) % p;
    }
    g.push_back(gn);
    x.push_back(tx);
    y.push_back(ty);
}

ll qry(ll tx) {
    ll tn = 1, sn = 0, ts = 0;
    int n = g.size();
    for(int i = 0; i < n; ++i) {
        tn = tn * (tx - x[i]) % p;
        ts = y[i] * inv(tx - x[i], p) % p;
        ts = ts * inv(g[i], p) % p;
        sn = (sn + ts) % p;
    }
    return (tn * sn % p + p) % p;
}

int main() {
    int n, op, tx, ty;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d %d", &tx, &ty);
            addpoint(tx, ty);
        } else {
            scanf("%d", &tx);
            printf("%lld\n", qry(tx));
        }
    }
    return 0;
}
