#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
using pld = pair < ld, ld >;
using point = pair < ld, ld >;
using line = pair < point, point >;

template < class T > bool minimum(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool maximum(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define el "\n"
#define NAME "CNTSQR"
#define HACKER "ETOHARI"
#define fi first        
#define se second
#define bit(a,b) ((a >> b)&1)
#define countBit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
#define len(s) (int)s.size()
const int MAXN = 3e6 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int d4x[4] = { 1, 0, -1, 0 };
const int d4y[4] = { 0, 1, 0, -1 };
const int d8x[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int d8y[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

int n, m, nRow, nCol, x[MAXN], y[MAXN], row[MAXN], col[MAXN];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
    }

    for (int i = 1; i <= m; i++) {
        cin >> x[i];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            row[++nRow] = x[j] - x[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            col[++nCol] = y[j] - y[i];
        }
    }

    sort(row + 1, row + nRow + 1);
    sort(col + 1, col + nCol + 1);

    ll res = 0;
    for (int i = 1, p1 = 1, p2 = 1; i <= nRow; i++) {
        while (p1 <= nCol && col[p1] < row[i])p1++;
        while (p2 <= nCol && col[p2] <= row[i])p2++;
        res += p2 - p1;
    }

    cout << res;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    freopen(NAME".inp", "r", stdin);
    freopen(NAME".out", "w", stdout);

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
