#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
using pld = pair < ld, ld >;
using point = pair < ld, ld > ;
using line = pair < point, point >;
using pil = pair < int, ll > ;

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

int n, h, x[MAXN], y[MAXN], dist[MAXN];

ll get(int u, int v){
    if(u < v)swap(u, v);
    if(u == 0 && v == n + 1)return 1ll * h * h;

}
void solve(){
    cin >> n >> h;

    for(int i = 1; i <= n; i ++){
        cin >> x[i] >> y[i];
    }   

    priority_queue < pii, vector < pii >, greater < pii > >  qe;
    for(qe.push({0, 0}); !qe.empty(); ){
        int u = qe.top().se;
        int du = qe.top().fi;
        qe.pop();

    }

    cout << (ll)sqrt(dist[n + 1]);
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
    
