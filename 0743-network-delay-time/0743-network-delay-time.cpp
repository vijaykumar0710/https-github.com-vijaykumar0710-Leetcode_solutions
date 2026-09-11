class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto vec : times) {
            int u = vec[0], v = vec[1], w = vec[2];
            adj[u].push_back({v, w});
        }
        vector<int> res(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        res[k] = 0;
        pq.push({0, k});
        while (!pq.empty()) {
            int node = pq.top().second;
            int w = pq.top().first;
            pq.pop();
            for (auto neigh : adj[node]) {
                int v = neigh.first, wt = neigh.second;
                if (w + wt < res[v]) {
                    res[v] = w + wt;
                    pq.push({w + wt, v});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,res[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};