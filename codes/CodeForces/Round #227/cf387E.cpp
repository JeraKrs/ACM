#include <stdio.h>
#include <string.h>
#include <iostream>
#include <set>

using namespace std;

const int N = 1000005;
typedef long long ll;

int n, k, p[N], b[N];
ll v[N];

void add(int x, ll val) {
	while (x <= n) {
		v[x] += val;
		x += (x & (-x));
	}
}

ll sum(int x) {
	ll ans = 0;
	while (x > 0) {
		ans += v[x];
		x -= (x & (-x));
	}
	return ans;
}

void init() {
	int a;
	memset(b, 0, sizeof(b));
	memset(v, 0, sizeof(v));
	scanf("%d%d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		p[a] = i;
		add(i, 1);
	}

	for (int i = 1; i <= k; i++) {
		scanf("%d", &a);
		b[a] = 1;
	}
}

ll solve() {
	set<int> s;
	set<int>::iterator iter;
	ll ans = 0;

	s.insert(0); s.insert(n+1);
	for (int i = 1; i <= n; i++) {
		if (b[i]) {
			s.insert(p[i]);
			continue;
		}
		iter = s.upper_bound(p[i]);
		int r = *iter - 1;
		int l = *(--iter);
		ans += sum(r) - sum(l);
		add(p[i], -1);
	}
	return ans;
}

int main() {
	init();
	cout << solve() << endl;
	return 0;
}
