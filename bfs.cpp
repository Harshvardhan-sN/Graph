#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

#define all(x) x.begin(),x.end()
#define nl endl
#define FOR(i,n) for(int i = 0; i < n; i++)
#define pb push_back

const int N = 1e7 + 10;
const ll MOD = 1e7 + 1;

vector<int> bfsOfGraph(int n, vector<vector<int>> &ad) {
	vector<bool> visited(n, 0);         // Visited Array
	visited[0] = 1;                     // Mark 1st node as visited
	queue<int> q;
	q.push(0);                          // Push it in Queue
	vector<int> bfs;
	while (!q.empty()) {                // Take out the nodes one by one till its empty
		int node = q.front();
		q.pop();
		bfs.pb(node);
		for (auto &it : ad[node]) {     // Check for the neighbors in list
			if (!visited[it]) {         // If not visited Insert them in queue and mark them as visited
				visited[it] = 1;
				q.push(it);
			}
		}
	}
	return bfs;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int e, v;    cin >> e >> v;
	vector<vector<int>> v1(e, vector<int> (2));
	for (int i = 0; i < v; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> v1[i][j];
		}
	}

	vector<int> ans =  bfsOfGraph(e, v1);
	for (auto &it : ans) {
		cout << it << " ";
	}

	return 0;
}