#include"bits/stdc++.h"
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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    DisjointSet ds(7);
    if (ds.findPar(3) == ds.findPar(7))
        cout << "Same\n";
    else    cout << "Not Same\n";
    ds.unionSize(1, 2);
    ds.unionSize(2, 3);
    ds.unionSize(4, 5);
    ds.unionSize(6, 7);
    ds.unionSize(5, 6);
    // if 3 & 7 belong to same compnent or not
    if (ds.findPar(3) == ds.findPar(7))
        cout << "Same\n";
    else    cout << "Not Same\n";
    ds.unionSize(3, 7);
    if (ds.findPar(3) == ds.findPar(7))
        cout << "Same\n";
    else    cout << "Not Same\n";

    return 0;
}