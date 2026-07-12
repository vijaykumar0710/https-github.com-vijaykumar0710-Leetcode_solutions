class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        int a = min(m, 4);
        int b = min(n, 4);
        vector<pair<int, int>> cells;
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                if(i == 0 && j == 0) continue;
                if(i == a - 1 && j == b - 1) continue;
                cells.push_back({i, j});
            }
        }
        int sz = cells.size();
        for(int mask = 0; mask < (1 << sz); mask++) {
            vector<string> gadget(a, string(b, '.'));
            for(int bit = 0; bit < sz; bit++) {
                if(mask & (1 << bit)) {
                    auto [i, j] = cells[bit];
                    gadget[i][j] = '#';
                }
            }
            vector<vector<int>> dp(a, vector<int>(b, 0));
            dp[0][0] = 1;
            for(int i = 0; i < a; i++) {
                for(int j = 0; j < b; j++) {
                    if(gadget[i][j] == '#') {
                        dp[i][j] = 0;
                        continue;
                    }
                    if(i == 0 && j == 0) continue;
                    if(i > 0) dp[i][j] += dp[i - 1][j];
                    if(j > 0) dp[i][j] += dp[i][j - 1];
                }
            }
            if(dp[a - 1][b - 1] != k) continue;
            vector<string> ans(m, string(n, '#'));
            for(int i = 0; i < a; i++) {
                for(int j = 0; j < b; j++) {
                    ans[i][j] = gadget[i][j];
                }
            }
            for(int j = b; j < n; j++)
                ans[a - 1][j] = '.';
            for(int i = a; i < m; i++)
                ans[i][n - 1] = '.';
            return ans;
        }
        return {};
    }
};