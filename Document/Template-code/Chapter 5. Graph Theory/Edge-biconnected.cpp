#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 1e4 + 5; // The number of Node
const int maxm = 1e6 + 5; // The number of Edge
/* 如果要求边双联通分量，只需在做一遍dfs，保证不经过割边即可。*/

int dfsclock, pre[maxn], cntbcc, bccno[maxn];
bool iscut[maxm * 2];
int first[maxn], jump[maxm * 2], linker[maxm * 2];

int dfs (int u, int fa) {  
	int lowu = pre[u] = ++dfsclock;
	for (int i = first[u]; i != -1; i = jump[i]) { 
		int v = linker[i];
		if (!pre[v]) {
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if (lowv > pre[u]) 
				iscut[i] = iscut[i^1] = 1;
		} else if (pre[v] < pre[u] && v != fa)
			lowu = min(lowu, pre[v]);
	}
	return lowu;
} 

void dfs (int u) {
	pre[u] = ++dfsclock;
	bccno[u] = cntbcc;

	for (int i = first[u]; i + 1; i = jump[i]) {
		if (iscut[i]) continue;
		int v = linker[i];
		if (!pre[v]) dfs(v);
	}
}

void findEdge (int n) {
	dfsclock = 0;
	memset(pre, 0, sizeof(pre));
	memset(iscut, 0, sizeof(iscut));
	for (int i = 1; i <= n; i++)
		if (!pre[i]) dfs(i, -1);

	dfsclock = cntbcc = 0;
	memset(bccno, 0, sizeof(bccno));
	for (int i = 1; i <= n; i++)
		if (!pre[i]) { cntbcc++; dfs(i); }
} 

int main () {
	return 0;
}
