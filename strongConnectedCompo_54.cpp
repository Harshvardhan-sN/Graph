#include<bits/stdc++.h>
using namespace std;
// Strongly Connected Components (SSC)
// Only valid for Directed Graphs
// Kosaraju's Algorithm

void dfs1(int S, vector<vector<int>>& graph, vector<bool> &vis, stack<int> &st) {
    vis[S] = 1;
    for (auto &it : graph[S])
        if (!vis[it])
            dfs1(it, graph, vis, st);
    st.push(S);
}
void dfs2(int S, vector<bool> &vis, vector<int> adj[]) {
    vis[S] = 1;
    for (auto &it : adj[S])
        if (!vis[it])
            dfs2(it, vis, adj);
}
int kosaraju(int V, vector<vector<int>>& graph) {
    vector<bool> vis(V, 0);
    stack<int> st;
    int res = 0;
    for (int i = 0; i < V; ++i) {
        if (!vis[i])
            dfs1(i, graph, vis, st);
    }
    vector<int> adj[V];
    for (int i = 0; i < V; ++i) {
        vis[i] = 0;
        for (auto &it : graph[i])
            adj[it].push_back(i);
    }
    while (st.size()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            res++;
            dfs2(node, vis, adj);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int V = 5;
    vector<vector<int>> mat{
        {1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}
    };

    cout << kosaraju(V, mat);

    return 0;
}