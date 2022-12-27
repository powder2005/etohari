#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int LG = 19;

#define all(x) (x).begin(), (x).end()
template <class T>
struct Compressor {
    vector <T> val;

    void add(T x) {
        val.push_back(x);
    }

    void init() {
        sort(all(val));
        val.resize(unique(all(val)) - val.begin());
    }

    int idx(T x) {
        return lower_bound(all(val), x) - val.begin() + 1;
    }
};

struct ST {
    int st[8 * N];
    int lazy[8 * N];
    int n;

    ST(int sz = 0) {
        n = sz;
    }

    void push(int id, int l, int r) {
        for (int i = (id << 1); i <= (id << 1 | 1); i++) {
            st[i] += lazy[id];
            lazy[i] += lazy[id];
        }

        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, int val) {
        if (v < l || r < u)
            return;
        if (u <= l && r <= v) {
            st[id] += val;
            lazy[id] += val;
            return;
        }
        int mid = (l + r) >> 1;
        push(id, l, r);
        update(id << 1, l, mid, u, v, val);
        update(id << 1 | 1, mid + 1, r, u, v, val);
        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }

    int get(int id, int l, int r, int u, int v) {
        if (v < l || r < u)
            return 0;
        if (u <= l && r <= v)
            return st[id];
        int mid = (l + r) >> 1;
        push(id, l, r);
        return max(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }
};

int n, q;
pair <int, int> a[N];
Compressor <int> cps;
ST st;
int f[LG][N];

void read_input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    cin >> q;
}

void compress() {
    for (int i = 1; i <= n; i++) {
        cps.add(a[i].first);
        cps.add(a[i].second);
    }
    cps.init();
    for (int i = 1; i <= n; i++) {
        a[i].first = cps.idx(a[i].first);
        a[i].second = cps.idx(a[i].second);
    }
}

void build() {
    int lim = cps.val.size();
    st = ST(lim);
    for (int i = 1, j = 1; i <= n; i++) {
        st.update(1, 1, lim, a[i].first, a[i].second, 1);
        while (j <= i && st.st[1] > 1) {
            st.update(1, 1, lim, a[j].first, a[j].second, -1);
            j++;
        }
        f[0][i] = j - 1;
    }

    for (int k = 1; k < LG; k++)
        for (int i = 0; i <= n; i++)
            f[k][i] = f[k - 1][f[k - 1][i]];

    while (q--) {
        int u, v;
        cin >> u >> v;

        int ans = 0;

        for (int k = LG - 1; k >= 0; k--) {
            if (f[k][v] >= u) {
                v = f[k][v];
                ans += (1 << k);
            }
        }

        cout << ans + (u <= v) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    read_input();
    compress();
    build();

    return 0;
}