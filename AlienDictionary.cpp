#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back


string bfs(int n, int k, vector<string> &dict) {
	vector<int> adj[k], InDegree(k, 0);
	for (int i = 1; i < n; i++) {
		string prev = dict[i - 1], curr = dict[i];
		int sizePrev = prev.size(), sizeCurr = curr.size();
		for (int j = 0; j < min(sizePrev, sizeCurr); j++) {
			if (prev[j] != curr[j]) {
				adj[prev[j] - 'a'].push_back(curr[j] - 'a');
				InDegree[curr[j] - 'a']++;
				break;
			}
		}
	}
	queue<int> q1;
	for (int i = 0; i < k; i++) {
		if (InDegree[i] == 0)      q1.push(i);
	}
	string res = "";
	while (q1.size()) {
		int from = q1.front();
		res += char(from + 'a');
		q1.pop();
		for (int &it : adj[from]) {
			if (--InDegree[it] == 0)   q1.push(it);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> dict;
	int N, K;

	// // testCase -> 1
	N = 5, K = 4;
	dict.push_back("baa");
	dict.push_back("abcd");
	dict.push_back("abca");
	dict.push_back("cab");
	dict.push_back("cad");


	// **********  BFS ****************
	cout << bfs(N, K, dict);

	return 0;
}