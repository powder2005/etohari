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
const int MAXN = 1e5 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, q, f[MAXN], rmq[MAXN][20];
ll a[MAXN];
map < ll, bool > check;
void solve(){
    cin >> n >> q;
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }

    for (int l = 0, r = 0; r < n; r ++){
        if (check[a[r]]){
            while (a[l] != a[r])check[a[l]] = false, l ++;
            l ++;
        }else check[a[r]] = true;
        f[r] = l;
        // cerr << l << " " << r << el;
        rmq[r][0] = r - l + 1;
    }

    // for (int i = 1; i <= q; i ++){
    //     int l, r; cin >> l >> r;
    //     int ans = 0;
    //     for (int j = l; j <= r; j ++){
    //         ans = max(ans, min(j - f[j] + 1, j - l + 1));
    //     }
    //     cout << ans << el;
    // }

    for (int j = 1; (1 << j) <= n; j ++){
        for (int i = 0; i + (1 << j) - 1 < n; i ++){
            rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
        }
    }

    auto get = [&](int l, int r){
        int k = log2(r - l + 1);
        return max(rmq[l][k], rmq[r - (1 << k) + 1][k]); 
    };

    for (int i = 1; i <= q; i ++){
        int l, r; cin >> l >> r;
        int ans = r;

        for (int bot = l, top = r; bot <= top; ){
            int mid = bot + top >> 1;
            if (f[mid] >= l){
                ans = mid;
                top = mid - 1;
            }else {
                bot = mid + 1;
            }
        }

        cout << min(r - l + 1, max(ans - l, get(ans, r))) << el;
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
    f[i] là đoạn dài nhất bắt đầu từ i
                         */
