#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int N = 505;

int n, m, g[N][N], ind[N], out[N], v[N], p[N];


void init () {
	memset(g, 0, sizeof(g));
	memset(ind, 0, sizeof(ind));
	memset(out, 0, sizeof(out));

	int a, b;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		g[a][b] = 1;
		out[a]++; ind[b]++;
	}
}

bool find (int r, int u) {
	for (int i = 1; i <= n; i++) {
		if (i == r || !g[u][i]) continue;
		if (v[i]) continue;
		v[i] = 1;
		if (p[i] == -1 || find(r, p[i])) {
			p[i] = u;
			return true;
		}
	}
	return false;
}

int handle(int r) {
	int ans = 0;
	memset(p, -1, sizeof(p));
	for (int i = 1; i <= n; i++) {
		if (i == r) continue;
		memset(v, 0, sizeof(v));
		if (find(r, i)) ans++;
	}
	return ans;
}

int solve (int r) {
	int s = ind[r] + out[r] - g[r][r];
	int ans = 2 * n - 1 - s;
	int f = handle(r);
	ans = ans + m - s - f;
	ans = ans + n - 1 - f;
	return ans;
}

int main () {
	init();
	int ans = 1 << 30;
	for (int i = 1; i <= n; i++) ans = min(ans, solve(i));
	printf("%d\n", ans);
	return 0;
}
