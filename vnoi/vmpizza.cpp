#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;

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

int d4x[4] = {1, 0, -1, 0}; 
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

struct line{
    ll a, b;
    line(ll _a = 0, ll _b = 0){
        a = _a;
        b = _b;
    }
    ll operator () (const ll &x) { return a * x + b; }
} tree[MAXN];
int n, B, t[MAXN], a[MAXN], b[MAXN], id[MAXN];
ll s[MAXN], f[MAXN], g[MAXN], dp[MAXN];

void update(int id, int l, int r, line val){
    if(l == r){
        if(val(l) > tree[id](l)) tree[id] = val;
        return ;
    }
    int m = (l + r) / 2;
    if(tree[id].a > val.a)swap(val, tree[id]);
    if(val(m) > tree[id](m)){
        swap(val, tree[id]);
        update(id * 2, l, m, val);
    }else{
        update(id * 2 + 1, m + 1, r, val);
    }
}

ll get(int id, int l, int r, int p){
    if(p < l || p > r)return -1e18;
    if(l == r)return tree[id](p);
    int m = (l + r) / 2;
    ll ans = tree[id](p);
    return max({ans, get(id * 2, l, m, p), get(id * 2 + 1, m + 1, r, p)});
}
void solve(){
    cin >> n >> B;

    for(int i = 1; i <= n; i ++){
        cin >> t[i] >> a[i] >> b[i];
        id[i] = i;
    }

    sort(id + 1, id + n + 1, [](int i, int j){
        return t[i] < t[j];
    });
    
    for(int i = 1; i <= n; i ++){
        s[i] = s[i - 1] + b[id[i]];
        f[i] = f[i - 1] + 1ll * b[id[i]] * t[id[i]];
        g[i] = g[i - 1] + a[id[i]];
    } 
    /*
        dp[i] = dp[j] + (g[i] - g[j]) - ( (t[i] - t[j + 1]) * b[j + 1] + .. + ) - B;
              = g[i] - t[i] * (s[i] - s[j]) + f[i] - f[j] + dp[j] - g[j] - B;
              = g[i] - t[i] * s[i] + f[i] + t[i] * s[j] - f[j] + dp[j] - g[j] - B;
    for(int i = 1; i <= n; i ++){
        dp[i] = -1e18;
        for(int j = 0; j < i; j ++){
            maximum(dp[i], g[i] - t[id[i]] * s[i] + f[i] + t[id[i]] * s[j] - f[j] + dp[j] - g[j] - B);
        }
    }
    */

    for(int i = 1; i <= n; i ++){
        dp[i] = get(1, 1, 1e5, t[id[i]]) + g[i] - t[id[i]] * s[i] + f[i] - B;
        update(1, 1, 1e5, line(s[i], dp[i] - g[i] - f[i]));
    }

    cout << dp[n] << el;
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
