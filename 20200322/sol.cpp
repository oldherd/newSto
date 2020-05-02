#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;

const int maxn = 1234567, inf = 0x3f3f3f3f;

int a[maxn], b[maxn];
int dp[maxn][2][2];
char ans[maxn];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, cnt0 = 0, cnt1 = 0, lst = INT_MAX;
	cin >> n;
	n <<= 1;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i];
	dp[0][0][0] = dp[0][0][1] = 1;
	dp[0][1][0] = dp[0][1][1] = 0;
	for(int i = 1; i < n; ++i) {
		dp[i][0][0] = dp[i][1][0] = inf;
		dp[i][0][1] = dp[i][1][1] = 0;
		if(a[i] >= a[i-1]) dp[i][0][0] = dp[i-1][0][0] + 1, dp[i][0][1] = dp[i-1][0][1] + 1;
		if(b[i] >= a[i-1]) dp[i][1][0] = min(dp[i][1][0], dp[i-1][0][0]), dp[i][1][1] = max(dp[i][1][1], dp[i-1][0][1]);
		if(a[i] >= b[i-1]) dp[i][0][0] = min(dp[i][0][0], dp[i-1][1][0] + 1), dp[i][0][1] = max(dp[i][0][1], dp[i-1][1][1] + 1);
		if(b[i] >= b[i-1]) dp[i][1][0] = min(dp[i][1][0], dp[i-1][1][0]), dp[i][1][1] = max(dp[i][1][1], dp[i-1][1][1]);
//		cout << dp[i][0][0] << ' ' << dp[i][0][1] << endl;
//		cout << dp[i][1][0] << ' ' << dp[i][1][1] << endl;
//		cout << endl;
	}
	if((dp[n-1][0][1] < dp[n-1][0][0] || dp[n-1][0][1] < (n>>1) || dp[n-1][0][0] > (n>>1)) && (dp[n-1][1][1] < dp[n-1][1][0] || dp[n-1][1][1] < (n>>1) || dp[n-1][1][0] > (n>>1))) {
		cout << "-1\n";
		return 0;
	}
	for(int i = n-1; ~i; --i) {
		if(dp[i][0][0] <= dp[i][0][1] && cnt0 + dp[i][0][1] >= (n>>1) && cnt1 + (i+1-dp[i][0][0]) >= (n>>1) && a[i] <= lst) {
			ans[i] = 'A'; lst = a[i]; ++cnt0;
		} else {
			ans[i] = 'B'; lst = b[i]; ++cnt1;
		}
	}
	cout << ans << endl;
	return 0;
}

