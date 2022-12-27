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

int n, a[MAXN][MAXN], rmq[11][MAXN][MAXN];
int q, px, py, type[MAXM], x[MAXM], y[MAXM], z[MAXM];


int A[MAXM], B[MAXM], C[MAXM], D[MAXM], E[MAXM], F[MAXM];
void input(){
    cin >> n >> q;
    cin >> A[0] >> B[0] >> C[0] >> D[0] >> E[0] >> F[0];
    A[1] = 1 + ((1ll * A[0] * A[0]) % MOD);
    B[1] = 1 + ((1ll * B[0] * B[0]) % MOD);
    C[1] = 1 + ((1ll * C[0] * C[0]) % MOD);
    D[1] = 1 + ((1ll * D[0] * D[0]) % n);
    E[1] = 1 + ((1ll * E[0] * E[0]) % n);
    F[1] = 1 + ((1ll * F[0] * F[0]) % n);

    for (int i = 2; i <= n; i ++){
        A[i] = 1 + ((A[i - 1] + A[i - 2]) % MOD);
        B[i] = 1 + ((B[i - 1] + B[i - 2]) % MOD);
    }

    for (int i = 2; i <= q; i ++){
        C[i] = 1 + ((C[i - 1] + C[i - 2]) % MOD);
        D[i] = 1 + ((D[i - 1] + D[i - 2]) % n);
        E[i] = 1 + ((E[i - 1] + E[i - 2]) % n);
        F[i] = 1 + ((F[i - 1] + F[i - 2]) % n);
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            a[i][j] = (A[i] + B[j]) % MOD;
        }
    }

    for (int i = 1; i <= q; i ++){
        type[i] = (C[i] & 1) + 1;
        x[i] = D[i];
        y[i] = E[i];
        if (type[i] == 1)z[i] = 1 + ((n - max(D[i], E[i])) & ((n - max(D[i], E[i])) ^ F[i])); 
    }
}
int get(int x, int y, int z){
    int k = log2(z);
    return max({
        rmq[k][x][y],
        rmq[k][x][y + z - (1 << k)],
        rmq[k][x + z - (1 << k)][y],
        rmq[k][x + z - (1 << k)][y + z - (1 << k)]
    });
}
void init(){
    for (int i = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++){
            rmq[0][i][j] = a[i][j];
            rmq[0][i + n][j] = a[i][j];
            rmq[0][i][j + n] = a[i][j];
            rmq[0][i + n][j + n] = a[i][j];
        }
    }

    for (int k = 1; k < 11; k ++){
        for (int i = 1; i + (1 << k) - 1 <= 2 * n; i ++){
            for (int j = 1; j + (1 << k) - 1 <= 2 * n; j ++){
                rmq[k][i][j] = max({
                    rmq[k - 1][i][j],
                    rmq[k - 1][i + (1 << (k - 1))][j],
                    rmq[k - 1][i][j + (1 << (k - 1))],
                    rmq[k - 1][i + (1 << (k - 1))][j + (1 << (k - 1))]
                });
            }
        }
    }
}
void solve(){
    vector < int > ans;
    for (int i = 1; i <= q; i ++){
        if (type[i] == 1){
            ans.emplace_back(get(px + x[i], py + y[i], z[i]));
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
        init();
        solve();
    }
    
    return 0;
}
/* 
    Hi I'm Powder
        fb.com/hai290605
            cf: Etohari
                        */
