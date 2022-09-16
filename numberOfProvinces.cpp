#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

#define all(x) x.begin(),x.end()
#define nl endl
#define FOR(i,j,n) for(int i = j; i < n; i++)
#define pb push_back

void dfs(vector<vector<int>> &ad, vector<bool> &vis , int N) {
	vis[N] = 1;
	FOR(i, 0, ad[N].size()) {
		if (ad[N][i] && !vis[i]) {
			dfs(ad, vis, i);
		}
	}
}

int numberOfProvinces(vector<vector<int>> &ad, int N) {
	vector<bool> vis(N, 0);
	int pro = 0;
	for (int i = 1; i < N; i++) {
		if (!vis[i]) {
			dfs(ad, vis, i);
			pro++;
		}
	}
	return pro;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;  cin >> n;
	vector<vector<int>> v1;
	FOR(i, 0, n) {
		vector<int> a;
		FOR(j, 0, n) {
			int x;  cin >> x;
			a.pb(x);
		}
		v1.pb(a);
	}
	cout << numberOfProvinces(v1, n);

	return 0;
}