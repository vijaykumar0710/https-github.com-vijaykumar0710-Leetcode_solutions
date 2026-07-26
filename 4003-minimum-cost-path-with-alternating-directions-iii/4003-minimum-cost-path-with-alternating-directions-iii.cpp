class Solution {
public:
    int RD[2][2] = {{0, 1}, {1, 0}};
    int LU[2][2] = {{0, -1}, {-1, 0}};
    long long EC(int r, int c) {return (long long)(r + 1) * (c + 1);} 
    void costfn(long long curr_cost, long long penalty_cost, int new_r, int new_c, int next_p, int m, int n, vector<vector<vector<long long>>>& dist, priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>>& pq) {
        long long new_total_cost = curr_cost + penalty_cost;
        if (new_total_cost < dist[new_r][new_c][next_p]) {
            dist[new_r][new_c][next_p] = new_total_cost;
            pq.push({new_total_cost, (long long)new_r, (long long)new_c, (long long)next_p});
        }
    }
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        vector<vector<vector<long long>>> dist(m,vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));       
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
        dist[0][0][1] = EC(0, 0);
        pq.push({dist[0][0][1], 0, 0, 1});
        while (!pq.empty()) {
            vector<long long> curr = pq.top();
            pq.pop();
            long long curr_cost = curr[0];
            int r = (int)curr[1];
            int c = (int)curr[2];
            int p = (int)curr[3];
            if (r == m - 1 && c == n - 1)
                return curr_cost;
            int next_p = 1 - p;
            long long curr_penalty = penalty[r][c];
            costfn(curr_cost, curr_penalty, r, c, next_p, m, n, dist, pq);
            for (auto& dir : RD) {
                int new_r = r + dir[0];
                int new_c = c + dir[1];
                if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n) {
                    long long cost = EC(new_r, new_c) + (p == 1 ? 0 : curr_penalty);
                    costfn(curr_cost, cost, new_r, new_c, next_p, m, n, dist, pq);
                }
            }
            for (auto& dir : LU) {
                int new_r = r + dir[0];
                int new_c = c + dir[1];
                if (new_r >= 0 && new_r < m && new_c >= 0 && new_c < n) {
                    long long cost = EC(new_r, new_c) + (p == 0 ? 0 : curr_penalty);
                    costfn(curr_cost, cost, new_r, new_c, next_p, m, n, dist, pq);
                }
            }
        }
        return min(dist[m - 1][n - 1][0], dist[m - 1][n - 1][1]);
    }
};