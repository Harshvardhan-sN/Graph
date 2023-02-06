#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

int dis[5] = {0, -1, 0, 1, 0};
void dfs(int r, int c, int n, int m, vector<vector<bool>> &grid, vector<vector<bool>> &vis) {
	vis[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int nR = r + dis[i];
		int nC = c + dis[i + 1];
		if (nR >= 0 and nC >= 0 and nR < n and nC < m and !vis[nR][nC] and grid[nR][nC]) {
			dfs(nR, nC, n, m, grid, vis);
		}
	}
}

void bfs(queue<pair<int, int>> &q1, int n, int m, vector<vector<bool>> &grid, vector<vector<bool>> &vis) {
	while (!q1.empty()) {
		int r = q1.front().first;
		int c = q1.front().second;
		q1.pop();
		for (int i = 0; i < 4; i++) {
			int nR = r + dis[i];
			int nC = c + dis[i + 1];
			if (nR >= 0 and nC >= 0 and nR < n and nC < m and !vis[nR][nC] and grid[nR][nC]) {
				vis[nR][nC] = 1;
				q1.push({nR, nC});
			}
		}
	}
}

int numberOfEnclaves(vector<vector<bool>> &grid) {
	int n = grid.size(), m = grid[0].size(), res = 0;
	vector<vector<bool>> vis(n, vector<bool>(m, 0));
	queue<pair<int, int>> q1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ( (i == 0 || i == n - 1) || (i > 0 and i < n - 1 and (j == 0 || j == m - 1)) ) {
				if (!vis[i][j] and grid[i][j]) {
					// // for dfs
					// dfs(i, j, n, m, grid, vis);

					// // for bfs
					q1.push({i, j});
					vis[i][j] = 1;
				}
			}
		}
	}
	bfs(q1, n, m, grid, vis);
	for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            res += grid[i][j] > vis[i][j];
        }
    }
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// given binary matrix
	int n, m;    cin >> n >> m;
	vector<vector<bool>> grid;
	for (int i = 0; i < n; i++) {
		vector<bool> a;
		for (int j = 0; j < m; j++) {
			bool b1;    cin >> b1;
			a.pb(b1);
		}
		grid.pb(a);
	}

	cout << (numberOfEnclaves(grid));

	return 0;
}
