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
#define NAME "PAIR"
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

int n, d, res, a[MAXN];
vector < pii > f;

void solve(){
    cin >> n >> d;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    
    for(int i = 1; i <= n; i ++){
        for(int j = i + 1; j <= n; j ++){
            f.emplace_back(i, j);
        }
    }

    sort(f.begin(), f.end(), [](pii x, pii y){
        return a[x.fi] + a[x.se] < a[y.fi] + a[y.se];
    });

    for(int i = 0; i < len(f); ){
        int p = i, t = a[f[i].fi] + a[f[i].se], save = i;
        vector < pii > vt;
        while(p < len(f) && a[f[p].fi] + a[f[p].se] - t <= d){
            vt.push_back(f[p]);
            if(a[f[p].fi] + a[f[p].se] - t == 0)save = p + 1;
            p ++;
        }
        i = save;

        set < int > st;
        for(pii x : vt){
            st.insert(x.fi);
            st.insert(x.se);
        }

        vector < int > pos(st.begin(), st.end());

        int ans = 0;
        for(int l = 0, r = len(pos) - 1; l < r; ){
            if((a[pos[l]] + a[pos[r]] == t) || (a[pos[l]] + a[pos[r]] == t + d)){
                l ++;
                r --;
                ans ++;
            }else{
                if(a[pos[l]] + a[pos[r]] < t)l ++;
                else r --;
            }
        }
        res = max(res, ans);

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
