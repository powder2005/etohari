// Code mely
// quy hoạch động cái túi cơ bản phiên bản tối ưu bộ nhớ hơn nữa :>

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1e3 + 10;
const int MAXM = 1e3 + 10;

int n, m, w[MAXN], v[MAXN], dp[MAXM];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= w[i]; j --){
            dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
        }
    }

    int answer = dp[m];
    cout << answer << "\n";

    return 0;
}