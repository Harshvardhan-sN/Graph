#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

#define all(x) x.begin(),x.end()
#define nl endl
#define FOR(i,j,n) for(int i = j; i < n; i++)
#define pb push_back

void dfs(int node, vector<vector<int>> &ad, vector<bool> &vis, vector<int> &ans) {
	vis[node] = 1;
	ans.pb(node);
	for (auto &it : ad[node]) {
		if (!vis[it]) {
			dfs(it, ad, vis, ans);
		}
	}
}
vector<int> dfsOfGraph(int N, vector<vector<int>> &ad) {
	vector<bool> vis(N);
	int start = 0;
	vector<int> result;
	dfs(start, ad, vis, result);
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int e, v;    cin >> e >> v;
	vector<vector<int>> v1(e, vector<int> (2));
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> v1[i][j];
		}
	}
	vector<int> ans = dfsOfGraph(e, v1);
	for (auto &it : ans)      cout << it << " ";

	return 0;
}