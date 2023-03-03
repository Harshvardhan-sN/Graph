#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        for (int i = 0; i <= n; ++i) {
            parent.push_back(i);
            rank.push_back(0);
            size.push_back(1);
        }
    }
    int findPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionRank(int u, int v) {
        int Upar_u = findPar(u);
        int Upar_v = findPar(v);
        if (Upar_u == Upar_v)     return;
        if (rank[Upar_u] < rank[Upar_v]) {
            parent[Upar_u] = Upar_v;
        }
        else if (rank[Upar_v] < rank[Upar_u]) {
            parent[Upar_v] = Upar_u;
        }
        else {
            parent[Upar_v] = Upar_u;
            ++rank[Upar_u];
        }
    }
    void unionSize(int u, int v) {
        int Upar_u = findPar(u);
        int Upar_v = findPar(v);
        if (Upar_u == Upar_v)     return;
        if (size[Upar_u] < size[Upar_v]) {
            parent[Upar_u] = Upar_v;
            size[Upar_v] += size[Upar_u];
        } else {
            parent[Upar_v] = Upar_u;
            size[Upar_u] += size[Upar_v];
        }
    }
};

int Solve(int n, vector<vector<int>>& edge) {
    int m = edge.size(), numberOfComponents = 0, extraEdges = 0;
    DisjointSet ds(n);
    for (auto &it : edge) {
        int u = it[0], v = it[1];
        if (ds.findPar(u) != ds.findPar(v))
            // forming MST
            ds.unionRank(u, v);
        else
            ++extraEdges;
    }
    for (int i = 0; i < n; i++) {
        if (ds.parent[i] == i)
            numberOfComponents++;
    }
    int totalMinReqEdges = numberOfComponents - 1;
    if (totalMinReqEdges > extraEdges)
        return -1;
    return totalMinReqEdges;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // // tc -> 1
    // int n = 4;
    // vector<vector<int>> adj;
    // adj.push_back({0, 1});
    // adj.push_back({0, 2});
    // adj.push_back({1, 2});

    // // tc -> 2
    int n = 6;
    vector<vector<int>> adj;
    adj.push_back({0, 1});
    adj.push_back({0, 2});
    adj.push_back({0, 3});
    adj.push_back({1, 2});
    adj.push_back({1, 3});
    
    cout << Solve(n, adj);
    return 0;
}