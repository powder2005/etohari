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
#define NAME "MINFACT"
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

int a, k, minPrime[MAXN];
vector < pii > prime;
void init(){
    for(int i = 2; i < MAXN; i ++){
        if(minPrime[i] == 0){
            for(int j = i; j < MAXN; j += i){
                if(minPrime[j] == 0)minPrime[j] = i;
            }
        }
    }
}
inline vector < pii > primeNumber(int n){
    vector < pii > prime;
    while(n > 1){
        prime.emplace_back(minPrime[n], 1);
        while(minPrime[n] == minPrime[n / minPrime[n]]){
            n /= minPrime[n];
            prime.back().se ++;
        }
        n /= minPrime[n];
    }
    return prime;
}
inline bool check(ll n){
    for(const auto &[a, b] : prime){
        ll cnt = 0, x = n;
        while(x > 0){
            cnt += x / a;
            x /= a;
        }
        if(cnt < k * b)return false;
    }
    return true;
}
inline ll get(){
    prime = primeNumber(a);
    ll ans = 1;
    for(ll bot = 1, top = 1e12; bot <= top; ){
        ll mid = (bot + top) >> 1;
        if(check(mid)){
            ans = mid;
            top = mid - 1;
        }else bot = mid + 1;
    }
    return ans ;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    freopen(NAME".inp", "r", stdin);
    freopen(NAME".out", "w", stdout);

    init();

    int test = 1;
    cin >> test;

    for(int i = 1; i <= test; i ++){
        cin >> a >> k;
        cout << get() << el;
    }
    
    return 0;
}
/* 
    Hi I'm Powder
        fb.com/hai290605
            cf: Etohari
                        */
