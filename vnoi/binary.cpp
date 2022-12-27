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

int n, k, dp[33][2][2][33];

int cal(int pos, int check1, int check2, int cnt){
    if(pos < 0) return cnt == k;
    if(dp[pos][check1][check2][cnt] != -1) return dp[pos][check1][check2][cnt];

    int ans = 0;
    int cur = bit(n, pos);

    for (int digit = 0; digit < 2; digit ++){
        if (check2 || digit <= cur){
            ans += cal(pos - 1, check1 || (digit > 0), check2 || (digit < cur), cnt + (digit == 0 && check1));
        }
    }

    return dp[pos][check1][check2][cnt] = ans;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    while(cin >> n >> k){
        memset(dp, -1, sizeof dp);
        cout << cal(30, 0, 0, 0)  + (k == 1) - (k == 0) << el;
    }    

    return 0;
}
/* 
    Hi I'm Powder
        fb.com/hai290605
            cf: Etohari
                        */
