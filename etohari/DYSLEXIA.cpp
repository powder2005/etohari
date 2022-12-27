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
#define NAME "DYSLEXIA"
#define HACKER "ETOHARI"
#define fi first        
#define se second
#define bit(a,b) ((a >> b)&1)
#define countBit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
#define len(s) (int)s.size()
const int MAXN = 1e7 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int MOD_1 = 166666668;
const int INF = 0x3f3f3f3f;

const int d4x[4] = {1, 0, -1, 0}; 
const int d4y[4] = {0, 1, 0, -1};
const int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const char B64[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int position[256];
void initBase64(){
    for (int i = 0; i < 64; i++)
        position[B64[i]] = i;
}

int n;
string S64; 
char S[MAXN];

void b64Conversion(const string &s){
    int ptr = 0;
    for (char c: s){
        int x = position[c];
        for (int i = 0; i < 6; i++){
            S[++ptr] = (x & 1) + '0';
            x >>= 1;
        }
    }
}

ll cal1(const char &x){
    ll cnt = 0, ans = 0;
    for (int i = 1; i <= n; i ++){
        if(S[i] == x)cnt ++;
        else {
            cnt = 0;
        }
        ans += (((((cnt * (cnt + 1)) % MOD) * (2 * cnt + 1)) % MOD) * MOD_1) % MOD;
        ans %= MOD;
    }
    return ans ;
}

ll cal2(){
    ll cnt0 = 0, cnt1 = 0, ans = 0, s0 = 0, s1 = 0, s = 0;
    for (int i = 1; i <= n; i ++){
        cnt0 += S[i] == '0';
        cnt1 += S[i] == '1';
        ans += ((((cnt0 * cnt1) % MOD) * 1ll * i) % MOD) - 
            cnt0 * s1 - cnt1 * s0 + s;
        s0 += cnt0;
        s1 += cnt1;
        s += cnt0 * cnt1;
        s0 %= MOD;
        s1 %= MOD;
        s %= MOD;
        ans %= MOD;
    }

    return ans ;
}
void solve(){
    cin >> n >> S64;
    initBase64(); b64Conversion(S64);

    cout << (cal1('1') + cal1('0') + cal2() + 1ll * MOD * MOD) % MOD ;
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

    (f[n] - f[i]) * (g[n] - g[i])
    f[n] * g[n] - f[i] * g[n] - f[n] * g[i] + f[i] * g[i]
    (n - 1) * f[n] * g[n] - f[n] * (g[1..n - 1]) - g[n] * (f[1..n - 1]) + ()                   */
