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

int n, q, a[MAXN];
tuple < int, int, int > rmqMax[20][MAXN], rmqMin[20][MAXN];

tuple < int, int, int > cal(bool check, tuple < int, int, int > a, tuple < int, int, int > b){
    auto [x1, y1, z1] = a;
    auto [x2, y2, z2] = b;
    vector < int > f = {x1, y1, z1, x2, y2, z2};
    sort(f.begin(), f.end());
    if (check)return tuple(f[5], f[4], f[3]);
    return tuple(f[2], f[1], f[0]);
}
tuple < int, int, int > get(bool check, int l, int r){
    tuple < int, int, int > ans;
    if (!check)ans = tuple(INF, INF, INF);
        else ans = tuple(-INF, -INF, -INF);
    for (int i = 20; i >= 0; i --){
        if (bit(r - l + 1, i)){
            if (check)ans = cal(true, ans, rmqMax[i][l]);
            else ans = cal(false, ans, rmqMin[i][l]);
            l += (1 << i);
        }
    }
    return ans;
}
ll etohari(int l, int r){
    auto [x1, y1, z1] = get(true, l, r);
    auto [x2, y2, z2] = get(false, l, r);
    return min(1ll * x2 * y2 * z2, 1ll * z2 * x1 * y1);
}
void solve(){
    cin >> n >> q;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++){
        auto &[x1, y1, z1] = rmqMax[0][i];
        x1 = a[i]; y1 = -INF, z1 = -INF;
        auto &[x2, y2, z2] = rmqMin[0][i];
        x2 = a[i]; y2 = INF, z2 = INF;
    }

    for (int j = 1; j < 20; j ++){
        for (int i = 1; i + (1 << j) - 1 <= n; i ++){
            rmqMax[j][i] = cal(true, rmqMax[j - 1][i], rmqMax[j - 1][i + (1 << (j - 1))]);
            rmqMin[j][i] = cal(false, rmqMin[j - 1][i], rmqMin[j - 1][i + (1 << (j - 1))]);
        }
    }

    for (int i = 1; i <= q; i ++){
        int l, r; cin >> l >> r;
        cout << etohari(l, r) << el;
    }
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
