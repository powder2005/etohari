#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
using pld = pair < ld, ld >;
using point = pair < ld, ld > ;
using line = pair < point, point >;

template < class T > bool minimum(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool maximum(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define el "\n"
#define int long long
#define NAME "ETOHARI"
#define HACKER "ETOHARI"
#define int ll
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

int n, k, ans, a[MAXN], dp[MAXN];

bool check(int x){

    int res = INF;
    for(int i = 1; i <= n; i ++){
        dp[i] = i - 1;
    }

    for(int  i = 2; i <= n; i ++){
        for(int j = 1; j < i; j ++){
            if(abs(a[j] - a[i]) <= x * (i - j)){
                minimum(dp[i], dp[j] + (i - j - 1));
            }
            res = min(res, dp[i] + (n - i));
        }
    }

    // for(int i = 1; i <= n; i ++){
    //     cout << dp[i] << " ";
    // }
    // cout << el;
    return res <= k;
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    for(int l = 0, r = 2e9 + 10; l <= r; ){
        int m = l + r >> 1;
        if(check(m)){
            ans = m;
            r = m - 1;
        }else {
            l = m + 1;
        }
    }

    cout << ans ;
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
