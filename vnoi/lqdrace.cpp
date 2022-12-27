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

int n, h[MAXN], minLen = INF;
ll res, k, s[MAXN];
vector < pii > adj[MAXN];

void dfs(int u, int p, set < tuple < ll, int, int > > &st){
    st.insert({s[u], h[u], 1});

    for (auto [v, l] : adj[u]){
        if (v == p)continue;

        h[v] = h[u] + 1;
        s[v] = s[u] + l;

        set < tuple < ll, int, int > > last;
        dfs(v, u, last);

        if (len(st) < len(last))swap(last, st);

        for (auto [val1, h1, cnt1] : last){
            auto p = st.lower_bound({k - val1 + 2 * s[u], 0, 0});
            if (p == st.end())continue;
            auto [val2, h2, cnt2] = *p;
            if (val2 != k - val1 + 2 * s[u]) continue;
            if (minimum(minLen, h1 + h2 - 2 * h[u])){
                res = 0;
            }
            if (minLen == h1 + h2 - 2 * h[u]){
                res += 1ll * cnt1 * cnt2;
            }
        }

        for (auto [val1, h1, cnt1] : last){
            auto p = st.lower_bound({val1, h1, 0});
            if (p == st.end()){
                st.insert({val1, h1, cnt1});
                continue;
            }
            auto [val2, h2, cnt2] = *p;
            if (val2 != val1 || h1 != h2){
                st.insert({val1, h1, cnt1});
            }else {
                st.erase(p);
                st.insert({val2, h2, cnt1 + cnt2});
            }
        }
    }
}
void solve(){
    cin >> n >> k;

    for (int i = 1; i < n; i ++){
        int u, v, l; cin >> u >> v >> l;
        adj[u].emplace_back(v, l);
        adj[v].emplace_back(u, l);
    }

    int ans = INF, ans1;
    for (int i = 0; i < n; i ++){
        fill(h, h + n, 0);
        fill(s, s + n, 0);
        set < tuple < ll, int, int > > st;
        minLen = INF;
        res = 0;
        dfs(i, -1, st); 
        if (minLen < ans){
            ans1 = res;
            ans = minLen;
        }
    }

    cout << (ans == INF ? -1 : res * 2) << el;

}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

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
