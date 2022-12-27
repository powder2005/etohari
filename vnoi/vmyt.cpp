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
const int MAXN = 1e6 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7 - 1;
const int INF = 0x3f3f3f3f;

const int d4x[4] = { 1, 0, -1, 0 };
const int d4y[4] = { 0, 1, 0, -1 };
const int d8x[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int d8y[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

class matrix {
public:
    vector < vector < long long > > data;

    int row() const { return len(data); }
    int col() const { return len(data[0]); }

    auto& operator [] (const int& i) { return data[i]; }

    matrix() = default;
    matrix(const int& r, const int& c): data(r, vector < long long >(c, 0)) { }
    matrix(const vector < vector < long long > >& d): data(d) { }

    static matrix identity(int n) {
        matrix a = matrix(n, n);
        while (n--) a[n][n] = 1;
        return a;
    }

    matrix operator * (matrix& b) {
        matrix a = *this;
        assert(a.col() == b.row());

        matrix c(a.row(), b.col());
        for (int i = 0; i < a.row(); i++) {
            for (int j = 0; j < b.col(); j++) {
                for (int k = 0; k < a.col(); k++) {
                    c[i][j] += a[i][k] * b[k][j];
                    c[i][j] %= MOD;
                }
            }
        }

        return c;
    }

    matrix pow(long long exp) {
        assert(row() == col());

        matrix base = *this, ans = identity(row());
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
    }

};

ll mult(ll a, ll b) {
    ll ans = 1;
    for (;b > 0; b >>= 1, a = (a * a) % (MOD + 1)) {
        if (b & 1)ans = (ans * a) % (MOD + 1);
    }
    return ans;
}
void solve() {
    int n, k; cin >> n >> k;

    vector < long long > a(k);
    for (auto& x : a)cin >> x;

    matrix base(k, k);
    for (int i = 0; i < k; i ++){
        base[0][i] = 1;
    }
    for (int i = 1; i < k; i ++){
        base[i][i - 1] = 1;
    }
    base = base.pow(n - k);
    
    ll res = 1;
    for (int i = 0; i < k; i++) {
        res = res * mult(a[k - i - 1], base[0][i]);
        res %= (MOD + 1);
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
