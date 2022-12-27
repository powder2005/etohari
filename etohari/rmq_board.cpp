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
const int MAXM = 2e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, a[MAXN][MAXN], rmq[11][11][MAXN][MAXN];
int q, px, py, type[MAXM], x[MAXM], y[MAXM], z[MAXM];


ll A[MAXN], B[MAXN], C[MAXN], D[MAXN], E[MAXN], F[MAXN];
void input(){
    cin >> n >> q;
    cin >> A[0] >> B[0] >> C[0] >> D[0] >> E[0] >> F[0];
    A[1] = 1 + ((A[0] * A[0]) % MOD);
    B[1] = 1 + ((B[0] * B[0]) % MOD);
    C[1] = 1 + ((C[0] * C[0]) % MOD);
    D[1] = 1 + ((D[0] * D[0]) % n);
    E[1] = 1 + ((E[0] * E[0]) % n);
    F[1] = 1 + ((F[0] * F[0]) % n);

    for (int i = 1; i <= n; i ++){
        A[i] = 1 + (A[i - 1] * A[i - 2]) % MOD;
        B[i] = 1 + (B[i - 1] * B[i - 2]) % MOD;
        C[i] = 1 + (C[i - 1] * C[i - 2]) % MOD;
    }

    for (int i = 1; i <= q; i ++){
        D[i] = 1 + (D[i - 1] * D[i - 2]) % n;
        E[i] = 1 + (E[i - 1] * E[i - 2]) % n;
        F[i] = 1 + (F[i - 1] * F[i - 2]) % n;
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            a[i][j] = (A[i] + B[j]) % MOD;
        }
    }

    for (int i = 1; i <= q; i ++){
        type[i] = C[i] & 1;
        x[i] = D[i];
        y[i] = E[i];
        if (type[i] == 1)z[i] = 1 + ((n - max(D[i], E[i])) & ((n - max(D[i], E[i])) ^ F[i])); 
    }
}
int get(int x, int y, int u, int v){
    int lg1 = log2(u - x + 1);
    int lg2 = log2(v - y + 1);
    return max({
        rmq[lg1][lg2][x][y], rmq[lg1][lg2][u - (1 << lg1) + 1][y],
        rmq[lg1][lg2][x][v - (1 << lg2) + 1], rmq[lg1][lg2][u - (1 << lg1) + 1][v - (1 << lg2) + 1]
    });
}
void init(){
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            rmq[0][0][i][j] = a[i][j];
            rmq[0][0][i][j + n] = a[i][j + n];
            rmq[0][0][i + n][j] = a[i + n][j];            
            rmq[0][0][i + n][j + n] = a[i + n][j + n];

        }
    }

    for (int lgi = 1; lgi < 11; lgi ++){
        for (int lgj = 1; lgj < 11; lgj ++){
            for (int i = 1; i + (1 << lgi) - 1 <= 2 * n; i ++){
                for (int j = 1; j + (1 << lgj) - 1 <= 2 * n; j ++){
                    rmq[lgi][lgj][i][j] = max({
                        rmq[lgi - 1][lgj][i][j], rmq[lgi - 1][lgj][i + (1 << (lgi - 1))][j],
                        rmq[lgi][lgj - 1][i][j], rmq[lgi][lgj - 1][i][j + (1 << (lgj - 1))],
                    });
                }
            }
        }
    }
}
void solve(){
    px = py = 0;

    vector < int > ans;
    for (int i = 1; i <= q; i ++){
        if (type[i] == 1){
            ans.emplace_back((px + x[i], py + y[i], px + x[i] + z[i], py + y[i] + z[i]));
        }else {
            px = (px + x[i]) % n;
            py = (py + y[i]) % n;
        }
    }

    for (int i = 0; i < len(ans); i += 1000){
        int res = 0;
        for (int j = i; j < min(len(ans), i + 1000); j ++){
            res += ans[j];
            res %= MOD;
        }
        cout << res << el;
    }
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    int test = 1;
    // cin >> test;

    for(int i = 1; i <= test; i ++){
        input();
        // init();
        // solve();
    }
    
    return 0;
}
/* 
    Hi I'm Powder
        fb.com/hai290605
            cf: Etohari
                        */
