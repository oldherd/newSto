#include <bits/stdc++.h>
#define itra map<int,bool>::iterator
//#define endl '\n'

using namespace std;

typedef long long ll;

vector< map<int, bool> > vin, inq;
queue< int > q1, q2;

int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n, m, u, v, cnt = 0;
	cin >> n >> m;
	vin.resize(n + 1);
	inq.resize(n + 1);
	while(m--) {
		cin >> u >> v;
		if(u == 4 && v == 3) {
			int t = u;
			t = u;	
		}
		itra it = vin[v].find(u);
		if(it != vin[v].end()) {
			cout << cnt << endl;
			continue;
		}
		++cnt;
		vin[v][u] = true;
		if(vin[u].find(v) != vin[u].end()) {
			q1.push(u);
			q2.push(v);
			inq[u][v] = inq[v][u] = true;
			while(!q1.empty()) {
				u = q1.front(); q1.pop();
				v = q2.front(); q2.pop();
				inq[u].erase(inq[u].find(v));
				inq[v].erase(inq[v].find(u));
				int cr;
				for(itra it = vin[u].begin(); it != vin[u].end(); it++) {
					cr = it -> first;
					if(cr == v) continue;
					if(vin[v].find(cr) == vin[v].end()) {
						vin[v][cr] = true;
						++cnt;
						if(vin[cr].find(v) != vin[cr].end() && !inq[cr][v]) {
							inq[cr][v] = inq[v][cr] = true;
							q1.push(v);
							q2.push(u);
						}
					}
				}
				for(itra it = vin[v].begin(); it != vin[v].end(); ++it) {
					cr = it->first;
					if(cr == u) continue;
					if(vin[u].find(cr) == vin[u].end()) {
						vin[u][cr] = true;
						++cnt;
						if(vin[cr].find(u) != vin[cr].end() && !inq[cr][u]) {
							inq[cr][u] = inq[u][cr] = true;
							q1.push(cr);
							q2.push(u);	
						}
					}
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}


