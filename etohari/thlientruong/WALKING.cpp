#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
using pld = pair < ld, ld >;
using point = pair < ld, ld > ;
using line = pair < point, point >;

template < class T > bool minimum(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool maximum(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define el "\n"
#define NAME "WALKING"
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

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, l, res, id[MAXN], t[MAXN], v[MAXN], dp[MAXN];

bool check(pll a, pll b){
    if(a == b)return 1;
    ll x = a.fi / a.se;
    ll y = b.fi / b.se;
    if (x > y)return 1;
    if (x < y)return 0;
    if (a.fi == x * a.se)return 0;
    if (b.fi == y * b.se)return 1;
    return !check(make_pair(a.se, a.fi - x * a.se), make_pair(b.se, b.fi - y * b.se));
}
void solve(){
    cin >> l >> n;
    for (int i = 1; i <= n; i ++){
        cin >> t[i] >> v[i];
    }

    iota(id + 1, id + n + 1, 1);
    sort(id + 1, id + n + 1, [](int i, int j){
        return t[i] < t[j];
    });

    for (int i = 1; i <= n; i ++){
        dp[i] = 1;
        for (int j = 1; j < i; j ++){
            ll a = 1ll * t[id[i]] * v[id[i]] + l;
            ll b = v[id[i]];
            ll c = 1ll * t[id[j]] * v[id[j]] + l;
            ll d = v[id[j]];
            if(!check(make_pair(a / __gcd(a, b), b / __gcd(a, b)),
                 make_pair(c / __gcd(c, d), d / __gcd(c, d))))maximum(dp[i], dp[j] + 1);
        }
        maximum(res, dp[i]);
    }

    cout << res ;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

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
