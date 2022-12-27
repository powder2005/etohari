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

string s, t;
int n, m, dp[MAXN][MAXN], nxtS[MAXN][26], nxtT[MAXN][26];

vector < string > res;

void build(string str, int nxt[MAXN][26]){
    for (int j = 0; j < 26; j ++){
        nxt[len(str)][j] = len(str);
    }

    for (int i = len(str) - 1; i >= 1; i --){
        for (int j = 0; j < 26; j ++){
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][str[i] - 'a'] = i;
    }
}
void trace(int x, int y, string cur){
    if (dp[x][y] <= 1){
        res.emplace_back(cur);
        return ;
    }

    for (int i = 0; i < 26; i ++){
        if (dp[nxtS[x + 1][i]][nxtT[y + 1][i]] + 1 == dp[x][y]){
            trace(nxtS[x + 1][i], nxtT[y + 1][i], cur + string(1, i + 'a'));
        }
    }
}
void solve(){
    cin >> s >> t;

    n = len(s);
    m = len(t);
     
    s = '#' + s;
    t = '$' + t;

    build(s, nxtS);
    build(t, nxtT);

    for (int i = n; i >= 1; i --){
        for (int j = m; j >= 1; j --){
            if (s[i] == t[j]){
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    for (int i = 0; i < 26; i ++){
        if (dp[nxtS[1][i]][nxtT[1][i]] == dp[1][1]){
            trace(nxtS[1][i], nxtT[1][i], string(1, i + 'a'));
        }
    }

    cout << len(res) << el;
    for(const string &p : res){
        cout << p << el;
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
