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

int n, m, a[MAXN][MAXN];

ll Hash, fHash[MAXN][MAXN];

bool visited[MAXN][MAXN];

vector < pii > distDfs;

unordered_map < ll, bool > f;

void dfs(int i, int j){
    visited[i][j] = true;
    distDfs.emplace_back(i, j);
    
    for(int d = 0; d < 4; d ++){
        int x = i + d4x[d];
        int y = j + d4y[d];
        if(a[x][y] && !visited[x][y]){
            dfs(x, y);
        }
    }
}
void mirror_horizontal() {
  for (auto &p : distDfs) {
    int &j = p.se;
    j = -j;
  }
}

void mirror_vertical() {
  for (auto &p : distDfs) {
    int &i = p.fi;
    i = -i;
  }
}

void mirror_diagonal() {
  for (auto &p : distDfs) {
    int &i = p.fi,
        &j = p.se;
    swap(i, j);
  }
}

ll getHash(){
    int minX = INF;
    int minY = INF;

    for(auto [x, y] : distDfs){
        minX = min(minX, x);
        minY = min(minY, y);
    }

    ll Hash = 0;
    for(auto [x, y] : distDfs){
        Hash += fHash[x - minX][y - minY];
    }
    
    return Hash;
}
void solve(){
    srand(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < max(n, m); i ++){
        for(int j = 0; j < max(n, m); j ++){
            fHash[i][j] = 1ll * rand() * rand() * rand() * rand() * rand() * rand();
        }
    }

    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(a[i][j] && !visited[i][j]){
                distDfs.clear();
                dfs(i, j);

                if (f[getHash()]) continue;

                mirror_horizontal();
                if (f[getHash()]) continue;      

      
                f[getHash()] = true;
            
        }
    }

    cout << len(f) << el;
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
