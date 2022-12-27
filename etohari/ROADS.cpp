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
#define NAME "ROADS"
#define HACKER "ETOHARI"
#define fi first        
#define se second
#define bit(a,b) ((a >> b)&1)
#define countBit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
#define len(s) (int)s.size()
const int MAXN = 1e5 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, m, s, t, cTrace; 
vector < tuple < int, int, int > > adj[MAXN];
map < int,  bool > check[MAXN];
map < int, tuple < int, int, int > > trace[MAXN];
vector < int > res;
void bfs(){
    queue < pii > qe;
    for (qe.emplace(s, 0), check[s][0] = true; !qe.empty(); qe.pop()){
        auto [u, c] = qe.front();

        for (auto [v, f, id] : adj[u]){
            if (check[v][f] || f == c) continue;
            trace[v][f] = {u, c, id};
            qe.emplace(v, f);
            check[v][f] = true;
            if (v == t){
                cTrace = f;2 1 1 2
1 2 2
                return ;
            }
        }
    }
}
void solve(){
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i ++){
        int u, v, f; cin >> u >> v >> f;
        adj[u].emplace_back(v, f, i);
        adj[v].emplace_back(u, f, i);
    }

    bfs();

    while(cTrace != 0 && t != s){
        auto [x, y, z] = trace[t][cTrace];
        res.emplace_back(z);
        t = x; cTrace = y;
    }

    cout << (len(res) ? len(res) : -1) << el;
    for (int i = len(res) - 1; i >= 0; i --){
        cout << res[i] << " ";
    }
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    freopen(NAME".inp", "r", stdin);
    freopen(NAME".out", "w", stdout);

    int test = 1;
    // cin >> test;

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
