#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef long long ll;
const int N = 10;

ll n, sx, sy, dx, dy, t;

struct mat {
	int r, c;
	ll k[N][N];

	void init(int r, int c) {
		this->r = r; this->c = c;
		memset(k, 0, sizeof(k));
	}

	void clear() {
		//memset(k, 0, sizeof(k));
		k[0][0] = k[0][5] = k[1][1] = k[1][5] = k[2][5] = k[3][5] = 2;
		k[0][1] = k[0][2] = k[0][4] = k[1][0] = k[1][3] = k[1][4] = k[2][0] = k[2][1] = k[2][2] = k[2][4] = 1;
		k[3][0] = k[3][1] = k[3][3] = k[3][4] = k[4][4] = k[4][5] = k[5][5] = 1;
	}

	friend mat operator * (const mat& a, const mat& b) {
		mat ans;
		ans.init(a.r, b.c);

		for (int i = 0; i < ans.r; i++) {

			for (int j = 0; j < ans.c; j++) {
				for (int x = 0; x < b.r; x++)
					ans.k[i][j] = ((ans.k[i][j] + a.k[i][x] * b.k[x][j]) % n + n) % n;
			}
		}
		return ans;
	}
};

int main() {
	cin >> n >> sx >> sy >> dx >> dy >> t;

	mat ans;
	ans.init(6, 1);
	ans.k[0][0] = sx - 1;
	ans.k[1][0] = sy - 1;
	ans.k[2][0] = dx;
	ans.k[3][0] = dy;
	ans.k[4][0] = 0;
	ans.k[5][0] = 1;

	mat b;
	b.init(6, 6);
	b.clear();

	while (t) {
		if (t&1)
			ans = b * ans;
		b = b * b;
		t>>=1;
	}

	cout << ans.k[0][0] + 1 << " " << ans.k[1][0] + 1 << endl;
	return 0;
}
