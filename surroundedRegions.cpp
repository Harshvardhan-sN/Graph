#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

int dis[5] = {0, -1, 0, 1, 0};

void dfs(int r, int c, int n, int m, vector<vector<char>> &mat, vector<vector<char>> &res, vector<vector<bool>> &vis) {
	vis[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int nR = r + dis[i];
		int nC = c + dis[i + 1];
		if (nR >= 0 and nC >= 0 and nR < n and nC < m and !vis[nR][nC] and mat[nR][nC] == 'O') {
			res[nR][nC] = 'O';
			dfs(nR, nC, n, m, mat, res, vis);
		}
	}
}

void bfs(queue<pair<int, int>> q1, int n, int m, vector<vector<char>> &mat, vector<vector<char>> &res, vector<vector<bool>> &vis) {
	while (!q1.empty()) {
		int r = q1.front().first;
		int c = q1.front().second;
		q1.pop();
		for (int i = 0; i < 4; i++) {
			int nR = r + dis[i];
			int nC = c + dis[i + 1];
			if (nR >= 0 and nC >= 0 and nR < n and nC < m and !vis[nR][nC] and mat[nR][nC] == 'O') {
				res[nR][nC] = 'O';
				vis[nR][nC] = 1;
				q1.push({nR, nC});
			}
		}
	}
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> &mat) {
	vector<vector<bool>> vis(n, vector<bool>(m, 0));
	vector<vector<char>> res(n, vector<char>(m, 'X'));
	queue<pair<int, int>> q1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i == 0 || i == n - 1) || (i > 0 and i < n - 1 and (j == 0 || j == m - 1))) {
				if (mat[i][j] == 'O') {
					res[i][j] = 'O';

					// -> for bfs
					q1.push({i, j});
					vis[i][j] = 1;

					// // -> for dfs
					// dfs(i, j, n, m, mat, res, vis);
				}
			}
		}
	}
	bfs(q1, n, m, mat, res, vis);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n, m;    cin >> n >> m;
	vector<vector<char>> mat;
	for (int i = 0; i < n; i++) {
		vector<char> a;
		for (int j = 0; j < m; j++) {
			char ch;    cin >> ch;
			a.pb(ch);
		}
		mat.pb(a);
	}
	cout << nl;
	vector<vector<char>> res = fill(n, m, mat);
	for (auto &it : res) {
		for (auto &i : it)    cout << i << " ";
		cout << nl;
	}


	return 0;
}

