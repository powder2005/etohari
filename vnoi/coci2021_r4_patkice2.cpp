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
const int MAXN = 2e3 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, m, xs, ys, xt, yt, dist[MAXN][MAXN], trace[MAXN][MAXN];
char a[MAXN][MAXN];

inline int eto(char x){
    if (x == 'v')return 0;
    if (x == '>')return 1;
    if (x == '^')return 2;
    if (x == '<')return 3;
    return 4;
}
inline char hari(int x){
    if (x == 0)return 'v';
    if (x == 1)return '>';
    if (x == 2)return '^';
    return '<';
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cin >> a[i][j];
            if (a[i][j] == 'o')xs = i, ys = j;
            if (a[i][j] == 'x')xt = i, yt = j;
        }
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            dist[i][j] = INF;
        }
    }

    priority_queue < tuple < int, int, int >, 
        vector < tuple < int, int, int > >, greater < tuple < int, int, int > > > qe;

    for ( qe.emplace(0, xs, ys), dist[xs][ys] = 0; !qe.empty(); ){
        auto [d, x, y] = qe.top(); qe.pop();
        
        if ( dist[x][y] != d)continue;
        if ( x == xt && y == yt)break;
        
        for (int i = 0; i < 4; i ++){
            int newX = x + d4x[i];
            int newY = y + d4y[i];

            if (newX < 0 || newX > n || newY < 0 || newY > m)continue;
            int e = eto(a[x][y]) != i;
            
            if (minimum(dist[newX][newY], dist[x][y] + e)){
                qe.emplace(dist[newX][newY], newX, newY);
                trace[newX][newY] = i;
            }
        }
    }

    cout << dist[xt][yt] - 1 << el;

    while (true){
        int d = trace[xt][yt];
        xt -= d4x[d]; yt -= d4y[d];
        if (xt == xs && yt == ys)break;
        a[xt][yt] = hari(d);
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= m; j ++){
            cout << a[i][j];
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
