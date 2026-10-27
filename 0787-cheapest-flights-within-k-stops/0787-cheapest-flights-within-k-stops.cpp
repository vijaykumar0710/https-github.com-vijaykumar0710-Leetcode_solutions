class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> adj;
    int dijkstra(int src, int dst, int k,int n) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        vector<vector<int>>res(n,vector<int>(k+1,INT_MAX));
        for(int j=0;j<=k;j++) res[src][j]=0;
        pq.push({0, src, 0});
        while (!pq.empty()) {
            auto u = pq.top();
            pq.pop();
            int node = u[1], cost = u[0], limit = u[2];
            for (auto &v:adj[node]) {
                if (limit < k) {
                    if (cost + v.second < res[v.first][limit+1]) {
                        res[v.first][limit+1] = cost + v.second;
                        pq.push({res[v.first][limit+1], v.first,limit + 1});
                    }
                } else if (limit == k && v.first == dst) {
                    if (cost + v.second < res[v.first][k]) {
                        res[v.first][k] = cost + v.second;
                    }
                }
            }
        }
        int maxi=INT_MAX;
        for(int j=0;j<=k;j++){
            maxi=min(maxi,res[dst][j]);
        }
        return maxi==INT_MAX?-1:maxi;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for (auto e : flights) 
            adj[e[0]].push_back({e[1], e[2]});
       int res=dijkstra(src, dst, k,n);
        return res == INT_MAX ? -1 : res;
    }
};