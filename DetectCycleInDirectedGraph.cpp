#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

bool dfs(int start, vector<int> adj[], vector<bool> &vis, vector<bool> &path) {
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

bool isCyclic(int V, vector<int> adj[]) {
	vector<bool> vis(V, 0);
	vector<bool> path(V, 0);
	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			if (dfs(i, adj, vis, path))  return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> mat;
	// testCase -> 1
    int V = 10;
	mat.pb({1});
	mat.pb({2});
	mat.pb({3, 6});
	mat.pb({4});
	mat.pb({5});
	mat.pb({});
	mat.pb({4});
	mat.pb({1, 8});
	mat.pb({9});
	mat.pb({7});

	cout << boolalpha;
	cout << isCycle(V, mat);

	return 0;
}