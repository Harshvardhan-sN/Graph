#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

void dfs(int S, vector<pair<int, int>> adj[], vector<bool> &vis, stack<int> &st) {
	vis[S] = 1;
	for (auto &it : adj[S]) {
		if (!vis[it.first]) {
			dfs(it.first, adj, vis, st);
		}
	}
	st.push(S);
}

vector<int> DoDfs(vector<pair<int, int>> adj[], int N) {
	vector<bool> vis(N, 0);
	stack<int> st;
	vector<int> path(N, 101);    // initilise with the maximum value of constraints
	for (int i = 0; i < N; i++) {
		if (!vis[i])     dfs(i, adj, vis, st);
	}
	path[0] = 0;      // set the given source node cost 0
	while (st.size()) {
		int top = st.top();
		st.pop();
		int currCost = path[top];
		// check for all adj nodes
		for (auto &it : adj[top]) {
			path[it.first] = min(path[it.first], currCost + it.second);
		}
	}
	for (auto &it : path) {
		if (it == 101)     it = -1;     // if node is not reachable
	}
	return path;
}
// toposort bfs kahn's algo
vector<int> bfs(vector<pair<int, int>> adj[], int N) {
	vector<int> InDegree(N, 0);
	queue<int> q1;
	vector<int> path(N, 101);
	for (int i = 0; i < N; i++) {
		for (auto &it : adj[i]) {
			InDegree[it.first]++;
		}
	}
	for (int i = 0; i < N; i++) {
		if (InDegree[i] == 0)		q1.push(i);
	}
	path[0] = 0;
	while (!q1.empty()) {
		int from = q1.front();
		q1.pop();
		int currDist = path[from];
		for (auto &it : adj[from]) {
			// calculate the path
			path[it.first] = min(path[it.first], currDist + it.second);
			// reduce the InDegree
			InDegree[it.first]--;
			if (InDegree[it.first] == 0)	q1.push(it.first);
		}
	}
	for (auto &it : path) {
		if (it == 101)     it = -1;     // if node is not reachable
	}
	return path;
}

vector<int> shortestPath(int N, int M, vector<vector<int>> &dag, int ch) {
	vector<pair<int, int>> adj[N];
	for (auto &it : dag) {
		int u = it[0], v = it[1], cost = it[2];
		adj[u].emplace_back(v, cost);
	}
	if (ch == 1)	return DoDfs(adj, N);
	return bfs(adj, N);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> dag;
	int N, M;

	// // testCase -> 1
	N = 6, M = 7;
	dag.push_back({0, 1, 2});
	dag.push_back({0, 4, 1});
	dag.push_back({4, 5, 4});
	dag.push_back({4, 2, 2});
	dag.push_back({1, 2, 3});
	dag.push_back({2, 3, 6});
	dag.push_back({5, 3, 1});

	// ***********  DFS *********
	vector<int> res1 = shortestPath(N, M, dag, 1);
	for (auto &it : res1)  cout << it << " ";

	cout << endl;
	// ***********  BFS *********
	vector<int> res2 = shortestPath(N, M, dag, 0);
	for (auto &it : res2)  cout << it << " ";



	return 0;
}