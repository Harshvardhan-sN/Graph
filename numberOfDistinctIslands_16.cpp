#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

int dis[5] = {0, -1, 0, 1, 0};
void bfs(int r, int c, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &vp, pair<int, int> base) {
	queue<pair<int, int>> q1;
	q1.push({r, c});
	vis[r][c] = 1;
	while (!q1.empty()) {
		int R = q1.front().first;
		int C = q1.front().second;
		q1.pop();
		for (int i = 0; i < 4; i++) {
			int nR = R + dis[i];
			int nC = C + dis[i + 1];
			if (nR >= 0 and nC >= 0 and nR < n and nC < m and !vis[nR][nC] and grid[nR][nC]) {
				int l1 = nR - base.first;
				int l2 = nC - base.second;
				vp.push_back({l1, l2});
				vis[nR][nC] = 1;
				q1.push({nR, nC});
			}
		}
	}
}
void dfs(int r, int c, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int, int>> &vp, pair<int, int> base) {
	vis[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int nR = r + dis[i];
		int nC = c + dis[i + 1];
		if (nR >= 0 and nC >= 0 and nR < n and nC < m and !vis[nR][nC] and grid[nR][nC] == 1) {
			int l1 = nR - base.first;
			int l2 = nC - base.second;
			vp.push_back({l1, l2});
			dfs(nR, nC, n, m, grid, vis, vp, base);
		}
	}
}
int countDistinctIslands(vector<vector<int>>& grid) {
	int n = grid.size(), m = grid[0].size();
	vector<vector<int>> vis(n, vector<int>(m, 0));
	set<vector<pair<int, int>>> s1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] and grid[i][j] == 1) {
				vector<pair<int, int>> vp;
				pair<int, int> base(i, j);
				vp.push_back({0, 0});
				dfs(i, j, n, m, grid, vis, vp, base);
				// bfs(i, j, n, m, grid, vis, vp, base);
				s1.insert(vp);
			}
		}
	}
	return (int)s1.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;    cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m , 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	cout << countDistinctIslands(grid);

	return 0;
}
