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
bool isValid(int x, int y, int n, int m) {
    return x >= 0 && y >= 0 && x < n && y < m;
}
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int MaxConnection(vector<vector<int>>& grid) {
    int n = grid.size(), res = -1;
    DisjointSet ds(n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                int node = i * n + j;
                for (int k = 0; k < 4; ++k) {
                    int x = dx[k] + i, y = dy[k] + j;
                    int neigh = x * n + y;
                    if (isValid(x, y, n, n) && grid[x][y] == 1) {
                        ds.unionSize(node, neigh);
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 0) {
                int curr = 0;
                unordered_set<int> st;
                for (int k = 0; k < 4; ++k) {
                    int x = dx[k] + i, y = dy[k] + j;
                    int neigh = x * n + y;
                    if (isValid(x, y, n, n) && grid[x][y] == 1) {
                        st.insert(ds.findPar(neigh));
                    }
                }
                for (auto &it : st)
                    curr += ds.size[it];
                res = max(res, curr + 1);
            }
        }
    }
    for (int i = 0; i < n * n; ++i)
        res = max(res, ds.size[ds.findPar(i)]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // // tc - 1
    int n = 2;
    vector<vector<int>> grid{
        {1, 1}, {0, 1}
    };

    // // tc - 2
    // int n = 3;
    // vector<vector<int>> grid{
    //     {1, 0, 1}, {1, 0, 1}, {1, 0, 1}
    // };

    cout << MaxConnection(grid);

    return 0;
}