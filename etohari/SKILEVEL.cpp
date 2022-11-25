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
#define NAME "SKILEVEL"
#define HACKER "ETOHARI"
#define fi first        
#define se second
#define bit(a,b) ((a >> b)&1)
#define countBit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
#define len(s) (int)s.size()
const int MAXN = 5e2 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int d4x[4] = {1, 0, -1, 0}; 
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, m, t, par[MAXN * MAXN], h[MAXN][MAXN], cnt[MAXN * MAXN];
vector < tuple < int, int, int > > edge;
ll res = 0;
inline int get(int i, int j){
    return (i - 1) * m + j;
}
inline int root(int u){
    return (par[u] < 0 ? u : (par[u] = root(par[u])));
}
void merger(int u, int v, int w){
    u = root(u);
    v = root(v);
    if(u == v)return ;
    if(par[u] < par[v])swap(u, v);

    par[u] += par[v];
    cnt[u] += cnt[v];
    par[v] = u;
    cnt[v] = 0;
    if(-par[u] >= t){
        res += 1ll * cnt[u] * w;
        cnt[u] = 0;
    }
    
}
signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    freopen(NAME".inp", "r", stdin);
    freopen(NAME".out", "w", stdout);

    cin >> n >> m >> t;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
             cin >> h[i][j];
        }
    }
    
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            int check; cin >> check;
            if(check)cnt[get(i, j)] = 1;
        }
    }

    if(t == 1){
        cout << 0 ;
        return 0;
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            par[get(i, j)] = -1;
            for(int d = 0; d < 4; d ++){
                int newX = i + d4x[d];
                int newY = j + d4y[d];
                if(newX < 1 || newX > n || newY < 1 || newY > m)continue;
                edge.emplace_back(abs(h[i][j] - h[newX][newY]), get(i, j), get(newX, newY));
            }
        }
    }

    sort(edge.begin(), edge.end());

    for(auto [w, u, v] : edge){
        merger(u, v, w);
    }

    cout << res ;
    return 0;
}
/* 
    Hi I'm Powder
        fb.com/hai290605
            cf: Etohari
                        */
