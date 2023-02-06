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
void DoDfs(int V, vector<int> adj[]) {
	vector<bool> vis(V, 0);
	vector<bool> path(V, 0);
	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			dfs(i, adj, vis, path);
		}
	}
	for (int i = 0; i < V; i++) {
		if (!path[i])     cout << i << " ";
	}
	cout << endl;
}

void bfs(int V, vector<int> adj[]) {
	vector<int> RevAdj[V];
	vector<int> InDegree(V, 0);
	queue<int> q1;
	for (int i = 0; i < V; i++) {
		for (int &it : adj[i]) {
			RevAdj[it].push_back(i);
			InDegree[i]++;
		}
	}
	for (int i = 0; i < V; i++) {
		if (InDegree[i] == 0)		q1.push(i);
	}
	priority_queue<int, vector<int>, greater<int>>	pq;
	while (!q1.empty()) {
		int from = q1.front();
		pq.push(from);
		q1.pop();
		for (int &it : RevAdj[from]) {
			InDegree[it]--;
			if (InDegree[it] == 0)		q1.push(it);
		}
	}
	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << nl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> grid;
	// testCase -> 1
	int V = 7;
	grid.push_back({0, 1});
	grid.push_back({0, 2});
	grid.push_back({1, 2});
	grid.push_back({1, 3});
	grid.push_back({3, 0});
	grid.push_back({4, 5});
	grid.push_back({2, 5});

	vector<int> adj[V];
	for (auto &it : grid) {
		adj[it[0]].push_back(it[1]);
	}

	// **********  DFS ***************
	DoDfs(V, adj);

	// ************** BFS *****************
	bfs(V, adj);

	return 0;
}
