#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

typedef long long ll;
typedef __int128 lll;

const int maxn = 23456, inf = 0x3f3f3f3f;

namespace unj {
	vector<int> fa;
	void init(int n) {
		fa.resize(n + 1);
		for(int i = 1; i <= n; ++i) fa[i] = i;
	}
	inline int find(int x) { return x==fa[x]?x:(fa[x]=find(fa[x])); }
	inline void join(int x, int y) { fa[find(x)] = find(y); }
};

namespace mst {
	struct edge {
		int u, v, w;
	};
	vector<edge> edges;
	vector<bool> chs;
	int n, m;
	ll totwei;
	void init(int nn, int mm) {
		n = nn, m = mm; totwei = 0;
		edges.resize(m);
		chs.assign(n + 1, false);
		unj::init(n);
	}
	void kruskal() {
		int cnt = 0;
		sort(edges.begin(), edges.end(), [&](edge &a, edge &b) { return a.w < b.w; });
		for(int i = 0; i < m && cnt < n-1; ++i) {
			if(unj::find(edges[i].u) != unj::find(edges[i].v)) {
				chs[i] = true;
				unj::join(edges[i].u, edges[i].v);
				totwei += edges[i].w;
			}
		}
	}
};

namespace lca {
	struct node {
		int tar, wei;
		node() {}
		node(int TAR, int WEI) : tar(TAR), wei(WEI) {}	
	};
	vector< vector<node> > edge;
	vector<int> dep;
	int mine[maxn][31], fa[maxn][31];
	int n;
	inline void init(int nn) {
		n = nn;
		edge.resize(n + 1);
		dep.resize(n + 1);
		memset(mine, inf, sizeof(mine));
		memset(fa, 0, sizeof(fa));
	}
	inline void addedge(int u, int v, int w) {
		edge[u].push_back(node(v, w));
		edge[v].push_back(node(v, w));
	}
	void dfs(int pre, int cur, int dis) {
		fa[cur][0] = pre; dep[cur] = dep[pre] + 1; mine[cur][0] = dis;
		for(int i = 1; i <= 30; ++i) fa[cur][i] = fa[fa[cur][i-1]][i-1], mine[cur][i] = min(mine[cur][i-1], mine[fa[cur][i-1]][i-1]);
		for(node e : edge[cur])
			if(e.tar != pre)
				dfs(cur, e.tar, e.wei);
	}
	pair<int,int> get_lca(int u, int v) {
		if(dep[u] < dep[v]) swap(u, v);
		int minedge = inf;
		for(int i = 30; ~i; --i) if(dep[fa[u][i]] <= dep[v]) minedge = min(minedge, mine[u][i]), u = fa[u][i];
		if(u == v) return make_pair(u, minedge);
		for(int i = 30; ~i; --i)
			if(fa[u][i] != fa[v][i]) minedge = min(minedge, mine[u][i]), minedge = min(minedge, mine[v][i]), u = fa[u][i], v = fa[v][i];
		return make_pair(fa[u][0], minedge);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	mst::edges.resize(m);
	for(int i = 0; i < m; ++i) cin >> mst::edges[i].u >> mst::edges[i].v >> mst::edges[i].w;
	mst::init(n, m);
	mst::kruskal();
	lca::init(n);
	for(int i = 0; i < m; ++i) if(mst::chs[i]) lca::addedge(mst::edges[i].u, mst::edges[i].v, mst::edges[i].w);
	lca::dfs(1, 1, 0);
	ll sum = mst::totwei;
	lll sumtot = 0;
	for(int i = 0; i < m; ++i) {
		ll t = sum;
		if(mst::chs[i]) t -= mst::edges[i].w;
		else t -= lca::get_lca(mst::edges[i].u, mst::edges[i].v).second;
		sumtot += t;
	}
	ll ans = sumtot / m;
	cout << ans << endl;
	return 0;
}
