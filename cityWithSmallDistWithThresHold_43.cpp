#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

// Using Dijkstra
int dijkstra(int n, int S, vector<vector<int>> adj[], int thress) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});
    vector<int> vis(n, 1e9);
    vis[S] = 0;
    unordered_set<int> st;
    while (pq.size()) {
        auto it = pq.top();
        int cost = it.first;
        int node = it.second;
        pq.pop();
        for (auto &it : adj[node]) {
            if (cost + it[1] < vis[it[0]]) {
                if (cost + it[1] <= thress) {
                    st.insert(it[0]);
                    vis[it[0]] = cost + it[1];
                    pq.push({cost + it[1], it[0]});
                }
            }
        }
    }
    return st.size();
}
int findCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> adj[n];
    for (auto &it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    int currMin = 1e9, currCity = -1;
    for (int i = 0; i < n; i++) {
        int Mini = dijkstra(n, i, adj, distanceThreshold);
        if (Mini <= currMin) {
            currCity = max(currCity, i);
            currMin = Mini;
        }
    }
    return currCity;
}

int floydWarshallAlgo(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> path(n, vector<int>(n, 1e9));
    for (auto &it : edges) {
        path[it[0]][it[1]] = it[2];
        path[it[1]][it[0]] = it[2];
    }
    for (int i = 0; i < n; i++)  path[i][i] = 0;
    int currMin = 1e9, currCity = -1;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (path[i][k] == 1e9 || path[k][j] == 1e9)
                    continue;
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (path[i][j] <= distanceThreshold)
                cnt++;
        }
        if (cnt <= currMin) {
            currCity = max(currCity, i);
            currMin = cnt;
        }
    }
    return currCity;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 4, distanceThreshold = 4;
    vector<vector<int>> path{
        {0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}
    };

    cout << findCity(n, path, distanceThreshold);

    return 0;
}