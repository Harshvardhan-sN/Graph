#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long

#define all(x) x.begin(), x.end()
#define nl endl
#define FOR(i, j, n) for (int i = j; i < n; i++)
#define pb push_back


vector<vector<string>> findSequence(string &start, string &end, vector<string> &words) {
    queue<vector<string>> que;
    vector<vector<string>> res;
    unordered_set<string> wordSet(words.begin(), words.end());
    vector<string> wordOnLevel;
    wordOnLevel.push_back(start);
    que.push({start});
    int level = 0;
    while (!que.empty()) {
        vector<string> currentPath = que.front();
        que.pop();
        if (currentPath.size() > level) {
            level++;
            for (auto &it : wordOnLevel) {
                wordSet.erase(it);
            }
            wordOnLevel.clear();
        }
        string currentWord = currentPath.back();
        if (currentWord == end) {
            if (res.size() == 0 || res[0].size() == currentPath.size()) {
                res.push_back(currentPath);
            }
            else if (res[0].size() < currentPath.size())     break;
        }
        for (int i = 0; i < currentWord.size(); i++) {
            string temp = currentWord;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                temp[i] = ch;
                if (wordSet.find(temp) != wordSet.end()) {
                    currentPath.push_back(temp);
                    que.push(currentPath);
                    wordOnLevel.push_back(temp);
                    currentPath.pop_back();
                }
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> wordList;
    string start, end;

    // // testcase -> 1
    start = "der", end = "dfs";
    wordList.push_back("des");
    wordList.push_back("der");
    wordList.push_back("dfr");
    wordList.push_back("dgt");
    wordList.push_back("dfs");

    // testcase -> 2
    // start = "toon", end = "plea";
    // wordList.push_back("poon");
    // wordList.push_back("plee");
    // wordList.push_back("same");
    // wordList.push_back("poie");
    // wordList.push_back("plea");
    // wordList.push_back("plie");
    // wordList.push_back("poin");

    vector<vector<string>> res = findSequence(start, end, wordList);
    for (auto &words : res) {
        for (auto &it : words)    cout << it << " ";
        cout << endl;
    }

    return 0;
}
