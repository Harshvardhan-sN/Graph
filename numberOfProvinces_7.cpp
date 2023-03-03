#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

#define all(x) x.begin(),x.end()
#define nl endl
#define FOR(i,j,n) for(int i = j; i < n; i++)
#define pb push_back

class DisjointSet {
    vector<int> rank, parent, size;
public:    
    DisjointSet(int n) {
        for (int i = 0; i <= n; ++i) {
            parent.push_back(i);
            rank.push_back(0);
            size.push_back(1);
        }
    }
    int findPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionRank(int u, int v) {
        int Upar_u = findPar(u);
        int Upar_v = findPar(v);
        if (Upar_u == Upar_v)     return;
        if (rank[Upar_u] < rank[Upar_v]) {
            parent[Upar_u] = Upar_v;
        }
        else if (rank[Upar_v] < rank[Upar_u]) {
            parent[Upar_v] = Upar_u;
        }
        else {
            parent[Upar_v] = Upar_u;
            ++rank[Upar_u];
        }
    }
    void unionSize(int u, int v) {
        int Upar_u = findPar(u);
        int Upar_v = findPar(v);
        if (Upar_u == Upar_v)     return;
        if (size[Upar_u] < size[Upar_v]) {
            parent[Upar_u] = Upar_v;
            size[Upar_v] += size[Upar_u];
        } else {
            parent[Upar_v] = Upar_u;
            size[Upar_u] += size[Upar_v];
        }
    }
};

int DisjointSetSolution(vector<vector<int>> &ad, int N){
	DisjointSet ds(V);
        for(int i = 0; i < V; ++i){
            int u = i;
            for(int j = 0; j < adj[i].size(); ++j){
                if(adj[i][j] == 1)
                    ds.unionRank(i, j);
            }
            ds.findPar(i);
        }
        int res = 0;
        for(int i = 0; i < V; ++i)
            res += (ds.findPar(i) == i);
        return res;	
}
void dfs(vector<vector<int>> &ad, vector<bool> &vis , int N) {
	vis[N] = 1;
	FOR(i, 0, ad[N].size()) {
		if (ad[N][i] && !vis[i]) {
			dfs(ad, vis, i);
		}
	}
}

int numberOfProvinces(vector<vector<int>> &ad, int N) {
	vector<bool> vis(N, 0);
	int pro = 0;
	for (int i = 1; i < N; i++) {
		if (!vis[i]) {
			dfs(ad, vis, i);
			pro++;
		}
	}
	return pro;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	// Matrix
	int n;  cin >> n;
	vector<vector<int>> v1;
	FOR(i, 0, n) {
		vector<int> a;
		FOR(j, 0, n) {
			int x;  cin >> x;
			a.pb(x);
		}
		v1.pb(a);
	}
	cout << numberOfProvinces(v1, n);

	return 0;
}
