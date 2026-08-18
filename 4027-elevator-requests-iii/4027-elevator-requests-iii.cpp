class Solution {
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        int k = requests.size();
        long long INF = 1e18; 
        vector<vector<long long>> dp(1 << k, vector<long long>(k, INF));
            for (int i = 0; i < k; i++) {
            long long travel_time = abs(start - requests[i][1]);
            long long arrival_time = requests[i][0];
            dp[1 << i][i] = max(travel_time, arrival_time);
        }    
           for (int mask = 1; mask < (1 << k); mask++) {
            for (int i = 0; i < k; i++) {
                if ((mask & (1 << i)) != 0) {
                    for (int j = 0; j < k; j++) {
                        if ((mask & (1 << j)) == 0) {
                            int next_mask = mask | (1 << j);
                            long long travel_time = abs(requests[i][1] - requests[j][1]);
                            long long arrival_time = requests[j][0];
                            long long ready_time = max(dp[mask][i] + travel_time, arrival_time);
                            dp[next_mask][j] = min(dp[next_mask][j], ready_time);
                        }
                    }
                }
            }
        }
        long long ans = INF;
        int full_mask = (1 << k) - 1;
        for (int i = 0; i < k; i++) {
            ans = min(ans, dp[full_mask][i]);
        }
        return ans;
    }
};