#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

// Simple dijkstra also works for small testCase.. ACCEPTED on GFG
int countPathsDIJKSTRA(int n, vector<vector<int>>& roads) {
    int res = 0, minCost = -1, mod = 1e9 + 7;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> adj[n];
    for (auto &it : roads) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    pq.push({0, {0, -1}});
    vector<int> vis(n, 1e9);
    vis[0] = 0;
    while (pq.size()) {
        int cost = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();
        if (node == n - 1) {
            if (minCost == -1)
                minCost = cost;
            if (minCost == cost)
                res++;
            res %= mod;
            continue;
        }
        for (auto &child : adj[node]) {
            int newCost = cost + child[1];
            if (child[0] != parent and newCost <= vis[child[0]]) {
                vis[child[0]] = newCost;
                pq.push({newCost, {child[0], node}});
            }
        }
    }
    return res % mod;
}

// Leetcode and GFG
int countPaths(int n, vector<vector<int>>& roads) {
    long long mod = 1e9 + 7;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<vector<int>> adj[n];
    for (auto &it : roads) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    pq.push({0, 0});
    vector<long long> vis(n, 1e12);
    vector<int> ways(n, 0);
    ways[0] = 1;
    vis[0] = 0;
    while (pq.size()) {
        long long cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto &child : adj[node]) {
            long long newCost = cost + child[1] + 0LL;
            if (newCost < vis[child[0]]) {
                vis[child[0]] = newCost;
                ways[child[0]] = ways[node] % mod;
                pq.push({newCost, child[0]});
            }
            else if (newCost == vis[child[0]]) {
                ways[child[0]] += ways[node];
                ways[child[0]] %= mod;
            }
        }
    }
    return ways[n - 1] % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 7;
    vector<vector<int>> roads{
        {0, 6, 7},
        {0, 1, 2},
        {1, 2, 3},
        {1, 3, 3},
        {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5},
        {4, 6, 2}
    };

    cout << countPaths(n, roads);

    return 0;
}