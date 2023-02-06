#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

#define all(x) x.begin(),x.end()
#define nl endl
#define FOR(i,j,n) for(int i = j; i < n; i++)
#define pb push_back

void bfs(int x, int y, vector<vector<int>> &ad, vector<vector<bool>> &vis) {
	vis[x][y] = 1;
	int n = ad.size();
	int m = ad[0].size();
	queue<pair<int, int>> q1;
	q1.emplace(x, y);
	while (!q1.empty()) {
		int dx = q1.front().first;
		int dy = q1.front().second;
		q1.pop();
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				int new_x = dx + i;
				int new_y = dy + j;
				if (new_x >= 0 and new_x<n and new_y >= 0 and new_y < m
				        and !vis[new_x][new_y] and ad[new_x][new_y]) {
					vis[new_x][new_y] = 1;
					q1.emplace(new_x, new_y);
				}
			}
		}
	}
}

void dfs(int x, int y, vector<vector<int>> &ad, vector<vector<bool>> &vis ) {
	vis[x][y] = 1;
	int n = ad.size();
	int m = ad[0].size();
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			int dx = x + i;
			int dy = y + j;
			if (dx >= 0 and dx<n and dy >= 0 and dy < m and
			        !vis[dx][dy] and ad[dx][dy]) {
				dfs(dx, dy, ad, vis);
			}
		}
	}
}

int numberOfisland(int n, int m, vector<vector<int>> &ad) {
	vector<vector<bool>> vis(n, vector<bool> (m, 0));
	int c = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!vis[i][j] and ad[i][j] == 1) {
				c++;
				bfs(i, j, ad, vis);
			}
		}
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;    cin >> n >> m;
	vector<vector<int>> v1;
	FOR(i, 0, n) {
		vector<int> a;
		FOR(j, 0, m) {
			int x;      cin >> x;
			a.pb(x);
		}   v1.pb(a);
	}

	cout << numberOfisland(n, m, v1) << nl;

	return 0;
}
