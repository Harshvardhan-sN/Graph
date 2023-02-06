#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

void dfs(int S, vector<int> adj[], vector<bool> &vis, stack<int> &st) {
	vis[S] = 1;
	for (int &child : adj[S]) {
		if (!vis[child]) {
			dfs(child, adj, vis, st);
		}
	}
	st.push(S);
}

void topoSortByDFS(int V, vector<int> adj[]) {
	vector<bool> vis(V, 0);
	stack<int> st;
	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			dfs(i, adj, vis, st);
		}
	}
	vector<int> res;
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

void topoSortByBFS(int V, vector<int> adj[]) {
	vector<int> InDegree(V, 0); 		// map<int, int> InDegree
	queue<int> q1;
	for (int i = 0; i < V; i++) {
		for (int &it : adj[i])    InDegree[it]++;
	}

	for (int i = 0; i < V; i++) {
		if (InDegree[i] == 0)    q1.push(i);
	}
	vector<int> res;
	while (!q1.empty()) {
		int S = q1.front();
		q1.pop();
		res.push_back(S);

		for (int &child : adj[S]) {
			InDegree[child]--;
			if (InDegree[child] == 0)    q1.push(child);
		}
	}
	if (res.size() == V) {
		for (auto &it : res)      cout << it << " ";
		cout << endl;
	}
	else {
		cout << "Cycle Detected No TopoSort\n";
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	vector<vector<int>> dag;

	// // testcase -> 1
	int V = 6;
	dag.push_back({5, 2});
	dag.push_back({5, 0});
	dag.push_back({4, 0});
	dag.push_back({4, 1});
	dag.push_back({2, 3});
	dag.push_back({3, 1});

	// // testCase -> 2
	// int V = 4;
	// dag.push_back({0, 1});
	// dag.push_back({1, 2});
	// dag.push_back({2, 3});
	// dag.push_back({3, 3});

	// // testCase -> 3
	// int V = 4;
	// dag.push_back({3, 0});
	// dag.push_back({1, 0});
	// dag.push_back({2, 0});


	// Create Adjacency List of given Graph
	vector<int> adj[V];
	for (auto &it : dag) {
		adj[it[0]].push_back(it[1]);
	}

	// ************  DFS  ****************
	topoSortByDFS(V, adj);

	// ************  BFS  ****************
	topoSortByBFS(V, adj);
	/*
	to detect a cycle in directed graph using topological sort
	just check if the topological sort for that graph exsit or not
	if it exist then it donot have cycle otherwise yes
	*/

	return 0;
}
