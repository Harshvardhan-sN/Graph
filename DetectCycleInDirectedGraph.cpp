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
		else if (path[i] == 1)    return 1;
	}
	path[start] = 0;
	return 0;
}

bool DoDfs(int V, vector<int> adj[]) {
	vector<bool> vis(V, 0);
	vector<bool> path(V, 0);
	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			if (dfs(i, adj, vis, path))  return 1;
		}
	}
	return 0;
}

bool bfs(int V, vector<int> adj[]) {
	vector<int> InDegree(V, 0);
	for (int i = 0; i < V; i++) {
		for (int &it : adj[i]) {
			InDegree[it]++;
		}
	}
	queue<int> q1;
	for (int i = 0; i < V; i++) {
		if (InDegree[i] == 0)		q1.push(i);
	}
	int N = 0;
	while (!q1.empty()) {
		int from = q1.front();
		q1.pop();
		N++;
		for (int &it : adj[from]) {
			InDegree[it]--;
			if (InDegree[it] == 0)		q1.push(it);
		}
	}
	// if topological sort exist then there is no cycle
	// else it have a cycle
	if (N == V)	return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> mat;

	// // testcase -> 1
	// int V = 6;
	// mat.push_back({5, 2});
	// mat.push_back({5, 0});
	// mat.push_back({4, 0});
	// mat.push_back({4, 1});
	// mat.push_back({2, 3});
	// mat.push_back({3, 1});

	// // testCase -> 2
	// int V = 4;
	// mat.push_back({0, 1});
	// mat.push_back({1, 2});
	// mat.push_back({2, 3});
	// mat.push_back({3, 3});

	// // testCase -> 3
	// int V = 4;
	// mat.push_back({3, 0});
	// mat.push_back({1, 0});
	// mat.push_back({2, 0});


	// Create Adjacency List of given Graph
	vector<int> adj[V];
	for (auto &it : mat) {
		adj[it[0]].push_back(it[1]);
	}


	// ************** DFS *******************
	cout << boolalpha;
	cout << "DFS-> " << DoDfs(V, adj) << nl;

	// *************** BFS *********************
	cout << "BFS-> " << bfs(V, adj);

	return 0;
}
