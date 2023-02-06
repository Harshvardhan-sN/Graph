#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

#define all(x) x.begin(),x.end()
#define nl endl
#define FOR(i,j,n) for(int i = j; i < n; i++)
#define pb push_back

// My Code
void my_dfs(vector<vector<int>> &ad, vector<vector<bool>> &vis, int x , int y, int val, int color) {
	vis[x][y] = 1;
	ad[x][y] = color;
	int n = ad.size();
	int m = ad[0].size();
	for (int i = -1; i <= 1; i += 2) {
		int dx = x + i;
		int dy = y + i;
		if (dx >= 0 and dx<n and y >= 0 and y < m and !vis[dx][y] and ad[dx][y] == val) {
			my_dfs(ad, vis, dx, y, val, color);
		}
		if (dy >= 0 and dy<m and x >= 0 and x < n and !vis[x][dy] and ad[x][dy] == val) {
			my_dfs(ad, vis, x, dy, val, color);
		}
	}
}
void FloodFillAlgorithm(vector<vector<int>> &ad, int x, int y, int color) {
	int n = ad.size();
	int m = ad[0].size();
	vector<vector<bool>> vis(n, vector<bool> (m, 0));
	int val = ad[x][y];
	my_dfs(ad, vis, x, y, val, color);
}


// *********   Optimal Code   ********

void dfs(int x, int y, vector<vector<int>> &ans, vector<vector<int>> &image, int dx[], int dy[], int val, int color) {
	ans[x][y] = color;
	int n = image.size();
	int m = image[0].size();
	for (int i = 0; i < 4 ; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if (X >= 0 and X<n and Y >= 0 and Y < m and ans[X][Y] == val) {
			dfs(X, Y, ans, image, dx, dy, val, color);
		}
	}
}

vector<vector<int>> floodfill(vector<vector<int>> &image, int x, int y, int color ) {
	int val = image[x][y];
	vector<vector<int>> ans = image;
	int dx[] = { -1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};
	dfs(x, y, ans, image, dx, dy, val, color);
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;        cin >> n >> m;

	vector<vector<int>> ad;
	FOR(i, 0, n) {
		vector<int> a;
		FOR(j, 0, m) {
			int x;  cin >> x;
			a.pb(x);
		}
		ad.pb(a);
	}
	int x, y;        cin >> x >> y;
	int val;        cin >> val;
	// FloodFillAlgorithm(ad,x,y,val);
	// for(auto &it: ad){
	//     for(auto &i: it)    cout<<i<<" ";
	//     cout<<nl;
	// }

	vector<vector<int>> ans = floodfill(ad, x, y, val);
	for (auto &it : ans) {
		for (auto &i : it)    cout << i << " ";
		cout << nl;
	}
	return 0;
}
