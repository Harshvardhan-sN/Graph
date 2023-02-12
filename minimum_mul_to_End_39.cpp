#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

int minimumMultiplications(vector<int>& arr, int start, int end) {
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> q1;
    long long mod = 100000, res = start;
    q1.push({0, res});
    vector<int> vis(100007, 1e9);
    vis[res] = 0;
    while (q1.size()) {
        long long curr = q1.top().second;
        int step = q1.top().first;
        q1.pop();
        if (curr == end)     return step;
        for (auto &it : arr) {
            long long diff = it * curr;
            if (diff > 1e5)
                diff %= mod;
            if (step + 1 < vis[diff]) {
                vis[diff] = step + 1;
                q1.push({vis[diff], diff});
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // tc 1
    vector<int> v1{2, 5, 7};
    int start = 3, end = 30;
    cout << minimumMultiplications(v1, start, end);

    cout << endl;
    // tc 2
    vector<int> v2{3, 4, 65};
    start = 7, end = 66175;   
    cout << minimumMultiplications(v2, start, end);
    
    return 0;
}