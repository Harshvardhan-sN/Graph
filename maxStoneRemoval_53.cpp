#include<bits/stdc++.h>
using namespace std;

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

int maxRemove(vector<vector<int>>& stones, int n1) {
    int n = 0, m = 0, res = 0;
    for (auto &it : stones) {
        n = max(n, it[0]);
        m = max(m, it[1]);
    }
    DisjointSet ds(n + m + 1);
    unordered_map<int, int> uniqueNodes;
    for (auto &it : stones) {
        int rowNumber = it[0];
        int colNumber = it[1] + n + 1;
        ds.unionSize(rowNumber, colNumber);
        uniqueNodes[rowNumber] = uniqueNodes[colNumber] = 1;
    }
    for (auto &it : uniqueNodes) {
        if (ds.findPar(it.first) == it.first)
            res++;
    }
    return n1 - res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;  cin >> n;
    vector<vector<int>> points;
    for (int i = 0; i < n; ++i) {
        int x, y;    cin >> x >> y;
        points.push_back({x, y});
    }
    cout << maxRemove(points, n);

    return 0;
}