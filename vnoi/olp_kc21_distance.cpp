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
const int INF = 2e9 + 10;

int d4x[4] = {1, 0, -1, 0}; 
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, m, k, a[MAXN], b[MAXN], rmq[20][MAXN];
void solve(){
    cin >> n >> m >> k ;
    
    for(int i = 1; i <= n; i ++){
        cin >> a[i] ;
    }

    for(int i = 1; i <= m; i ++){
        cin >> b[i] ;
    }

    sort(b + 1, b + m + 1);

    for(int i = 1; i <= n; i ++){
        int r = lower_bound(b + 1, b + m + 1, a[i]) - b;
        int l = r - 1;
        rmq[0][i] = min((l > 0 ? abs(a[i] - b[l]) : INF), (r <= m ? abs(a[i] - b[r]) : INF));
    }

    auto get = [&](int l, int r){
        int k = log2(r - l + 1);
        return min(rmq[k][l], rmq[k][r - (1 << k) + 1]);
    };

    for(int j = 1; (1 << j) <= n; j ++){
        for(int i = 1; i + (1 << j) - 1 <= n; i ++){
            rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
        }
    }
    
    for(int i = 1; i <= k; i ++){
        int l, r;
        cin >> l >> r;
        cout << get(l, r) << el;
    }
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
