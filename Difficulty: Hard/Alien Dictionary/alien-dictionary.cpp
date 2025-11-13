class Solution {
  private:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);

        // compute indegree
        for (int u = 0; u < V; u++) {
            for (int v : adj[u])
                indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++)
            if (indegree[i] == 0)
                q.push(i);

        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }
        return order;
    }
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size();
        vector<vector<int>> adj(26); 

        // Build graph from word comparisons
        for (int i = 0; i < n - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            int len = min(w1.size(), w2.size());
            bool found=false;
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                    found=true;
                    break;
                }
            }
            // Invalid case: "abc" before "ab"
            if (!found && w1.size() > w2.size())
                return "";
        }

        // Topological sort
        vector<int> topo = topoSort(26, adj);

        // Collect only the chars that appear in words
        unordered_set<char> present;
        for (auto &w : words)
            for (char c : w)
                present.insert(c);

        string ans = "";
        for (int i : topo)
            if (present.count('a' + i))
                ans += char('a' + i);

        // if not all chars are used -> cycle/invalid
        if (ans.size() < present.size())
            return "";
        return ans;
        
    }
};