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
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    DisjointSet ds(n * m);
    vector<int> res;
    int currTotal = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for (auto &it : operators) {
        int i = it[0], j = it[1];
        if (!vis[i][j]) {
            vis[i][j] = 1;
            ++currTotal;
            int node = i * m + j;
            for (int k = 0; k < 4; ++k) {
                int x = dx[k] + i;
                int y = dy[k] + j;
                int neighbour = x * m + y;
                // check if they are not already connected
                if (isValid(x, y, n, m) && vis[x][y] && ds.findPar(node) != ds.findPar(neighbour)) {
                    --currTotal;
                    ds.unionSize(node, neighbour);
                }
            }
        }
        res.push_back(currTotal);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // // testCase - 1
    // int n = 4, m = 5;
    // vector<vector<int>> opr{
    //     {1,1},{0,1},{3,3},{3,4}
    // };

    // // testCase - 2
    int n = 4, m = 5;
    vector<vector<int>> opr{
        {0, 0}, {1, 1}, {2, 2}, {3, 3}
    };

    vector<int> ans = numOfIslands(n, m, opr);
    for (int &i : ans)
        cout << i << " ";

    return 0;
}