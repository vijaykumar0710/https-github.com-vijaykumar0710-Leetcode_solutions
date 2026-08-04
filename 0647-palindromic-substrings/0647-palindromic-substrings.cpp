class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int res = n;
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <=n-len; i++) {
                int j = len + i - 1;
                if (len == 1)
                    dp[i][i] = 1;
                else {
                    if (s[i] == s[j] && (dp[i + 1][j - 1] || len == 2)) {
                        dp[i][j] = 1;
                        res++;
                    }
                }
            }
        }
        return res;
    }
};