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
#define NAME "ORDER"
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

void solve(){
    int type;
    cin >> type;
    if(type == 1){
        ll p, q, n = 0;
        cin >> p >> q;
        for(int i = 0; i <= 63; i ++){
            if(p == q){
                n += (1ll << i);
                break;
            }else if(p > q){
                p -= q;
                n += (1ll << i);
            }else {
                q -= p;
            }
        }
        cout << n << el;
    }else {
        ll p = 1, q = 1, n;
        cin >> n;
        for(int i = log2(n) - 1; i >= 0; i --){
            if(bit(n, i)){
                p = p + q;
            }else {
                q = p + q;
            }
        }
        cout << p << " " << q << el;
    }

}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    
    int test = 1;
    cin >> test;

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
    