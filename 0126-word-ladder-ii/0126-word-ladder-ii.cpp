class Solution {
private:
    void dfs(string word, string beginWord,
             unordered_map<string, vector<string>>& adj, vector<string>& path,
             vector<vector<string>>& ans) {

        if (word == beginWord) {
            reverse(path.begin(), path.end());
            ans.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        for (auto& next : adj[word]) {
            path.push_back(next);
            dfs(next, beginWord, adj, path, ans);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        vector<vector<string>> ans;

        if (!st.count(endWord))
            return ans;

        unordered_map<string, vector<string>> adj;

        unordered_map<string, int> dist;
        queue<string> q;

        q.push(beginWord);
        dist[beginWord] = 0;

        while (!q.empty()) {
            string word = q.front();
            q.pop();

            int currDist = dist[word];

            for (int i = 0; i < word.size(); i++) {
                string temp = word;

                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == word[i])
                        continue;

                    temp[i] = ch;

                    if (!st.count(temp))
                        continue;

                    if (!dist.count(temp)) {
                        dist[temp] = currDist + 1;
                        q.push(temp);

                        adj[temp].push_back(word);
                    }

                    else if (dist[temp] == currDist + 1) {
                        adj[temp].push_back(word);
                    }
                }
            }
        }

        if (!dist.count(endWord))
            return ans;

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, adj, path, ans);

        return ans;
    }
};