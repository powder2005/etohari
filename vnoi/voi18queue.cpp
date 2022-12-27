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

int n, m, a[MAXN], b[MAXN], bitL[MAXN], bitR[MAXN];
void update(int BIT[], int p){
    for (; p <= m; p += (-p) & p){
        BIT[p] ++;
    }
}
int get(int BIT[], int p){
    int ans = 0;
    for (; p > 0; p -= (-p) & p){
        ans += BIT[p];
    }
    return ans;
}

bool check(int limN){
    fill(bitL + 1, bitL + m + 1, 0);
    fill(bitR + 1, bitR + m + 1, 0);

    vector < pii > p;
    for (int i = 1; i <= limN; i ++){
        p.emplace_back(a[i], b[i]);

    }

    sort(p.begin(), p.end(), [](pii x, pii y){
        return (x.se < y.se) || (x.se == y.se && x.fi > y.fi);
    });

    for (auto [x, y] : p){
        update(bitL, x);
        update(bitR, y);
        int cnt = get(bitR, y) - get(bitL, x - 1);
        if (cnt > y - x + 1)return false;
    }

    return true;
}
void solve(){
    cin >> m >> n;

    for (int i = 1; i <= n; i ++){
        cin >> a[i] >> b[i];
    }

    int res = 0;
    for (int l = 1, r = n; l <= r; ){
        int mid = l + r >> 1;
        if (check(mid)){
            res = mid;
            l = mid + 1;
        }else {
            r = mid - 1;
        }
    }

    cout << res << el;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

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
