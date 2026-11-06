class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        int m = queries.size();
        vector<int> ans(m);
        vector<pair<int,int>> q;
        for (int i = 0; i < m; i++) q.push_back({queries[i], i});
        sort(q.begin(), q.end()); 
        unordered_map<int,int> freq; 
        int L = 0, R = 0;
        int logsN = logs.size();

        for (auto [t, idx] : q) {
            while (R < logsN && logs[R][1] <= t) {
                int server = logs[R][0];
                freq[server]++;
                R++;
            }
            while (L < logsN && logs[L][1] < t - x) {
                int server = logs[L][0];
                freq[server]--;
                if (freq[server] == 0) freq.erase(server);
                L++;
            }
            ans[idx] = n - freq.size();
        }
        return ans;
    }
};