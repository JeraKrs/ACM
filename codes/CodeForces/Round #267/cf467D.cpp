#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 1e5+5;

typedef long long ll;
typedef pair<ll, ll> pii;

int M, N, sz, W[maxn];
map<string, int> V;
vector<int> g[maxn * 3];
pii vec[maxn*3];

void add (string& s) {
	ll len = s.length(), cnt = 0;

	for (int j = 0; j < len; j++) {
		if (s[j] >= 'A' && s[j] <= 'Z')
			s[j] = s[j] - 'A' + 'a';

		if (s[j] == 'r')
			cnt++;
	}

	if (!V.count(s)) {
		V[s] = sz;
		vec[sz++] = make_pair(cnt, len);
	}
}

void init () {
	sz = 0;

	string s, e;

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> s;
		add(s);
		W[i] = V[s];
	}

	cin >> N;
	for (int i = 0; i <	N; i++) {
		cin >> s >> e;
		add(s);
		add(e);
		g[V[e]].push_back(V[s]);
	}
}

void solve () {
	queue<int> que;
	for (int i = 0; i < sz; i++)
		que.push(i);

	while (!que.empty()) {
		int idx = que.front();
		pii u = vec[idx];
		que.pop();

		for (int i = 0; i < g[idx].size(); i++) {
			int v = g[idx][i];
			if (vec[v] > u) {
				vec[v] = u;
				que.push(v);
			}
		}
	}

	ll len = 0, cnt = 0;
	for (int i = 0; i < M; i++) {
		cnt += vec[W[i]].first;
		len += vec[W[i]].second;
	}
	cout << cnt << " " << len << endl;
}

int main () {
	init();
	solve();
	return 0;
}
