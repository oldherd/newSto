#include <cstdio>

using namespace std;

typedef long long ll;
const int maxn = 2345, mod = 998244353;
int x[maxn], y[maxn];

ll inv(ll x, ll mod) {
    ll m = mod - 2, ans = 1 % mod;
    for(; m; m >>= 1) {
        if(m % 2) {
            ans = ans * x % mod;
        }
        x = x * x % mod;
    }
    return ans;
}

ll lagrange(int n, int x0) {
    ll ans = 0, tmp, md;
    for(int i = 1; i <= n; ++i) {
        tmp = y[i] % mod;
        md = 1;
        for(int j = 1; j <= n; ++j) 
            if(j != i) {
                tmp = tmp * (x0 - x[j]) % mod;
            	md = md * (x[i] - x[j]) % mod;
            }
        ans = (ans + tmp * inv(md, mod) % mod) % mod;
    }
    return (ans % mod + mod) % mod;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%d %d", x + i, y + i);
    }
    printf("%lld\n", lagrange(n, k));
    return 0;
}
