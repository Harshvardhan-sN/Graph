#include<bits/stdc++.h>
using namespace std;

#define ll long long

class DisjointSet {
public:
    vector<int> rank, parent, size;
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

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    int n = accounts.size();
    unordered_map<string, int> mapMail;
    DisjointSet ds(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < accounts[i].size(); ++j) {
            string mail = accounts[i][j];
            if (!mapMail.count(mail))
                mapMail[mail] = i;
            else
                ds.unionSize(i, mapMail[mail]);
        }
    }
    vector<string> mergeMail[n];
    for (auto &it : mapMail) {
        string mail = it.first;
        int node = ds.findPar(it.second);
        mergeMail[node].push_back(mail);
    }
    vector<vector<string>> res;
    for (int i = 0; i < n; ++i) {
        if (mergeMail[i].size()) {
            sort(mergeMail[i].begin(), mergeMail[i].end());
            vector<string> temp(mergeMail[i].begin(), mergeMail[i].end());
            temp.insert(temp.begin(), accounts[i][0]);
            res.push_back(temp);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);


    vector<vector<string>> accounts{
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };

    vector<vector<string>> ans = accountsMerge(accounts);
    for (auto &it : ans) {
        for (auto &i : it)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}