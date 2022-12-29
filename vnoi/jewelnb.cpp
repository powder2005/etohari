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
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

const int d4x[4] = { 1, 0, -1, 0 };
const int d4y[4] = { 0, 1, 0, -1 };
const int d8x[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int d8y[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };

class li_chao_tree_t {
public:
    inline static vector < int64_t > query_point;

    class line_t {
    public:
        int64_t a, b;
        int64_t operator () (const int64_t& x) const { return a * x + b; }
        line_t() = default;
        line_t(const int64_t& _a, const int64_t& _b): a(_a), b(_b) {};
    };

    li_chao_tree_t* left, * right;
    int64_t l, r, m;
    line_t line;

    li_chao_tree_t(int32_t l = 0, int32_t r = query_point.size() - 1) {
        this->l = query_point[l];
        this->r = query_point[r];
        int32_t m = (l + r) / 2;
        this->m = query_point[m];
        if (l != r) {
            left = new li_chao_tree_t(l, m);
            right = new li_chao_tree_t(m + 1, r);
        }
        line.a = 0;
        line.b = 0;
    }

    int64_t get(const int64_t& x) {
        if (l == r) {
            return line(x);
        }
        else if (m >= x) {
            return max(line(x), left->get(x));
        }
        else {
            return max(line(x), right->get(x));
        }
    }

    void update(const int64_t& a, const int64_t& b, const int32_t& u, const int32_t& v) {
        if (v < l || u > r) return;
        line_t new_line(a, b);
        bool check_l = new_line(l) >= line(l);
        bool check_r = new_line(r) >= line(r);
        if (u <= l && r <= v && check_l && check_r) {
            line = new_line;
        }
        else if (check_l || check_r) {
            left->update(a, b, u, v);
            right->update(a, b, u, v);
        }

    }
};

int32_t n, m, s[MAXN], e[MAXN], v[MAXN], d[MAXN];
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> s[i] >> e[i] >> v[i] >> d[i];
    }

    li_chao_tree_t::query_point.resize(n + 1, 0);
    iota(li_chao_tree_t::query_point.begin(), li_chao_tree_t::query_point.end(), 0);
    li_chao_tree_t* tree = new li_chao_tree_t();

    for (int i = 1; i <= m; i++) {
        tree->update(d[i], -1ll * s[i] * d[i] + v[i], s[i], e[i]);
    }

    for (int i = 1; i <= n; i++) {
        cout << tree->get(i) << el;
    }

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
