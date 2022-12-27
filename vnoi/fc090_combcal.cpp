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
const int MOD = 1e7 + 19;
const int INF = 0x3f3f3f3f;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

ll f[MOD], g[MOD];
ll power(ll a, ll n){
    ll ans = 1;
    for (;n > 0; n >>= 1, a = (a * a) % MOD){
        if (n & 1)ans = (ans * a) % MOD;
    }
    return ans;
}
void init(){
    f[0] = 1;
    for (int i = 1; i < MOD; i ++){
        f[i] = f[i - 1] * i;
        f[i] %= MOD;
    }
    g[MOD - 1] = power(f[MOD - 1], MOD - 2);
    for (int i = MOD - 2; i >= 0; i --){
        g[i] = g[i + 1] * (i + 1);
        g[i] %= MOD;
    }
}
ll com(ll n, ll k){
    ll ans = 1;
    while (n > 0){
        ll x = n % MOD;
        ll y = k % MOD;
        if (x < y)return 0;
        (ans *= f[x]) %= MOD;
        (ans *= g[y]) %= MOD;
        (ans *= g[x - y]) %= MOD;
        n /= MOD;
        k /= MOD;
    }
    return ans;
}
void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    ll res = com(n + m - 2, k - 2);
    res *= n % MOD;
    res %= MOD;
    res *= m % MOD;
    res %= MOD;
    cout << res << el;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    init();
    
    int test = 1;
    cin >> test;

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
