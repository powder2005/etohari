#include "bits/stdc++.h"
// #include "ext/pb_ds/tree_policy.hpp"
// #include "ext/pb_ds/assoc_container.hpp"

// using namespace __gnu_pbds;
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
using pld = pair < ld, ld >;
using point = pair < ld, ld > ;
using line = pair < point, point >;
// using ordered_set = tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update >;

template < class T > bool minimum(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool maximum(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define el "\n"
#define NAME "PROJECT"
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

int d4x[4] = {1, 0, -1, 0}; 
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

struct node{
    int u, v, id;
    ld l, c;
} edge[MAXN];

int n, m, idd[MAXN], par[MAXN];
vector < int > res;
int root(int u){
    return par[u] < 0 ? u : (par[u] = root(par[u]));
}
bool merger(int u, int v){
    u = root(u); v = root(v);
    if(u == v)return false;
    if(par[u] < par[v])swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return true;
}
bool check(ld x, ld exp){
    res.clear();
    iota(idd + 1, idd + m + 1, 1);
    fill(par + 1, par + n + 1, -1);
    sort(idd + 1, idd + m + 1, [&](int i, int j){
        return x * edge[i].l - edge[i].c > (x * edge[j].l - edge[j].c);
    });

    ld ans = 0;
    for(int i = 1; i <= m; i ++){
        if(merger(edge[idd[i]].u, edge[idd[i]].v)){
            res.emplace_back(edge[idd[i]].id);
            ans += x * edge[idd[i]].l - edge[idd[i]].c;
        }
    }
    return ans >= 0;
}
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; i ++){
        cin >> edge[i].u >> edge[i].v >> edge[i].l >> edge[i].c;
        edge[i].id = i;
    }
    
    ld ans = 0;
    for(ld bot = 1e-10, top = 1e10, exp = 1e-9; bot <= top; ){
        ld mid = (bot + top) / 2;
        if(check(mid, exp)){
            ans = mid;
            top = mid - exp;
        }else {
            bot = mid + exp;
        }
    }

    assert(ans != 0);
    sort(res.begin(), res.end());
    for(int i = 0; i < n - 1; i ++){
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
