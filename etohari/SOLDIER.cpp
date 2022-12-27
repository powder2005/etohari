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
#define NAME "SOLDIER"
#define HACKER "ETOHARI"
#define fi first        
#define se second
#define bit(a,b) ((a >> b)&1)
#define countBit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
#define len(s) (int)s.size()
const int MAXN = 5e3 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, k, a[MAXN], dpLeft[MAXN][MAXN], dpRight[MAXN][MAXN];
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 0; j <= k; j ++){
            if(j >= a[i])dpLeft[i][j] = max(dpLeft[i - 1][j], dpLeft[i - 1][j - a[i]] + a[i]);
                else dpLeft[i][j] = dpLeft[i - 1][j];
        }
    }

    for (int i = n; i >= 1; i --){
        for (int j = 0; j <= k; j ++){
            if(j >= a[i])dpRight[i][j] = max(dpRight[i + 1][j], dpRight[i + 1][j - a[i]] + a[i]);
                else dpRight[i][j] = dpRight[i + 1][j];
        }
    }

    for (int i = 1; i <= n; i ++){
        bool ok = false;
        for (int j = 0; j < k; j ++){
            if(dpLeft[i - 1][j] || dpRight[i + 1][k - j - 1]){
                if(dpLeft[i - 1][j] + dpRight[i + 1][k - j - 1] >= k - a[i]){
                    ok = true;
                    break;
                }
            }
        }
        cout << ok;
    }
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

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
    dp[i][j] là xét i thằng đầu tiên và tìm được các thằng có tổng lớn nhất <= j
    dp[i - 1][j] + dp[i + 1][k - j] < k
    dp[i - 1][j] + dp[i + 1][k - j] >= k + a[i]
    cnt0 * cnt1 + cnt0 * cnt0 + cnt1 * cnt1 
                        */
