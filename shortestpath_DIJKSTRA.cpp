#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

void dfs(int S, int E, vector<int> &path, vector<int> &res) {
    if (S == E)      return;
    dfs(path[S], E, path, res);
    res.push_back(S);
}

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    set<pair<int, int>> st;
    vector<vector<int>> adj[n + 1];
    for (auto &it : edges) {
        int u = it[0], v = it[1], w = it[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> initialCost(n + 1, 1e9);
    initialCost[1] = 0;
    st.emplace(0, 1);
    vector<int> path(n + 1, 0);
    path[1] = 1;
    while (st.size()) {
        auto it = st.begin();
        int cost = it->first;
        int node = it->second;
        st.erase(it);
        for (auto &neighbour : adj[node]) {
            int newCost = cost + neighbour[1];
            int goToNode = neighbour[0];
            if (newCost < initialCost[goToNode]) {
                if(initialCost[goToNode] != 1e9)    
                    st.erase({initialCost[goToNode], goToNode});
                initialCost[goToNode] = newCost;
                path[goToNode] = node;
                st.emplace(newCost, goToNode);
            }
        }
    }
    if (path[n] == 0)    return { -1};
    vector<int> res;
    res.push_back(1);
    dfs(n, 1, path, res);
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V = 5, E = 6;
    vector<vector<int>> edges;
    edges.push_back({1,2,2});
    edges.push_back({2,5,5});
    edges.push_back({2,3,4});
    edges.push_back({1,4,1});
    edges.push_back({4,3,3});
    edges.push_back({3,5,1});
    
    vector<int> res = shortestPath(V, E, edges);
    for(auto &it: res)      cout<<it<<" ";


    return 0;
}