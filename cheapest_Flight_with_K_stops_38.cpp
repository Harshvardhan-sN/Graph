#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
    vector<pair<int, int>> adj[n];
    for (auto &it : flights)
        adj[it[0]].push_back({it[1], it[2]});
    // Both pq and queue will work
    // in pq make the steps primary
    queue<pair<int, pair<int, int>>> q1;
    // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q1;
    q1.push({0, {src, -1}});
    int res = 1e9;
    // take a distance array or ->
    // vector<int> vis(n, 1e9);
    set<pair<pair<int, int>, int>> st;
    while (q1.size()) {
        int node = q1.front().second.first;
        int step = q1.front().second.second;
        int cost = q1.front().first;
        q1.pop();
        if (step <= k and node == dst) 
            res = min(res, cost);
        if (step >= k and node != dst) 
            continue;
        for (auto &it : adj[node]) {
            if (!st.count({{node, it.first}, step})) {
                st.insert({{node, it.first}, step});
                q1.push({cost + it.second, {it.first, step + 1}});
            }
        }
    }
    return res == 1e9 ? -1 : res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 4, src = 0, dst = 3, k = 1;
    vector<vector<int>> path{
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };

    cout << CheapestFLight(n, path, src, dst, k); 
    return 0;
}