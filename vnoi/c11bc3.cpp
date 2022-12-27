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
const int MAXN = 1e2 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};


int n, m, p, fBlue[MAXN][MAXN], fRed[MAXN][MAXN];
char a[MAXN][MAXN];

int cal(int x1, int y1, int u1, int v1, int x2, int y2, int u2, int v2){
    int x = max(x1, x2);
    int u = min(u1, u2);
    int y = max(y1, y2);
    int v = min(v1, v2);
    if (x > u || y > v)return 0;
    return (fBlue[u][v] - fBlue[x - 1][v] - fBlue[u][y - 1] + fBlue[x - 1][y - 1]
            - fRed[u][v] + fRed[x - 1][v] + fRed[u][y - 1] - fRed[x - 1][y - 1]);
}
void solve(){
    cin >> n >> m >> p;
    
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            fBlue[i][j] = fBlue[i - 1][j] + fBlue[i][j - 1] - fBlue[i - 1][j - 1] + (a[i][j] == '1');
            fRed[i][j] = fRed[i - 1][j] + fRed[i][j - 1] - fRed[i - 1][j - 1] + (a[i][j] == '2');
        }
    }

    for (int rowBlue = p; rowBlue <= n; rowBlue ++){
        for (int colBlue = p; colBlue <= m; colBlue ++){
            int res = fBlue[n][m], s = fBlue[n][m];
            for (int rowRed = p; rowRed <= n; rowRed ++){
                for (int colRed = p; colRed <= m; colRed ++){
                    res = min(res, s
                        - (fBlue[rowBlue][colBlue] - fBlue[rowBlue - p][colBlue] - fBlue[rowBlue][colBlue - p] + fBlue[rowBlue - p][colBlue - p])
                        - (fBlue[rowRed][colRed] - fBlue[rowRed - p][colRed] - fBlue[rowRed][colRed - p] + fBlue[rowRed - p][colRed - p])
                        + (fRed[rowBlue][colBlue] - fRed[rowBlue - p][colBlue] - fRed[rowBlue][colBlue - p] + fRed[rowBlue - p][colBlue - p])
                        + (fRed[rowRed][colRed] - fRed[rowRed - p][colRed] - fRed[rowRed][colRed - p] + fRed[rowRed - p][colRed - p])
                        + 2 * cal(rowBlue - p + 1, colBlue - p + 1, rowBlue, colBlue,
                            rowRed - p + 1, colRed - p + 1, rowRed, colRed      
                        )
                    );
                }
            }
            cout << res << " ";
        }
        cout << el;
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
