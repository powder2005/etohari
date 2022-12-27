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

struct node {
    int Min, Sum, ind; 
} tree[MAXN << 2];

int n, q, add, pos, a[MAXN];

void build(int id, int l, int r){
    if (l == r){
        tree[id].Sum = tree[id].Min = a[l];
        return ;
    }
    int m = l + r >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    tree[id].Sum = tree[id << 1].Sum + tree[id << 1 | 1].Sum;
    tree[id].Min = min(tree[id << 1].Sum, tree[id << 1].Sum + tree[id << 1 | 1].Min);
}
void update(int id, int l, int r, int p){
    if (l == r){
        tree[id].Sum = tree[id].Min = a[p];
        return ;
    }
    int m = l + r >> 1;
    if (p <= m)update(id << 1, l, m, p);
    else update(id << 1 | 1, m + 1, r, p);
    tree[id].Sum = tree[id << 1].Sum + tree[id << 1 | 1].Sum;
    tree[id].Min = min(tree[id << 1].Sum, tree[id << 1].Sum + tree[id << 1 | 1].Min);
}
int get(int id, int l, int r, int p){
    if (p > r)return INF;
    int m = l + r >> 1;
    int ans = get(id << 1, l, m, p);
    if (p <= m) {
        ans = min(ans, add + tree[id << 1 | 1].Min);
        add += tree[id << 1 | 1].Sum;
    }else{
        ans = min(ans, get(id << 1 | 1, m + 1, r, p));
    }
    return ans;
}
void read(){
    string s; cin >> s;
    n = len(s); 

    for (int i = 1; i <= n; i ++){
        a[i] = (s[i - 1] == '(' ? 1 : -1);
    }
}
void solve(){
    cin >> q;
    for (int i = 1; i <= q; i ++){
        char type; cin >> type;
        int id; cin >> id;

        if(type == 'C'){
            a[id] *= -1;
            update(1, 1, n, id);
        }else {
            add = 0;
            pos = id - 1;
            get(1, 1, n, id);
            cout << pos - id + 1 << el;
        }
    }
}   

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    int test = 1;
    // cin >> test;

    for(int i = 1; i <= test; i ++){
        read();
        build(1, 1, n);
        solve();
    }
    
    return 0;
}
/* 
    Hi I'm Powder
        fb.com/hai290605
            cf: Etohari
                        */
