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
#define NAME "LONGRUN"
#define HACKER "ETOHARI"
#define fi first        
#define se second
#define x fi
#define y se
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

int n, l, c, a[MAXN], v[MAXN], BIT[MAXN];
vector < pll > p;
pll d[MAXN];
ll res, s[MAXN];
void update(int p, int val){
    for(; p <= n; p += (-p) & p){
        BIT[p] += val;
    }
}
int get(int p){
    int ans = 0;
    for(; p > 0; p -= (-p) & p){
        ans += BIT[p];
    }
    return ans;
}

pll operator - (pll a, pll b){
    pll ans;
    ans.x = a.x * b.y - b.x * a.y;
    ans.y = a.y * b.y; 
    if(ans.x == 0){
        ans = {0, 1};
        return ans;
    }
    ll GCD = __gcd(ans.x, ans.y);
    ans.x /= GCD;
    ans.y /= GCD;
    return ans;
}
pll operator * (pll a, pll b){
    pll ans;
    ans.x = a.x * b.x;
    ans.y = a.y * b.y;
    if(ans.x == 0){
        ans = {0, 1};
        return ans;
    }
    ll GCD = __gcd(ans.x, ans.y);
    ans.x /= GCD;
    ans.y /= GCD;
    return ans;
}

void solve(){
    cin >> n >> l >> c;
    for(int i = 1; i <= n; i ++){
        cin >> v[i];
    }

    pll timeMax = {l * c, *max_element(v + 1, v + n + 1)};
    for(int i = 1; i <= n; i ++){
        pll tmp = {v[i], c};
        d[i] = timeMax * tmp;
    }

    sort(d + 1, d + n + 1, [](pll a, pll b){
        return a.x * b.y < b.x * a.y;
    });

    for(int i = 1; i <= n; i ++){
        a[i] = d[i].x / d[i].y;
        pll tmp = {a[i], 1};
        d[i] = d[i] - tmp;
        p.push_back(d[i]);
    }
    
    sort(p.begin(), p.end(), [](pll a, pll b){
        return a.x * b.y < b.x * a.y;
    });

    for(int i = 1; i <= n; i ++){
        res += 1ll * a[i] * (i - 1) - s[i - 1];
        s[i] = s[i - 1] + a[i];
        int id = lower_bound(p.begin(), p.end(), d[i], [](pll a, pll b){
            return a.x * b.y < b.x * a.y;
        }) - p.begin() + 1;
        
        res -= get(n) - get(id);
        update(id, 1);
    }

    cout << res ;
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
