#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
const int N = 2005;
const int d[4][2] = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
const char sign[10] = "><^v";

int r, c, a, b, cnt, n, m;
char g[N][N];

void Max (int k) {
	m = max(k, m);
	if (m > n) swap(n, m);
}

void init () {
	cnt = 0;
	scanf("%d%d%*c", &r, &c);
	for (int i = 0; i < r; i++) gets(g[i]);
}

int dfs(int x, int y) {
	int ans = 0;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int p = x + d[i][0], q = y + d[i][1];
		if (p < 0 || p >= r || q < 0 || q >= c) continue;
		if (g[p][q] != sign[i]) continue;
		if (g[x][y] == '#') Max(dfs(p, q));
		else ans = max(ans, dfs(p, q));
	}
	return ans + 1;
}

int solve () {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) if (g[i][j] == '#') {
			dfs(i, j);
		}
	}
	if (cnt < r * c) return -1;
	return n == m ? 2 * n : 2 * n - 1;
}

int main () {
	init();
	printf("%d\n", solve ());
	return 0;
}
