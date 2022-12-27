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


ll A, B, dp[20][2][10][2][20];
int n, D, K, a[20];

ll cal(int pos, int check, int preDigit, int check1, int cnt){
    if (cnt > K)return 0;
    if (pos < 0)return 1;
    if (dp[pos][check][preDigit][check1][cnt] != -1)return dp[pos][check][preDigit][check1][cnt];

    ll ans = 0;
    int d = a[pos];

    for (int digit = 0; digit < 10; digit ++){
        if(check || digit <= d){
            ans += cal(pos - 1, check || (digit < d), digit, check1 || (digit > 0), cnt + (abs(preDigit - digit) <= D && check1));
        }
    } 

    return dp[pos][check][preDigit][check1][cnt] = ans;
    
}
ll etohari(ll x){
    if (x < 10) return x + 1;

    n = log10(x);
    for (int i = 0; i <= n; i ++){
        a[i] = x % 10;
        x /= 10;
    }

    memset(dp, -1, sizeof dp);
    return cal(n, 0, 0, 0, 0);
}
void solve(){   
    cin >> A >> B >> D >> K;
    cout << etohari(B) - etohari(A - 1);
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
                        */
