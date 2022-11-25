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

int d4x[4] = {1, 0, -1, 0}; 
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};



int h, w, n, x[MAXN], y[MAXN], id[MAXN];
ll f[MAXN], g[MAXN], dp[MAXN];

ll power(ll a, ll exp){
    ll ans = 1;
    for(; exp > 0; exp >>= 1, a = (a * a) % MOD){
        if(exp & 1)ans = (ans * a) % MOD;
    }
    return ans;
}
void init(){
    f[0] = 1;
    for(int i = 1; i < MAXN; i ++){
        f[i] = f[i - 1] * i;
        f[i] %= MOD;
    }
    g[MAXN - 1] = power(f[MAXN - 1], MOD - 2);
    for(int i = MAXN - 2; i >= 0; i --){
        g[i] = g[i + 1] * (i + 1);
        g[i] %= MOD;
    }
}
ll com(int n, int k){
    ll ans = f[n];
    ans *= g[k];
    ans %= MOD;
    ans *= g[n - k];
    ans %= MOD;
    return ans;
}
void solve(){
    cin >> h >> w >> n ;
    for(int i = 1; i <= n; i ++){
        cin >> x[i] >> y[i] ;
    }

    iota(id + 1, id + n + 1, 1);
    sort(id + 1, id + n + 1, [](int i, int j){
        return x[i] < x[j] || (x[i] == x[j] && y[i] < y[j]);
    });

    x[id[n + 1] = n + 1] = h;
    y[id[n + 1] = n + 1] = w;

    for(int i = 1; i <= n + 1; i ++){
        ll s = com(x[id[i]] + y[id[i]] - 2, x[id[i]] - 1);
        for(int j = 1; j < i; j ++){
            s -= dp[j] * com(x[id[i]] + y[id[i]] - x[id[j]] - y[id[j]], x[id[i]] - x[id[j]]);
            s %= MOD;
        }
        dp[i] = s;
    }

    cout << (dp[n + 1] + MOD) % MOD; ;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    init();
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
