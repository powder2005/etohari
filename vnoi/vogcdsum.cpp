#include<bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define fi first
#define se second
#define N 100005
#define NMOD 2
typedef long long ll;

const int MOD[] = {int(1e9) + 2277, int(1e9) + 5277, int(1e9) + 8277, int(1e9) + 9277};
const int BASE = 256;

ll pw[NMOD][N];
struct Hash {
    ll value[NMOD];

    Hash(char c = 0) {
        for (int i = 0; i < NMOD; ++i)
            value[i] = c;
    }

    Hash operator + (const Hash &x) const {
        Hash res;
        for (int i = 0; i < NMOD; ++i) {
            res.value[i] = value[i] + x.value[i];
            if(res.value[i] >= MOD[i])
                res.value[i] -= MOD[i];
        }

        return res;
    }

    Hash operator - (const Hash &x) const {
        Hash res;
        for (int i = 0; i < NMOD; ++i) {
            res.value[i] = value[i] - x.value[i];
            if(res.value[i] < 0)
                res.value[i] += MOD[i];
        }

        return res;
    }

    Hash operator * (int k) const {
        Hash res;
        for (int i = 0; i < NMOD; ++i)
            res.value[i] = value[i] * pw[i][k] % MOD[i];

        return res;
    }

    bool operator == (const Hash &h) const {
        for (int i = 0; i < NMOD; ++i)
            if(value[i] != h.value[i])
                return false;

        return true;
    }

    bool operator < (const Hash &h) const {
        for (int i = 0; i < NMOD; ++i)
            if(value[i] != h.value[i])
                return value[i] < h.value[i];

        return false;
    }
};

vector<vector<Hash>> h;
vector<int> len;
int idx[N], n, maxlen;

void prepare() {
    for (int i = 0; i < NMOD; ++i) {
        pw[i][0] = 1;
        for (int j = 1; j < N; ++j)
            pw[i][j] = pw[i][j - 1] * BASE % MOD[i];
    }
}

Hash getHash(int it, int l, int r) {
    return (h[it][r] - h[it][l - 1]) * (maxlen - r);
}

typedef pair<Hash, int> hi;
vector<hi> cod;

bool check(int x) {
    cod.clear();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j + x - 1 <= len[i]; ++j) {
            cod.push_back({getHash(i, j, j + x - 1), i});
        }

        idx[i] = 0;
    }

    sort(cod.begin(), cod.end());

    Hash h(0);
    int d(0), id(0);
    for (auto &[hasht, idxt] : cod) {
        if(hasht == h) {
            if(idx[idxt] != id)
                idx[idxt] = id, ++d;
        } else {
            if(d >= n)
                break;

            h = hasht;
            d = 1;
            idx[idxt] = ++id;
        }
    }

    return (d >= n);
}

void process() {
    string s;
    prepare();

    h.push_back(vector<Hash>());
    len.push_back(0);

    int minlen(1e9);
    while(getline(cin, s)) {
        h.push_back(vector<Hash>());
        len.push_back(int(s.length()));
        ++n;

        minlen = min(minlen, len[n]);
        maxlen = max(maxlen, len[n]);

        h[n].push_back(Hash(0));
        for (int i = 0; i < len[n]; ++i) {
            h[n].push_back(h[n][i] + Hash(s[i]) * (i + 1));
        }
    }

    int l(1), r(minlen), ans(0);
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    process();
    return 0;
}