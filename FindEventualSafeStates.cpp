#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

bool dfs(int start, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &path) {
	vis[start] = 1;
	path[start] = 1;
	for (int &i : adj[start]) {
		if (!vis[i]) {
			if (dfs(i, adj, vis, path))  return 1;
		}
		else if (path[i])    return 1;
	}
	path[start] = 0;
	return 0;
}
vector<int> eventualSafeNodes(int V, vector<vector<int>> &adj) {
	vector<bool> vis(V, 0);
	vector<bool> path(V, 0);
	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			dfs(i, adj, vis, path);
		}
	}
	vector<int> res;
	for (int i = 0; i < V; i++) {
		if (!path[i])     res.push_back(i);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> grid;
	int V = 10;
	grid.pb({1});
	grid.pb({2});
	grid.pb({3, 6});
	grid.pb({4});
	grid.pb({5});
	grid.pb({});
	grid.pb({4});
	grid.pb({1, 8});
	grid.pb({9});
	grid.pb({7});

	vector<int> res = eventualSafeNodes(V, grid);
	for (auto &it : res)      cout << it << " ";

	return 0;
}