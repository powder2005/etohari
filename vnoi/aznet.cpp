#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"

using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
using pld = pair < ld, ld >;
using point = pair < ld, ld > ;
using line = pair < point, point >;
using ordered_set = tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update >;

template < class T > bool minimum(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool maximum(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define el "\n"
#define NAME "ETOHARI"
#define HACKER "ETOHARI"
#define fi first        
#define se second
#define bit(a,b) ((a >> b)&1)
#define countBit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
#define len(s) (int)s.size()
const int MAXN = 1e6 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

struct edge {
	int u, v, id;
	edge(int _u = 0, int _v = 0, int _id = 0) : u(_u), v(_v), id(_id) {};
} e1[MAXN], e2[MAXN];

int n, cnt, m, m1, m2, a[MAXN], b[MAXN], par[MAXN], pos[MAXN];

int root(int u) {
	return (par[u] < 0 ? u : (par[u] = root(par[u])));
}
bool merger(int u, int v){
	u = root(u);
	v = root(v);
	if(u == v)return false;
	if(par[u] < par[v])swap(u, v);
	par[u] += par[v];
	par[v] = u;
	return true;
}

void solve(){

	m1 = 0;
	m2 = 0;
	cnt = 0;

	cin >> n >> m;
	for(int i = 1; i < n; i ++){
		cin >> a[i];
	}

	for(int i = 1; i < n; i ++){
		cin >> b[i];
	}

	for(int i = 1, u, v, c; i <= m; i ++){
		cin >> u >> v >> c;
		if(c == 1)e1[++ m1] = edge(u, v, i);
			else e2[++ m2] = edge(u, v, i);
	}

	fill(par + 1, par + n + 1, -1);
	for(int i = 1; i <= m1; i ++){
		merger(e1[i].u, e1[i].v);
	}

	for(int i = 1; i <= m2; i ++){
		if(merger(e2[i].u, e2[i].v)){
			pos[++ cnt] = i;
		}
	}

	fill(par + 1, par + n + 1, - 1);
	for(int  i = 1; i <= cnt; i ++){
		merger(e2[pos[i]].u, e2[pos[i]].v);
	}

	int ans = b[cnt] + a[n - cnt - 1], p = cnt;
	for(int i = 1; i <= m2; i ++){
		if(merger(e2[i].u, e2[i].v)){
			pos[++ cnt] = i;
			if(minimum(ans, b[cnt] + a[n - cnt - 1])){
				p = cnt ;
			}
		}
	}

	
	fill(par + 1, par + n + 1, - 1);
	for(int i = 1; i <= p;  i ++){
		merger(e2[pos[i]].u, e2[pos[i]].v);
		cout << e2[pos[i]].id << " ";
	}
	
	for(int i = 1; i <= m1; i ++){
		if(merger(e1[i].u, e1[i].v)){
			cout << e1[i].id << " ";
		}
	}

	cout << el;
}

signed main() {
	cin.tie(NULL) -> sync_with_stdio(false);

	int test = 1;	
	cin >> test;

	for(int i = 1; i <= test; i ++){
		solve();
	}
	
	return 0;
}
/* 
	Hi I'm Powder
		fb.com/hai290605
			cf: Etohari
						*/
