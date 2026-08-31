class Solution {
    public:
    int n;
    vector<vector<int>> memo;
    int solve(int i, int current_sum, vector<int>& nums) {
        if (current_sum == 0) return 0;
        if (i == n || current_sum < 0) return 1e9;
        if (memo[i][current_sum] != -1) {
            return memo[i][current_sum];
        }
        int ans = 1e9;
        ans = min(ans, solve(i + 1, current_sum, nums));
        int div_val = nums[i];
        int div_cost = 0;
        while (true) {
            long long mul_val = div_val;
            int mul_cost = 0;
            while (mul_val <= current_sum) {
                if (mul_val > 0) {
                    int total_cost = div_cost + mul_cost;
                    ans = min(ans, total_cost + solve(i + 1, current_sum - mul_val, nums));
                }
                if (mul_val == 0) break; 
                mul_val *= 2;
                mul_cost++;
            }
            if (div_val == 0) break;
            div_val /= 2;
            div_cost++;
        }
        return memo[i][current_sum] = ans;
    }
    int minOperations(vector<int>& nums, int sum) {
        n = nums.size();
        memo.assign(n, vector<int>(sum + 1, -1));
        int result = solve(0, sum, nums);
        return result >= 1e9 ? -1 : result;
    }
};