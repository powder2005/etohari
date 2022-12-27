// Code mely
// quy hoạch động cái túi cơ bản phiên bản tối ưu bộ nhớ

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 1e3 + 10;
const int MAXM = 1e3 + 10;

int n, m, w[MAXN], v[MAXN], lastDp[MAXM], preDp[MAXM];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            preDp[j] = lastDp[j];
        }
        for (int j = 0; j <= m; j++) {
            if (j >= w[i]) {
                lastDp[j] = max(preDp[j], preDp[j - w[i]] + v[i]);
            }
            else {
                lastDp[j] = preDp[j];
            }
        }
    }

    int answer = lastDp[m];
    cout << answer << "\n";

    return 0;
}