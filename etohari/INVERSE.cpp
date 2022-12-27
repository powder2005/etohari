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
#define NAME "INVERSE"
#define HACKER "ETOHARI"
#define fi first        
#define se second
#define bit(a,b) ((a >> b)&1)
#define countBit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
#define len(s) (int)s.size()
const int MAXN = 5e2 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 2;
const int INF = 0x3f3f3f3f;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, m, c[MAXN][MAXN], ansRow[MAXN], ansCol[MAXN];
char a[MAXN][MAXN], b[MAXN][MAXN];
int etohari(int row, int val){
    ansRow[row] = val;
    for(int col = 1; col <= m; col ++){
        ansCol[col] = (c[row][col] - ansRow[row] + MOD) % MOD;
    }
    for(int row = 2; row <= n; row ++){
        ansRow[row] = (c[row][1] - ansCol[1] + MOD) % MOD;
        for(int col = 2; col <= m; col ++){
            if(ansRow[row] != ((c[row][col] - ansCol[col] + MOD) % MOD)){
                return -1;
            }
        }
    }
    return sum(ansRow + 1, ansRow + n + 1, 0) + sum(ansCol + 1, ansCol + m + 1, 0);
}
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> b[i][j];
        }
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            c[i][j] = a[i][j] != b[i][j];
        }
    }

    int x = etohari(1, 0);
    int y = etohari(1, 1);
    
    if(x == -1 && y == -1){
        cout << -1 << el; 
        return ;
    }else
    if(x < y){
        cout << etohari(1, 0) << el;
    }else{
        cout << etohari(1, 1) << el;        
    }

    for(int i = 1; i <= n; i ++){
        if(ansRow[i] != 0)cout << i << " ";
    }

    for(int i = 1; i <= m; i ++){
        if(ansCol[i] != 0)cout << -i <<" ";
    }
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
