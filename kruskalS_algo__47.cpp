#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public:
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

int spanningTree(int n, vector<pair<int, pair<int, int>>> &mat) {
    DisjointSet ds(n + 1);
    int res = 0;
    sort(mat.begin(), mat.end());
    for (auto &it : mat) {
        int w = it.first, u = it.second.first, v = it.second.second;
        if (ds.findPar(u) != ds.findPar(v)) {
            ds.unionSize(u, v);
            res += w;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 3;
    vector<pair<int, pair<int, int>>> mat;
    // w , u, v
    mat.push_back({5, {0, 1}});
    mat.push_back({3, {1, 2}});
    mat.push_back({1, {0, 2}});

    cout << spanningTree(n, mat);

    return 0;
}