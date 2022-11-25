#include<iostream>
#include<algorithm>
using namespace std;

inline void read(int& x) {
	register char c = getchar();
	while (!isdigit(c)) c = getchar();
	x = c ^ 48;
	while (isdigit(c = getchar())) x = (x << 3) + (x << 1) + (c ^ 48);
}

const int N = 10004, M = 100005;
int n, m, a[N], b[N];
struct edge {
	int u, v, id;
	edge(int _u = 0, int _v = 0, int _id = 0) : u(_u), v(_v), id(_id) {}
} e1[M], e2[M];
int cnt1, cnt2;

int par[N];
int root(int u) { return par[u] < 0 ? u : par[u] = root(par[u]); }
bool Union(int u, int v) {
	if ((u = root(u)) == (v = root(v))) return false;
	if (par[u] > par[v]) swap(u, v);
	par[u] += par[v];
	par[v] = u;
	return true;
}

int cnt, st[N];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int test; read(test); while (test--) {
		read(n); read(m);
		for (int i = 1; i < n; ++i) read(a[i]);
		for (int i = 1; i < n; ++i) read(b[i]);

		cnt1 = cnt2 = 0;
		for (int i = 1, u, v, c; i <= m; ++i) {
			read(u); read(v); read(c);
			if (c == 1) e1[cnt1++] = edge(u, v, i);
			else e2[cnt2++] = edge(u, v, i);
		}

		fill(par + 1, par + n + 1, -1);
		for (int i = 0; i < cnt1; ++i) Union(e1[i].u, e1[i].v);

		cnt = 0;
		for (int i = 0; i < cnt2; ++i)
			if (Union(e2[i].u, e2[i].v)) st[cnt++] = i;

		fill(par + 1, par + n + 1, -1);
		for (int i = 0; i < cnt; ++i) Union(e2[st[i]].u, e2[st[i]].v);

		int ans(a[n - 1 - cnt] + b[cnt]), p(cnt), Cnt(cnt);
		for (int i = 0; i < cnt2; ++i) if (Union(e2[i].u, e2[i].v)) {
			++Cnt;
			if (ans > a[n - 1 - Cnt] + b[Cnt]) {
				ans = a[n - 1 - Cnt] + b[Cnt];
				p = Cnt;
			}
		}

		fill(par + 1, par + n + 1, -1);
		for (int i = 0; i < cnt; ++i)
			Union(e2[st[i]].u, e2[st[i]].v), cout << e2[st[i]].id << ' ';

		for (int i = 0; i < cnt2 && cnt < p; ++i)
			if (Union(e2[i].u, e2[i].v)) ++cnt, cout << e2[i].id << ' ';

		for (int i = 0; i < cnt1; ++i)
			if (Union(e1[i].u, e1[i].v)) cout << e1[i].id << ' ';

		cout << '\n';
	}
}
/**  /\_/\
 *  (= ._.)
 *  / >0  \>1
**/
