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
const int BASE = 811;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int a[7];

bool check(int a, int b, int c){
    return (a + b > c) && (a + c > b) && (b + c > a);
}

ll cal(int u, int U, int v, int V, int w, int W)
{
    ll X = (w * w + u * u - V * V);
    ll Y = (v * v + w * w - U * U);
    ll Z = (u * u + v * v - W * W);
    ll T = (u * v * w);
    return X * Y * Z + 2 * 2 * T * T - u * u * Y * Y - v * v * X * X - w * w * Z * Z;
}

void solve(){
    for(int i = 1; i <= 6; i ++){
        cin >> a[i];
    }

    sort(a + 1, a + 7);

    do{
        int BC = a[1];
        int CA = a[2];
        int AB = a[3];
        int OA = a[4];
        int OB = a[5];
        int OC = a[6];
        ll ABCO = cal(OA, BC, OB, CA, OC, AB);
        bool ABC = check(BC, CA, AB);
        bool OBC = check(BC, OB, OC);
        bool OCA = check(OC, CA, OA);
        bool OAB = check(OA, OB, AB);
        if(ABC && OBC && OCA && OAB && ABCO > 0){
            cout << "Yes" << el;
            return ;
        }
    }while(next_permutation(a + 1, a + 7));

    cout << "No" << el;
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
