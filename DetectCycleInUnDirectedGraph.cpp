#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

bool bfs(int V, int source, vector<vector<int>> &adj, vector<bool> vis){
    queue<pair<int,int>> que;
    que.push({source, -1});
    vis[source] = 1;
    while(!que.empty()){
        int child = que.front().first;
        int parent = que.front().second;
        que.pop();
        for(int it: adj[child]){
            if(parent!=it){
                if(!vis[it]){
                    que.push({it, child});
                    vis[it] = 1;
                }
                else            return 1;
            }
        }
    }
    return 0;
}

bool isCycle(int V, vector<vector<int>> &adj) {
    vector<bool> vis(V, 0);
    for(int i=0; i<V; i++){
        if(bfs(V, i, adj, vis))      return 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V = 5;
    vector<vector<int>> v1;
    
    // testCase - 1
    // v1.push_back({1});
    // v1.push_back({0, 2, 4});
    // v1.push_back({1, 3});
    // v1.push_back({2, 4});
    // v1.push_back({1, 3});

    // testCase - 2
    v1.push_back({});
    v1.push_back({2});
    v1.push_back({1, 3});
    v1.push_back({2});

    cout<<boolalpha;
    cout<<isCycle(V, v1);

    return 0;
}