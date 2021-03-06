#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 500;
struct Parcel {
	int in, out, w, s, v;
	void read() {
		scanf("%d%d%d%d%d", &in, &out, &w, &s, &v);
	}
}p[maxn];

inline bool cmp (const Parcel& a, const Parcel& b) {
	return a.out < b.out || (a.out == b.out && a.in > b.in);
}

int N, S, dp[maxn + 5][maxn * 2 + 5], f[maxn * 2 + 5];

int main () {
	scanf("%d%d", &N, &S);
	p[0] = (Parcel){0, 2 * maxn, 0, S, 0};
	for (int i = 1; i <= N; i++)
		p[i].read();
	sort(p, p + N + 1, cmp);

	for (int i = 0; i <= N; i++) {
		for (int w = p[i].w; w <= S; w++) {
			int o = p[i].in;
			int wi = min(p[i].s, w - p[i].w);
			f[o] = 0;

			for (int j = 0; j < i; j++) if (p[j].in >= p[i].in) {
				while (o < p[j].out) {
					o++;
					f[o] = f[o-1];
				}
				f[o] = max(f[o], f[p[j].in] + dp[j][wi]);
			}
			dp[i][w] = f[o] + p[i].v;
		}
	}

	printf("%d\n", dp[N][S]);
	return 0;
}
