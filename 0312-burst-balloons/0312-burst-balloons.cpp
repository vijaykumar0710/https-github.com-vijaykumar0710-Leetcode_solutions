class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 1; len <= n - 2; len++) {
            for (int l = 1; l + len - 1 <= n - 2; l++) {
                int r = len + l - 1;
                for (int k = l; k <= r; k++)
                    dp[l][r] = max(dp[l][r],dp[l][k - 1] + dp[k + 1][r] + (nums[l - 1] * nums[k] * nums[r + 1]));
            }
        }
        return dp[1][n - 2];
    }
};