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
using point = pair < ld, ld >;
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
const int MAXN = 1e3 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int d4x[4] = { 1, 0, -1, 0 };
const int d4y[4] = { 0, 1, 0, -1 };
const int d8x[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int d8y[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

int R, C, res;
char a[MAXN][MAXN];
queue < pii > qe1, qe2;
bool check[MAXN][MAXN];

void solve() {
    cin >> R >> C;
    for (int row = 1; row <= R; row++) {
        for (int col = 1; col <= C; col++) {
            cin >> a[row][col];
        }
    }

    for (qe1.emplace(1, 1), check[1][1] = true; !qe1.empty(); ) {
        res++;
        // cerr << res << el;
        for (auto [rootX, rootY] = qe1.front(); !qe1.empty(); qe1.pop()) {
            auto [x, y] = qe1.front();
            for (int i = 0; i < 4; i++) {
                int newX = x + d4x[i];
                int newY = y + d4y[i];
                if (newX < 1 || newX > R || newY < 1 || newY > C)continue;
                if (check[newX][newY] || a[newX][newY] == '*')continue;
                check[newX][newY] = true;

                if (a[rootX][rootY] == a[newX][newY]) {
                    qe1.emplace(newX, newY);
                }
                else {
                    qe2.emplace(newX, newY);
                }
            }
            // cerr  << a[x][y] << " " <<  x << " " << y << el;
        }

        for (; !qe2.empty(); qe2.pop()) {
            // cerr << qe2.front().fi << " " << qe2.front().se << el;
            qe1.emplace(qe2.front());
        }
    }

    cout << res;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int test = 1;
    // cin >> test;

    for (int i = 1; i <= test; i++) {
        solve();
    }

    return 0;
}
/*
    Hi I'm Powder
        fb.com/hai290605
            cf: Etohari
                        */
