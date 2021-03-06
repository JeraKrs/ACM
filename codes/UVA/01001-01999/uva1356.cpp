#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

double f (double a, double x) {
	double aa = a * a, xx = x * x;;
	return (x * sqrt(aa + xx) + aa * log(fabs(x + sqrt(aa + xx)))) / 2;
}

double parabola_length (double w, double h) {
	double a = 4 * h / (w * w);
	double b = 1.0 / (2 * a);
	return (f(b, w/2) - f(b, 0)) * 4 * a;
}

double bsearch (double l, double r, double d, double v) {
	while (r - l > 1e-5) {
		double mid = (r + l) / 2;
		if (parabola_length(d, mid) < v)
			l = mid;
		else
			r = mid;
	}
	return l;
}

int main () {
	int cas;
	scanf("%d", &cas);
	for (int kcas = 1; kcas <= cas; kcas++) {
		int D, H, B, L;
		scanf("%d%d%d%d", &D, &H, &B, &L);

		int n = (B + D - 1) / D;
		double d = B * 1.0 / n;
		double l = L * 1.0 / n;

		if (kcas > 1)
			printf("\n");
		printf("Case %d:\n%.2lf\n", kcas, (double)H - bsearch(0, H, d, l));
	}
	return 0;
}
