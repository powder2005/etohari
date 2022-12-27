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
const int MAXN = 1e5 + 1;
const int MAXM = 20;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, m, res, f[MAXN];
bitset < MAXN > pos[MAXM], nega[MAXM];

void solve(){
    cin >> n >> m;

    f[0] = 1;
    for (int i = 1; i <= n; i ++){
        f[i] = f[i - 1] * 2;
        f[i] %= MOD;
    }

    for (int i = 0; i < m; i ++){
        int k; cin >> k;
        for (int j = 0; j < k; j ++){
            int a; cin >> a;
            if (a > 0)pos[i][a] = 1;
                else nega[i][-a] = 1;
        }
    }

    res = f[n];
    for (int mask = 1; mask < (1 << m); mask ++){
        bitset < MAXN > position;
        bitset < MAXN > negation;

        for (int i = 0; i < m; i ++){
            if (bit(mask, i)){
                position |= pos[i];
                negation |= nega[i];
            }
        }

        int com = (position & negation).count();
        if (com == 0){
            int tmp = f[n - position.count() - negation.count()];
            if (countBit(mask) % 2){
                res -= tmp;
            }else{
                res += tmp;
            }
            res %= MOD;
        }

    }

    cout << (res + MOD) % MOD ;
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
