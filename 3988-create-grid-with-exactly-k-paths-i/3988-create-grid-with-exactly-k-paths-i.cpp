class Solution {
public:
    int a, b, K;
    vector<string> grid;
    vector<pair<int,int>> cells;
    int countPaths() {
        vector<vector<int>> dp(a, vector<int>(b, 0));
        dp[0][0] = 1;
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                if(grid[i][j] == '#') {
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0) continue;
                if(i > 0) dp[i][j] += dp[i - 1][j];
                if(j > 0) dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[a - 1][b - 1];
    }
    bool generate(int idx) {
        if(idx == cells.size()) return countPaths() == K;
        auto [i, j] = cells[idx];
        grid[i][j] = '.';
        if(generate(idx + 1)) return true;
        grid[i][j] = '#';
        if(generate(idx + 1)) return true;
        return false;
    }
    vector<string> createGrid(int m, int n, int k) {
        K = k;
        a = min(m, 4);
        b = min(n, 4);
        grid.assign(a, string(b, '.'));
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                if(i == 0 && j == 0) continue;
                if(i == a - 1 && j == b - 1) continue;
                cells.push_back({i, j});
            }
        }
        if(!generate(0)) return {};
        vector<string> ans(m, string(n, '#'));
        for(int i = 0; i < a; i++) {
            for(int j = 0; j < b; j++) {
                ans[i][j] = grid[i][j];
            }
        }
        for(int j = b; j < n; j++) ans[a - 1][j] = '.';
        for(int i = a; i < m; i++) ans[i][n - 1] = '.';
        return ans;
    }
};