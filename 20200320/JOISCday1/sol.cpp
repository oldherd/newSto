#include <bits/stdc++.h>
//#define endl '\n'

using namespace std;

typedef long long ll;

vector< vector<int> > dp;
vector<int> a, b;

const int inf = 2147483647;

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	cin >> n;
	const int n2 = n;
	n <<= 1;
	a.resize(n);
	b.resize(n);
	dp.resize(n);
	for(int i = 0; i < n; ++i) {
		dp[i].assign(min(i+1, n2), inf);
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i) cin >> b[i];
	dp[0][1] = a[0]; dp[0][0] = b[0];
	for(int i = 1; i < n; ++i)
		for(int j = 0; j <= min(i+1, n2); ++j) {
			if(j && dp[i-1][j-1] <= a[i]) dp[i][j] = a[i];
			if(dp[i-1][j] <= b[i]) dp[i][j] = min(dp[i][j], b[i]);
		}
	cout << dp[n][n2] << endl;
	return 0;
}


