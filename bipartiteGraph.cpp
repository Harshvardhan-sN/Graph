#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

bool bfs(int start, vector<vector<int>> &adj, vector<int> &vis) {
	queue<int> q1;
	q1.push(start);
	vis[start] = 1;
	while (!q1.empty()) {
		int parent = q1.front();
		q1.pop();
		for (int child : adj[parent]) {
			if (vis[child] == -1) {
				vis[child] = !vis[parent];
				q1.push(child);
			}
			else if (vis[parent] == vis[child])
				return 0;
		}
	}
	return 1;
}
bool dfs(int parent, int color, vector<vector<int>> &adj, vector<int> &vis) {
	vis[parent] = color;
    for (int child : adj[parent]) {
		if (vis[child] == -1) {
			if (!dfs(child, !color, adj, vis))   return 0;
		}
		else if (vis[child] == vis[parent]) return 0;
	}
	return 1;
}
bool isBipartite(int V, vector<vector<int>> &adj) {
	vector<int> vis(V, -1);
	for (int i = 0; i < V; i++) {
		if (vis[i] == -1) {
			// // for -> BFS
			// if(!bfs(i, adj, vis))    return 0;

			// // for -> DFS
			if (!dfs(i, 0, adj, vis))    return 0;
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> grid;

	// // testCase-1
	// int V = 8;
	// grid.pb({2});
	// grid.pb({1, 3});
	// grid.pb({2 ,4});
	// grid.pb({3, 5, 7});
	// grid.pb({4, 6});
	// grid.pb({2, 5});
	// grid.pb({4, 8});
	// grid.pb({7});


	// // testCase-2
	// int V = 3;
	// grid.pb({1, 2});
	// grid.pb({0});
	// grid.pb({0});

	cout << boolalpha;
	cout << isBipartite(V, grid);

	return 0;
}