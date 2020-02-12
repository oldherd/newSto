#include <cstdio>

using namespace std;

typedef long long ll;
const int maxn = 2345;
const ll mod = 998244353;
ll x[maxn], y[maxn];

ll inv(ll x) {
    ll m = mod - 2, ans = 1 % mod;
    for(; m; m >>= 1) {
        if(m % 2) {
            ans = ans * x % mod;
        }
        x = x * x % mod;
    }
    return ans;
}

ll lagrange(int n, ll x0) {
    ll ans = 0, tmp;
    for(int i = 1; i <= n; ++i) {
        tmp = y[i] % mod;
        for(int j = 1; j <= n; ++j) 
            if(j != i) {
                tmp = tmp * (x0 - x[j]) % mod;
                tmp = tmp * inv(x[i] - x[j]) % mod;
            }
        ans = (ans + tmp) % mod;
    }
    return ans;
}

int main() {
    ll n, k;
    scanf("%lld %lld", &n, &k);
    for(int i = 1; i <= n; ++i) {
        scanf("%lld %lld", x + i, y + i);
    }
    printf("%lld\n", lagrange(n, k));
    return 0;
}
