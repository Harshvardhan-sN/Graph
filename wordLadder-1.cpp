#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back

int bfs(vector<string> &wordList, string &start, string &end) {
	unordered_set<string> st(wordList.begin(), wordList.end());
	queue<pair<string, int>> q1;
	q1.emplace(start, 1);
	st.erase(start);
	while (!q1.empty()) {
		string from = q1.front().first;
		int cost = q1.front().second;
		q1.pop();
		if (from == end)   return cost;
		for (int i = 0; i < from.size(); i++) {
			string temp = from;
			for (char ch = 'a'; ch <= 'z'; ch++) {
				temp[i] = ch;
				if (st.find(temp) != st.end()) {
					st.erase(temp);
					q1.emplace(temp, cost + 1);
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> wordList;
	string start, end;

	// // testcase -> 1
	// start = "der", end = "dfs";
	// wordList.push_back("des");
	// wordList.push_back("der");
	// wordList.push_back("dfr");
	// wordList.push_back("dgt");
	// wordList.push_back("dfs");

	// testcase -> 2
	start = "toon", end = "plea";
	wordList.push_back("poon");
	wordList.push_back("plee");
	wordList.push_back("same");
	wordList.push_back("poie");
	wordList.push_back("plea");
	wordList.push_back("plie");
	wordList.push_back("poin");

	cout << bfs(wordList, start, end);

	return 0;
}