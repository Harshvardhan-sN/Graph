#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

void shortest_distance(vector<vector<int>> &path) {
    int n = path.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (path[i][j] == -1)
                path[i][j] = 1e5;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (path[i][k] + path[k][j] < path[i][j])
                    path[i][j] = path[i][k] + path[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (path[i][j] == 1e5)
                path[i][j] = -1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Undirected Graph
    // graph[i][j] == -1 means there is no edge from i -> j or j -> i;
    // i == j diagonal is always 0 i.e: i -> i distance will be zero always

    // // test 1
    // vector<vector<int>> graph{
    //     {0, 25}, {-1, 0}
    // };

    // test 2
    vector<vector<int>> graph{
        {0, 1, 43}, {1, 0, 6}, { -1, -1, 0}
    };

    shortest_distance(graph);
    for (auto &v1 : graph) {
        for (auto &it : v1)
            cout << it << " ";
        cout << nl;
    }

    return 0;
}