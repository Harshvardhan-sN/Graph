#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

void dfs(int S, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st) {
	vis[S] = 1;
	for (int &child : adj[S]) {
		if (!vis[child]) {
			dfs(child, adj, vis, st);
		}
	}
	st.push(S);
}

vector<int> topoSort(int V, vector<vector<int>> &adj) {
	vector<bool> vis(V, 0);
	stack<int> st;
	for (int i = 0; i < V; i++) {
		if (!vis[i]) {
			dfs(i, adj, vis, st);
		}
	}
	vector<int> res;
	while (!st.empty()) {
		res.push_back(st.top());
		st.pop();
	}
	return res;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	
	vector<vector<int>> dag;

    // // testCase -> 1
    // int V = 6;
	// dag.push_back({1});
	// dag.push_back({2});
	// dag.push_back({3});
	// dag.push_back({4, 5});
	// dag.push_back({});
	// dag.push_back({});

    // // testCase -> 2
    int V = 6;
    dag.push_back({});
    dag.push_back({});
    dag.push_back({3});
    dag.push_back({1});
    dag.push_back({0, 1});
    dag.push_back({0, 2});


    // ************  DFS  ****************
	vector<int> order = topoSort(V, dag);
	for (auto &it : order)    cout << it << " ";
    cout<<nl;



    // ************  BFS  ****************
    vector<int> InDegree(V, 0); 		// map<int, int> InDegree
	queue<int> q1;
    for(int i=0; i<V; i++){
	    for(int &it: dag[i])    InDegree[it]++;
	}    
	for(int i=0; i<V; i++){
	    if(InDegree[i]==0)    q1.push(i);
	}
    vector<int> res;
	while(!q1.empty()){
        int S = q1.front();
	    q1.pop();
	    res.push_back(S);
	        
	    for(int &child: dag[S]){
	        InDegree[child]--;
	        if(InDegree[child]==0)    q1.push(child);
	    }
	}
    for(auto &it: res)      cout<<it<<" ";

	return 0;
}