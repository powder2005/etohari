// Code mely
// quy hoạch động cái túi cơ bản phiên bản đệ qui có nhớ

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1e3 + 10;
const int MAXM = 1e3 + 10;

int n, m, w[MAXN], v[MAXN], f[MAXN][MAXM];

int dp(int n, int m){
    if (m < 0) return INT_MIN;
    if (n < 1) return 0;
    if (f[n][m] != -1) return f[n][m];
    f[n][m] = max(dp(n - 1, m), dp(n - 1, m - w[n]) + v[n]);
    return f[n][m];
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> w[i] >> v[i];
    }   

    memset(f, -1, sizeof f);

    int answer = dp(n, m);
    cout << answer << "\n";

    return 0;
}