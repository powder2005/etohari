#include <bits/stdc++.h>
using namespace std;

const int ALPHA = 26;
  
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int cnt = ALPHA, l = -1, r = -1;

    vector<int> last(ALPHA, -1), f(ALPHA + 1, -1);
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        f.erase(find(f.begin(), f.end(), last[c]));
        last[c] = i;
        f.insert(f.begin(), i);

        for (int j = 1; j <= ALPHA; j++)
            if (j * (r - l + 1) < cnt * (i - f[j])) {
                cnt = j;
                l = f[j] + 1;
                r = i;
            }
    }

    cout << l + 1 << " " << r + 1;

    return 0;
}
