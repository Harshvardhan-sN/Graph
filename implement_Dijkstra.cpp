#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

vector<int> DijkstraMinHeap(int V, int S, vector<vector<int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> st;
    st.emplace(0, S);
    vector<int> paths(V, 1e9);
    paths[S] = 0;
    while (st.size()) {
        int cost = st.top().first;
        int node = st.top().second;
        st.pop();
        for (auto &it : adj[node]) {
            int GoingToNode = it[0];
            int OldCost = it[1];
            int newCost = cost + OldCost;
            if (newCost < paths[GoingToNode]) {
                paths[GoingToNode] = newCost;
                st.emplace(newCost, GoingToNode);
            }
        }
    }
    return paths;
}

vector<int> DijkstraSet(int V, int S, vector<vector<int>> adj[]) {
    set<pair<int, int>> st;
    st.emplace(0, S);
    vector<int> paths(V, 1e9);
    paths[S] = 0;
    while (st.size()) {
        auto it = st.begin();
        int cost = it->first;
        int node = it->second;
        st.erase(it);
        for (auto &it : adj[node]) {
            int GoingToNode = it[0];
            int OldCost = it[1];
            int newCost = cost + OldCost;
            if (newCost < paths[GoingToNode]) {
                if(paths[GoingToNode]!=1e9)
                    st.erase({paths[GoingToNode], GoingToNode});
                paths[GoingToNode] = newCost;
                st.emplace(newCost, GoingToNode);
            }
        }
    }
    return paths;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V = 3, S = 2;
    vector<vector<int>> adj[V];
    adj[0].push_back({1, 1});
    adj[0].push_back({2, 6});
    adj[1].push_back({2, 3});
    adj[1].push_back({0, 1});
    adj[2].push_back({1, 3});
    adj[2].push_back({0, 6});

    // ************ USING SET
    vector<int> res1 = DijkstraSet(V, S, adj);
    for (auto &it : res1)  cout << it << " ";

    cout << nl;
    // ************* USING MIN HEAP
    vector<int> res2 = DijkstraMinHeap(V, S, adj);
    for (auto &it : res2)  cout << it << " ";

    return 0;
}
