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
#define NAME "BILL"
#define HACKER "ETOHARI"
#define fi first        
#define se second
#define bit(a,b) ((a >> b)&1)
#define countBit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
#define len(s) (int)s.size()
#define x fi
#define y se
const int MAXN = 1e6 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int d4x[4] = {1, 0, -1, 0}; 
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};


int n;
point root, a[MAXN];
ld dot(point a, point b, point c){
    point ab, ac;
    ab.x = b.x - a.x;
    ab.y = b.y - a.y;
    ac.x = c.x - a.x;
    ac.y = c.y - a.y;
    return ab.x * ac.x + ab.y * ac.y;
}
ld cross(point a, point b, point c){
    point ab, ac;
    ab.x = b.x - a.x;
    ab.y = b.y - a.y;
    ac.x = c.x - a.x;
    ac.y = c.y - a.y;
    return ab.x * ac.y - ab.y * ac.x;
}
ld dist(point a, point b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
ld linePointDist(point a, point b, point c){
    ld h = abs(cross(a, b, c)) / dist(a, b);
    // cout << abs(cross(a, b, c)) << " " << dist(a, b) << el;
    ld dot1 = dot(b, a, c);
    if(dot1 < 0)return dist(b, c);
    ld dot2 = dot(a, b, c);
    if(dot2 < 0)return dist(a, c);
    // cout << (ld)h << el;
    return h;
}
void solve(){
    cin >> n >> root.x >> root.y;
    // cout << root.x << root.y << el;
    for(int i = 1; i <= n; i ++){
        cin >> a[i].x >> a[i].y;
        // cout << a[i].x << " " << a[i].y << el;
    }

    ld res = 1e19;

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(a[i] != a[j])
            res = min(res, linePointDist(a[i], a[j], root));
        }
    }

    cout << fixed << setprecision(4) << res << el;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    freopen(NAME".inp", "r", stdin);
    freopen(NAME".out", "w", stdout);
    
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
