#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

struct val{
    int x, y, z;
};

int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool isValidDirection(int X, int Y, int n, int m) {return (X >= 0 && Y >= 0 && X < n && Y < m);}

int bfs(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination){
    int n = grid.size(), m = grid[0].size();
    
    // use queue for this question
    // queue<val> q1;
    set<pair<int, pair<int, int>>> q1;
    // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q1;
    vector<vector<bool>> vis(n, vector<bool> (m, 0));
    vis[source.first][source.second] = 1;
    // q1.push({source.first, source.second, 0});
    q1.insert({0, source});
    while(q1.size()){
        auto it = q1.begin();
        int x = it->second.first;
        int y = it->second.second;
        int cost = it->first;
        q1.erase(it);
        if(x == destination.first and y == destination.second)
            return cost;
        for(int i = 0; i < 4; i++){
            int dX = x + dx[i];
            int dY = y + dy[i];
            if(isValidDirection(dX, dY, n, m) and !vis[dX][dY] and grid[dX][dY]==1){
                vis[dX][dY] = 1;
                q1.insert({cost + 1, {dX, dY}});
            }
        }
    }
    return -1;
}

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
    return bfs(grid, source, destination);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // test-1
    vector<vector<int>> grid;
    grid.push_back({1,1,1,1});
    grid.push_back({1,1,0,1});
    grid.push_back({1,1,1,1});
    grid.push_back({1,1,0,0});
    grid.push_back({1,0,0,1});
    pair<int, int> S(0,1), D(2,2);
    
    // test-2
    // vector<vector<int>> grid;
    // grid.push_back({1,1,1,1,1});
    // grid.push_back({1,1,0,1,1});
    // grid.push_back({1,1,1,1,0});
    // grid.push_back({1,0,1,0,1});
    // pair<int, int> S(0,0), D(3,4);
    
    cout<<shortestPath(grid, S, D);

    

    return 0;
}