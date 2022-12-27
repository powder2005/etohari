// Code mely
// quy hoạch động cái túi cơ bản
#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1e3 + 10;
const int MAXM = 1e3 + 10;

int n, m, w[MAXN], v[MAXN], dp[MAXN][MAXM];

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i ++){
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i ++){
        for (int j = 0; j <= m; j ++){
            if (j >= w[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int answer = dp[n][m];
    cout << answer << "\n";

    return 0;
}