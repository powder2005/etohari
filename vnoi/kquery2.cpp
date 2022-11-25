#include "bits/stdc++.h"

using namespace std;

#define el "\n"
#define LL long long
#define name "ETOHARI"
#define hacker "ETOHARI"
#define fi first        
#define se second
#define flush cout.flush()
#define bit(a,b) ((a >> b)&1)
#define countBit(a) __builtin_popcount(a)
#define sum(l,r,val) accumulate(l,r,val)
const int maxn = 1e4 + 10;
const int maxm = 5e3 + 10;
const int mod = 1e9 + 7;
const int inf = 999999999;
const int blockSize = 555;
int n, q, a[maxn * 4], BIT[blockSize][maxn + 1];
void input() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}
void update(int t, int index, int val) {
    for (;index > 0; index -= (-index) & index)
        BIT[t][index] += val;
}
int get(int t, int index) {
    int ans = 0;
    for (;index < maxn; index += (-index) & index)
        ans += BIT[t][index];
    return ans;
}
void build() {
    for (int i = 1; i <= n; i++)
        update(i / blockSize, a[i], 1);
}
void updateQuery(int p, int x) {
    update(p / blockSize, a[p], -1);
    a[p] = x;
    update(p / blockSize, a[p], 1);
}
int getQuery(int l, int r, int k) {
    int res = 0;
    int blockL = l / blockSize + 1;
    int blockR = r / blockSize;
    if (blockL >= blockR) {
        for (int i = l; i <= r; i++)
            res += a[i] > k;
    }
    else {
        for (int i = blockL; i < blockR; i++)
            res += get(i, k + 1);
        for (int i = l; i < blockL * blockSize; i++)
            res += a[i] > k;
        for (int i = blockR * blockSize; i <= r; i++)
            res += a[i] > k;
    }
    return res;
}
void solve() {
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type) {
            int l, r, k;
            cin >> l >> r >> k;
            cout << getQuery(l, r, k) << el;
        }
        else {
            int p, x;
            cin >> p >> x;
            updateQuery(p, x);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    build();
    solve();

    return 0;
}
/*
Boy one champ Jinx
fb: Hà Lộc Hải
cf: Etohari
*/
