#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

int spanningTree(int n, vector<vector<int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> vis(n, 0);
    pq.push({0, 0});
    int sum = 0;
    while (pq.size()) {
        auto[cost, node] = pq.top();
        pq.pop();
        if (vis[node])
            continue;
        vis[node] = 1;
        sum += cost;
        for (auto &it : adj[node]) {
            if (!vis[it[0]]) {
                pq.push({it[1], it[0]});
            }
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 3;
    vector<vector<int>> adj[n];
    adj[0].push_back({1, 5});
    adj[1].push_back({0, 5});
    adj[0].push_back({2, 1});
    adj[2].push_back({0, 1});
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    cout << spanningTree(n, adj);
    return 0;
}