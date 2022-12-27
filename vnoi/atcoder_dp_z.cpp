#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
using pld = pair < ld, ld >;
using point = pair < ld, ld > ;

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

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

struct line{
    ll a, b;
    line (ll _a = 0, ll _b = 1ll * INF * INF) : a(_a), b(_b) {}
    ll operator () (ll x) { return a * x + b; }
} tree[4 * MAXN];
int n, h[MAXN];
ll c, dp[MAXN];

void update(int id, int l, int r, line x){
    if(l == r){
        if(x(l) < tree[id](l))tree[id] = x;
        return ;
    }
    int m = l + r >> 1;
    if(tree[id].a > x.a)swap(tree[id], x);
    if(x(m) < tree[id](m)){
        swap(x, tree[id]);
        update(id << 1 | 1, m + 1, r, x);
    }else{
        update(id << 1, l, m, x);
    }
}

ll get(int id, int l, int r, int p){
    if(l > p || p > r)return 1ll * INF * INF;
    if(l == r)return tree[id](p);
    int m = l + r >> 1;
    return min({tree[id](p), get(id << 1, l, m, p), get(id << 1 | 1, m + 1, r, p)});

}
void solve(){
    cin >> n >> c;
    for (int i = 1; i <= n; i ++){
        cin >> h[i] ;
    }

    /*
        dp[i] = dp[j] + (h[i] - h[j]) ^ 2 + C;
        dp[i] = dp[j] + h[i] ^ 2 - 2 * h[i] * h[j] + h[j] * h[j] + C;
        dp[i] = dp[j] + -2 * h[j] * x + h[j] * h[j] + b;

    */
    for (int i = 2; i <= n; i ++){
        update(1, 1, MAXN - 1,  line(- 2 * h[i - 1], 1ll * h[i - 1] * h[i - 1] + dp[i - 1]));
        dp[i] = get(1, 1, MAXN - 1, h[i]) + 1ll * h[i] * h[i] + c;
    }

    cout << dp[n] ;
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
