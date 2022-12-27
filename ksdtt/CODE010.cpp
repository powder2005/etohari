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
#define NAME "CODE010"
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

int dp[MAXN][4];
void solve(){
    int n; cin >> n;
    string s; cin >> s; 
    s = '$' + s;

    if (n <= 2){
        cout << 0 ;
        return ;
    }

    for (int i = 1; i <= n; i ++){
        for (int mask = 0; mask < 4; mask ++){
            dp[i][mask] = INF;
        }
    }

    dp[2][0] = (s[2] != '0') + (s[1] != '0');
    dp[2][1] = (s[2] != '0') + (s[1] != '1');
    dp[2][2] = (s[2] != '1') + (s[1] != '0');
    dp[2][3] = (s[2] != '1') + (s[1] != '1');

    // cerr << dp[2][0] << " " << dp[2][1] << " " << dp[2][2] << " " << dp[2][3] << el;
    for (int i = 3; i <= n; i ++){
        for (int mask = 0; mask < 4; mask ++){
            for (int p = 0; p < 2; p ++){
                if (mask + 4 * p == 2)continue;
                int newMask = (mask >> 1) + 2 * p;
                minimum(dp[i][newMask], dp[i - 1][mask] + ((s[i] - '0') != p));
            }
        }
    }

    cout << *min_element(dp[n], dp[n] + 4);
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
    f[i][mask] là số bước ít nhất để đoạn 1..i có 2 bit cuối là mask 
    và thỏa mãn yêu cầu
                        */
