#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

struct S {
	int x, y, z;
};

int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<vector<int>>nearest(vector<vector<int>>&grid)
{
	int n = grid.size(), m = grid[0].size();
	vector<vector<bool>> vis(n, vector<bool>(m , 0));
	vector<vector<int>> res(n, vector<int>(m , 0));
	queue<S> q1;
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 1) { 
                q1.push({i, j, 0});
                vis[i][j] = 1;
                res[i][j] = 0;
			}
		}
	}
    
	while (!q1.empty()) {
		int R = q1.front().x;
		int C = q1.front().y;
		int V = q1.front().z + 1;
		q1.pop();
		for (int i = 0; i < 4; i++) {
			int nRow = R + dx[i];
			int mCol = C + dy[i];
			if (nRow >= 0 && mCol >= 0 &&
                    nRow < n && mCol < m &&
                        grid[nRow][mCol] == 0 && !vis[nRow][mCol]) {
                            q1.push({nRow, mCol, V});
				            vis[nRow][mCol] = 1;
				            res[nRow][mCol] = V;
			}
		}
	}
	return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;        cin>>n>>m;
    vector<vector<int>> grid;
    for(int i=0; i<n; i++){
        vector<int> a;
        for(int j=0; j<m; j++){
            int c;  cin>>c;
            a.pb(c);
        }
        grid.pb(a);
    }
    cout<<nl;
    vector<vector<int>> ans = nearest(grid);
    for(auto &it: ans){
        for(auto &i: it)  cout<<i<<" ";
        cout<<nl;
    }

    return 0;
}