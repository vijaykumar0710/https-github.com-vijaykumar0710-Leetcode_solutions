class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 1);
        int lis = 1;
        for (int i = 0; i < n; i++) {
             int max_len = 0;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    max_len = max(max_len, t[j]);
                }
            }
            t[i] = 1 + max_len;
            lis = max(lis, t[i]);
        }
        return lis;
    }
};