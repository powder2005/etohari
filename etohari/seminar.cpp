#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair < int, int >;
using pll = pair < ll, ll >;
using pld = pair < ld, ld >;

template < class T > bool minimum(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template < class T > bool maximum(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

#define el "\n"
#define NAME "seminar"
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

int n, id[MAXN], sa[MAXN], ea[MAXN], sb[MAXN], eb[MAXN], f[MAXN], rmq[21][MAXN];
vector < pii > point;

int get(int l, int r){
    if(l > r)return 0;
    int k = log2(r - l + 1);
    return max(rmq[k][l], rmq[k][r - (1 << k) + 1]);
}
bool solve(){
    point.clear();

    iota(id + 1, id + n + 1, 1);
    sort(id + 1, id + n + 1, [](int i, int j){
        return (sa[i] < sa[j] || (sa[i] == sa[j] && ea[i] < ea[j]));
    });
    
    // for(int i = 1; i <= n; i ++){
    //     cout << sa[id[i]] << " " << ea[id[i]] << " " << sb[id[i]] << " " <<  eb[id[i]] << el;
    // }
    for(int i = 1; i <= n; i ++){
        point.emplace_back(sb[id[i]], - i);
        point.emplace_back(eb[id[i]], i);
    }

    sort(point.begin(), point.end());
    // for(auto [x, p] : point){
    //     cout << x << " " << p << el;
    // }
    for(int i = 0; i < 2 * n; i ++){
        rmq[0][i] = abs(point[i].se);
    }

    for(int j = 1; j <= 20; j ++){
        for(int i = 0; i + (1 << j) - 1 < 2 * n; i ++){
            rmq[j][i] = max(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
        }
    }

    for(int i = 0; i < 2 * n; i ++){
        int x = point[i].fi;
        int p = point[i].se;
        if(p < 0){
            f[-p] = i;
        }else {
            f[p] = get(f[p] + 1, i - 1);
        }
    }

    for(int i = 1; i <= n; i ++){
        if(!f[i])continue;
        if(max(sa[id[i]], sa[f[i]]) <= min(ea[id[i]], ea[f[i]]))continue;
        return true;
    }

    return false;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);

    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
    }

    if(solve()){
        cout << "NO";
        return 0;
    }
    
    for(int i = 1; i <= n; i ++){
        swap(sa[i], sb[i]);
        swap(ea[i], eb[i]);
    }

    if(solve()){
        cout << "NO";
        return 0;
    }

    cout << "YES" ;
    return 0;
}
/* 
    Hi I'm Powder
        fb.com/hai290605
            cf: Etohari
                        */
