#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool isValidDirection(int X, int Y, int n, int m) {return (X >= 0 && Y >= 0 && X < n && Y < m);}

int MinimumEffort(vector<vector<int>>& heights) {
    int n = heights.size(), m = heights[0].size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    vector<vector<int>> distance(n, vector<int> (m, 1e9));
    distance[0][0] = 0;
    while (pq.size()) {
        int currEffort = pq.top().first;
        int x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();

        // pq stores the values in sorted order of effort
        // so... it will always take the optimal effort path
        // whatever reachs first to the end will definately be the min. effort
        if (x == n - 1 and y == m - 1) {
            return currEffort;
        }
        for (int i = 0; i < 4; i++) {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (isValidDirection(X, Y, n, m)) {
                int newEffort = max(currEffort, (int)abs(heights[x][y] - heights[X][Y]));
                if (distance[X][Y] > newEffort) {
                    distance[X][Y] = newEffort;
                    pq.push({newEffort, {X, Y}});
                }
            }
        }
    }
    // if not reachable... which is not possible 🙂
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> v1;
    v1.push_back({1, 2, 2});
    v1.push_back({3, 8, 2});
    v1.push_back({5, 3, 5});
    
    cout<<MinimumEffort(v1);

    return 0;
}