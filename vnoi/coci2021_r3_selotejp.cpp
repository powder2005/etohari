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
const int MAXN = 1e3 + 10;
const int MAXM = 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, m;
char a[MAXN][MAXM];

int cost(int id, int mask1, int mask2){
    int cnt = 0;
    for (int j = 0; j < m; j ++){
        if(bit(mask1, j)){
            if(a[id][j] == '.')cnt = INF;
            if(!bit(mask2, j))cnt ++;
        }else {
            if(a[id][j] == '.')continue;
            
        }
    }
    return cnt ;
}
void solve(){
    cin >> n >> m ;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            cin >> a[i][j];
        }
    }

    vector < int > dp(1 << m), preDp(1 << m);

    for (int mask = 0; mask < (1 << m); mask ++){
        dp[mask] = preDp[mask] = cost(1, mask, 0);
    }

    for (int i = 1; i < n; i ++){
        for (int mask1 = 0; mask1 < (1 << m); mask1 ++){
            dp[mask1] = INF;
            for (int mask2 = 0; mask2 < (1 << m); mask2 ++){
                minimum(dp[mask1], preDp[mask2] + cost(i, mask1, mask2));
            }
        }
        preDp = dp;
    }

    cout << *max_element(dp.begin(), dp.end()) ;
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
