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
const int maxn = 1e5 + 10;
const int maxm = 1e6 + 10;
const int mod = 1e9 + 7;
const int inf = 999999999;

int n, root, COUNT, p[maxn], res[maxn], tree[maxn], START[maxn], END[maxn];
vector < int > adj[maxn];
void dfs(int u, int p) {
    START[u] = ++COUNT;
    for (auto v : adj[u])
        if (v != p) {
            dfs(v, u);
        }
    END[u] = COUNT;
}
void update(int index, int val) {
    for (; index <= n; index += (-index) & index)
        tree[index] = (tree[index] + val) % mod;
}
int get(int index) {
    int ans = 0;
    for (;index > 0; index -= (-index) & index)
        ans = (ans + tree[index]) % mod;
    return ans;
}
int getRange(int l, int r) {
    return (get(r) - get(l - 1) + mod) % mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen(name".inp", "r")) {
        freopen(name".inp", "r", stdin);
        freopen(name".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        if (p[i] == 0)root = i;
        else {
            adj[i].push_back(p[i]);
            adj[p[i]].push_back(i);
        }
    }
    dfs(root, 0);
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        if (a != root) {
            update(START[p[a]], getRange(START[a], END[a]) + 1);
        }
        res[a] = getRange(START[a], END[a]) + 1;
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << el;
    return 0;
}
/* is Powder */
