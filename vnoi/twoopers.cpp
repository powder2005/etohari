#include "bits/stdc++.h"

using namespace std;

#define el "\n"
#define LL long long
#define name "ETOHARI"
#define hacker "ETOHARI"
#define fi first        
#define se second
#define bit(a,b) ((a >> b)&1)
#define countBit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
#define len(s) (int)s.size()
#define int long long
const int maxn = 1e6 + 10;
const int maxm = 1e6 + 10;
const int mod = 1e9 + 7;
const int inf = 999999999;
const int base = 811;

int n, mul[maxn], hashT[maxn], hashS[maxn];
string s, t;
long long res;
int getHash(int HASH[], int l, int r){
    return (1LL * HASH[r] - 1LL * HASH[l - 1] * mul[r - l + 1] + 1LL * mod * mod) % mod;
}
signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    cin >> s >> t;
    n = len(s);
    s = '#' + s;
    t = '#' + t + t;
    
    mul[0] = 1;
    for(int i = 1; i < maxn; i ++){
        mul[i] = (1LL * mul[i - 1] * base) % mod;
    }
    
    for(int i = 1; i <= n; i ++){
        hashS[i] = (1LL * hashS[i - 1] * base + s[i]) % mod;
    }
    
    for(int i = 1; i < 2 * n; i ++){
        hashT[i] = (1LL * hashT[i - 1] * base  + t[i]) % mod;
    }

    for (int k = 0; k < n; k ++){
        if (hashS[n] == getHash(hashT, k + 1, k + n)){
            res += n;
        }else{
            int pos = 0;
            for (int l = 1, r = n; l <= r; ){
                int m = l + r >> 1;
                if (getHash(hashS, 1, m) == getHash(hashT, 1 + k, m + k)){
                    pos = m;
                    l = m + 1;
                }else{
                    r = m - 1;
                }
            }
            res += getHash(hashS, pos + 2, n) == getHash(hashT, pos + 2 + k, n + k);
        }
    }

    cout << res;
    return 0;
}
/* Hi I'm Powder */
