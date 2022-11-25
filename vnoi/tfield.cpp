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
#define x fi
#define y se
const int MAXN = 1e3 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int d4x[4] = {1, 0, -1, 0}; 
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};


struct polygon {
    vector < point > data;
    auto & operator [] (int i) { return data[i]; }
    polygon () = default;
    polygon (int n) : data(n) {};
    ld area(){
        ld ans = 0;
        for(int i = 0; i < len(data); i ++){
            ans += (data[i].x - data[(i + 1) % len(data)].x) * 
                (data[i].y - data[(i + 1) % len(data)].y);
        }
        return ans / 2;
    }
} a[MAXN];

int n, k;
void solve(){
    cin >> n >> k ;
    for(int i = 0; i < n; i ++){
        int m;
        cin >> m;
        a[i] = polygon(m);
        for(int j = 0; j < m; j ++){
            cin >> a[i][j];
        }
    }

    sort(a + 1, a + n + 1, [](int i, int j){
        return a[]
    });
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
