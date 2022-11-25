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
#define NAME "ROBOT"
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

int n, m, p, k, nxt[111111][26];
string s, base;
map < int, int > dist[MAXN];
bool check[MAXN][MAXN];

int get(int i, int j){
    return (i - 1) * m + j;
}
void solve(){
    cin >> n >> m >> p >> k >> s;
    s = '$' + s;

    base = "DRUL";

    for(char ch : base){
        nxt[k + 1][ch - 'A'] = k + 1;
    }

    for(int i = k; i >= 1; i --){
        for(char ch : base){
            nxt[i][ch - 'A'] = nxt[i + 1][ch - 'A'];
        }
        nxt[i][s[i] - 'A'] = i;
    }

    for(int i = 1; i <= p; i ++){
        int x, y; cin >> x >> y;
        check[x][y] = true;
    }

    set < tuple < int, int, int > > qe;
    for(dist[get(1, 1)][0] = 0, qe.insert({0, 1, 1}); !qe.empty(); ){
        int d = get < 0 > (*qe.begin());
        int x = get < 1 > (*qe.begin());
        int y = get < 2 > (*qe.begin());

        qe.erase(qe.begin());

        for(int i = 0; i < 4; i ++){
            int newX = x + d4x[i];
            int newY = y + d4y[i];
            if(newX < 1 || newX > n || newY < 1 || newY > m)continue;
            if(check[newX][newY]) continue;

            int newNext = nxt[d + 1][base[i] - 'A'];
            if(newNext > k)continue;

            if(!dist[get(newX, newY)].count(newNext)){
                dist[get(newX, newY)][newNext] = dist[get(x, y)][d] + 1;
                qe.insert({newNext, newX, newY});
            }else {
                minimum(dist[get(newX, newY)][newNext], dist[get(x, y)][d] + 1);
            }
        }
    }

    int res = -1;
    
    for(pii pr : dist[get(n, m)]){
        res = max(res, k - pr.se);
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
// dp[u][x] là cách it đến được ô u với x ô đầu tiên
// dp[v][y] = dp[u][x] + 1 với y > x và từ x + 1 -> ycó cạnh tới v
// ans = max(x - dp[n * m][x])