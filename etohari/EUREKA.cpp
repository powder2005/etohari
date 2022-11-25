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
const int MOD = 123456789;
const int INF = 0x3f3f3f3f;

int d4x[4] = {1, 0, -1, 0}; 
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int n, a[MAXN];
vector < int > prime;
vector < vector < int > > st;
void init(){
    for(int i = 2; i <= 200; i ++){
        bool ok = false;
        for(int j = 2; j * j <= i; j ++){
            if(i % j == 0){
                ok = true;
                break;
            }
        }
        if(!ok)prime.emplace_back(i);
    }
    for(auto x : prime)cout << x << " ";
}
auto operator * (const vector < int > &p){

}

void solve(){
    cin >> n;
    for(int i = 1; i <= 3 * n + 1; i ++){
        cin >> a[i];
    }

    for(int i = 3 * n + 1; i >= 1; i --){
        if(a[i] < 0)st.emplace_back(vector < int > (46, 0));
        else if(a[i] > 0 && a[i - 1] > 0){
            int p = a[i], q = a[i - 1];
        }
    }

    cout << cal(st[0]) ;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    init();
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
