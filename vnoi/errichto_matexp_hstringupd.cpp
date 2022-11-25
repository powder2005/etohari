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
const int MAXN = 8e5 + 10;
const int MAXM = 1e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int d4x[4] = {1, 0, -1, 0}; 
int d4y[4] = {0, 1, 0, -1};
int d8x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int d8y[8] = {1, 1, 0, -1, -1, -1, 0, 1};

class matrix {
    public:
        vector < vector < long long > > data;

        int row() const { return len(data); }
        int col() const { return len(data[0]); }

        auto & operator [] (const int &i) { return data[i]; }
        
        matrix () = default;
        matrix (const int &r, const int &c) : data(r, vector < long long > (c, 0)){ }
        matrix (const vector < vector < long long > > &d) : data(d){ }

        matrix operator * (matrix &b) {
            matrix a = *this;
            assert(a.col() == b.row()); 

            matrix c(a.row(), b.col());
            for(int i = 0; i < a.row(); i ++){
                for(int j = 0; j < b.col(); j ++){
                    for(int k = 0; k < a.col(); k ++){
                        c[i][j] += a[i][k] * b[k][j];
                        c[i][j] %= MOD;
                    }
                }
            }

            return c;
        }
        
        void init(const char &match){
            data = {
                {0, 0},
                {0, 0}
            };
            for(char ch = 'A'; ch <= 'Z'; ++ch) {
                if(match == '?' || ch == match) {
                    if(ch == 'H') {
                        data[0][1]++;
                        data[1][1]++;
                    }
                    else if(ch == 'S' || ch == 'D') {
                        data[0][0]++;
                        data[1][0]++;
                    }
                    else if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'U' || ch == 'O') {
                        data[0][1]++;
                        data[1][0]++;
                    }
                    else {
                        data[0][0]++;
                        data[1][1]++;
                    }
                }
            }
        }
};

int n, q, base;
string s;
matrix tree[MAXN];

void solve(){
    cin >> n >> q >> s;
    
    for( base = 1; base < n; base *= 2);

    for(int i = 0; i < n; ++i) {
        tree[base+i].init(s[i]);
    }

    for(int i = n; i < base; ++i) {
        tree[base+i].init('Z'); 
    }

    for(int i = base - 1; i >= 1; -- i){
        tree[i] = tree[i * 2] * tree[i * 2 + 1];
    }

    cout << tree[1][1][1] << el;
    
    while(q--){
        int id; cin >> id;
        char val; cin >> val;
        id --;

        tree[base + id].init(val);
        for(int i = (base + id) / 2; i >= 1; i /= 2){
            tree[i] = tree[i * 2] * tree[i * 2 + 1];
        }
    
        cout << tree[1][1][1] << el;
    }
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
