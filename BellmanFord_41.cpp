#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back
//  **********************
//  Bellman Ford for negative cycle graph
//  Dijkstra do not work in negative cycle
//  Bellman Ford works on directed graphs

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> cost(V, 1e8);
    cost[S] = 0;
    for (int i = 0; i < V; i++) {
        for (auto &it : edges) {
            int u = it[0], v = it[1], w = it[2];
            if (w + cost[u] < cost[v]) {
                cost[v] = cost[u] + w;
                if (i == V - 1)
                    return { -1};
            }
        }
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 3, source = 2;
    vector<vector<int>> graph{
        {0, 1, 5}, {1, 0, 3}, {1, 2, -1}, {2, 0, 1}
    };

    vector<int> res = bellman_ford(n, graph, source);
    for (auto &it : res)  cout << it << " ";

    return 0;
}