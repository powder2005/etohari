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

int n, x[MAXN], y[MAXN], z[MAXN], id[MAXN];
ll res, ans, preSum[MAXN], sufSum[MAXN];
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> x[i] >> y[i] >> z[i];
    }

    for(int i = 1; i <= n; i ++){
        id[i] = i;
        y[i] -= x[i];
        z[i] -= x[i];
        res += x[i];
    }

    sort(id + 1, id + n + 1, [](int i, int j){
        return y[i] - z[i] < y[j] - z[j]; 
    });
    
    auto cal = [](int x){
        return 1ll * x * (x + 1) / 2;
    };

    for(int i = 1; i <= n; i ++){
        preSum[i] = preSum[i - 1] + y[id[i]];
    }
    for(int i = n; i >= 1; i --){
        sufSum[i] = sufSum[i + 1] + z[id[i]];
    }

    for(int i = 0; i <= n; i ++){
        for(int j = i; j <= n; j ++){
            minimum(ans, preSum[i] - cal(i - 1));
            minimum(ans, sufSum[j + 1] - cal(n - j - 1));
            minimum(ans, preSum[i] + sufSum[j + 1] - cal(i - 1) - cal(n - j - 1));
        }
    }

    cout << res + ans ;
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
