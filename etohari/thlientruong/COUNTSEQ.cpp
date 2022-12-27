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
#define NAME "COUNTSEQ"
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

ll power(ll a, ll n){
    ll ans = 1;
    for (; n > 0; n >>= 1, a = (a * a) % MOD){
        if (n & 1) ans = (ans * a) % MOD;
    }
    return ans;
}
void solve(){
    int s; cin >> s;
    int n = s;

    ll res = power(2, n - 1);

    vector < int > prime;
    for (int i = 2; i * i <= n; i ++){
        if(n % i == 0){
            prime.emplace_back(i);
            while(n % i == 0)n /= i;
        }
    }

    if(n != 1)prime.emplace_back(n);

    vector < pll > mask(1, make_pair(1, 1));
    for (int x : prime){
        for (int i = len(mask) - 1; i >= 0; i --){
            mask.emplace_back(mask[i].fi * x, mask[i].se * (-1));
            res += mask.back().se * power(2, s / mask.back().fi - 1);
            res %= MOD;
        }
    }

    cout << (res + MOD) % MOD << el;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    freopen(NAME".inp", "r", stdin);
    freopen(NAME".out", "w", stdout);

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
    1 1 1
    1 2
    2 1
    3
                        */
