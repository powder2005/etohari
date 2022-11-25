#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll base = 119;
const int MAXK = 3000;
int m, n, k;
int x_1[MAXK + 5];
int y_1[MAXK + 5];
int x_2[MAXK + 5];
int y_2[MAXK + 5];
int x[MAXK + 5];
int n_x[MAXK + 5];
int y[MAXK + 5];
int n_y[MAXK + 5];
ll s[MAXK + 5][MAXK + 5];
bool c[MAXK + 5][MAXK + 5];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool ok(int u, int v) { return u > 0 && v > 0 && u <= m && v <= n; }
void dfs(int u, int v) {
    c[u][v] = 1;
    for (int i = 0; i < 4; i++) {
        int u1 = u + dx[i], v1 = v + dy[i];
        if (ok(u1, v1) && c[u1][v1] == 0 && s[u1][v1] == s[u][v]) {
            dfs(u1, v1);
        }
    }
}
int main() {
    freopen("CAKE.INP", "r", stdin);
    freopen("CAKE.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> m >> n && m != 0 && n != 0) {
        cin >> k;
        swap(m, n);
        int lim = 0;
        for (int i = 1; i <= k; i++) {
            cin >> x_1[i] >> y_1[i] >> x_2[i] >> y_2[i];
            if (x_1[i] > x_2[i])
                swap(x_1[i], x_2[i]);
            if (y_1[i] > y_2[i])
                swap(y_1[i], y_2[i]);
            x_1[i]++;
            y_1[i]++;
            // cout<<x_1[i]<<' '<<y_1[i]<<' '<<x_2[i]<<' '<<y_2[i]<<'\n';
            x[++lim] = x_1[i];
            y[lim] = y_1[i];
            x[++lim] = x_2[i];
            y[lim] = y_2[i];

            x[++lim] = x_1[i]+1;
            y[lim] = y_1[i]+1;
            x[++lim] = x_2[i]+1;
            y[lim] = y_2[i]+1;
        }
        x[++lim] = m;
        y[lim] = n;
        x[++lim] = 1;
        y[lim] = 1;
        sort(x + 1, x + lim + 1);
        sort(y + 1, y + lim + 1);
        int limx=0, limy=0;
        for(int i=1; i<=lim; i++){
            n_x[++limx]=x[i];
            while(i<lim && x[i+1]==x[i]) i++;
        }
        for(int i=1; i<=lim; i++){
            n_y[++limy]=y[i];
            while(i<lim && y[i+1]==y[i]) i++;
        }
        ll d = 1;
        for (int i = 1; i <= k; i++) {
            x_1[i]=lower_bound(n_x+1, n_x+limx+1, x_1[i])-n_x;
            x_2[i]=lower_bound(n_x+1, n_x+limx+1, x_2[i])-n_x;
            y_1[i]=lower_bound(n_y+1, n_y+limy+1, y_1[i])-n_y;
            y_2[i]=lower_bound(n_y+1, n_y+limy+1, y_2[i])-n_y;
            s[x_1[i]][y_1[i]] += d;
            s[x_1[i]][y_2[i] + 1] -= d;
            s[x_2[i] + 1][y_1[i]] -= d;
            s[x_2[i] + 1][y_2[i] + 1] += d;
            d *= base;
        }
        m=lower_bound(n_x+1, n_x+limx+1, m)-n_x;
        n=lower_bound(n_y+1, n_y+limy+1, n)-n_y;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] += s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
            }
        }
        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (c[i][j] == 0) {
                    dfs(i, j);
                    res++;
                }
            }
        }
        cout << res << '\n';

        memset(s, 0, sizeof(s));
        memset(c, 0, sizeof(c));
    }
    return 0;
}
