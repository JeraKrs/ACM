#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 5 * 1e5 + 5;

int n, c = -1;
ll stack[N];

int main () {
	ll x, ans = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &x);

		while (c > 0 && stack[c-1] >= stack[c] && stack[c] <= x) {
			ans += min(stack[c-1], x);
			c--;
		}
		stack[++c] = x;
	}
	sort (stack, stack + c + 1);

	for (int i = 0; i <= c - 2; i++)
		ans += stack[i];
	printf("%lld\n", ans);
	return 0;
}
