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
const int MAXN = 5e3 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int d4x[4] = {1, 0, -1, 0}; 
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, m, p, k;
string s, base;
bool check[MAXN][MAXN];
int get(int x){
    if(s[x] == 'D')return 0;
    else if(s[x] == 'R')return 1;
    else if(s[x] == 'U')return 2;
    else return 3;
}
void solve(){
    cin >> n >> m >> p >> k >> s;
    s = '$' + s;
    
    for(int i = 1; i <= p; i ++){
        int x, y; cin >> x >> y;
        check[x][y] = true;
    }

    vector < vector < int > > dist(n + 1, vector < int > (m + 1, INF));
    vector < vector < int > > lastDist(n + 1, vector < int > (m + 1, INF));

    dist[1][1] = lastDist[1][1] = 0;
    for(int d = 1; d <= k; d ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                if(lastDist[i][j] == INF)continue;
                if(check[i][j])continue;
                int newX = i + d4x[get(d)];
                int newY = j + d4y[get(d)];
                if(newX < 1 || newX > n || newY < 1 || newY > m)continue;
                minimum(dist[newX][newY], dist[i][j] + 1);
            }
        }

        lastDist = dist;
    }

    cout << (dist[n][m] == INF ? -1 : k - dist[n][m]) ;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    freopen(NAME".inp", "r", stdin);
    freopen(NAME".ans", "w", stdout);

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
// dp[u][x] là cách it đến được ô u với x ô đầu tiên
// dp[v][y] = dp[u][x] + 1 với y > x và từ x + 1 -> ycó cạnh tới v
// ans = max(x - dp[n * m][x])