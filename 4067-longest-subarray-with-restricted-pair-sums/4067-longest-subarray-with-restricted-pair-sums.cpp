class Solution {
public:
    bool two_sum(vector<int>& nums, int target, int i, int j) {
        while (i < j) {
            if (nums[i] + nums[j] > target)
                j--;
            else if (nums[i] + nums[j] < target)
                i++;
            else return false;
        }
        return true;
    }
    bool three_sum(vector<int> nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        bool flag = true;
        for (int i = n-1; i>=0; i--) {
            flag &= two_sum(nums, nums[i], 0, i-1);
        }
        return flag;
    }
    bool fn(vector<int>& nums, int len) {
        int n = nums.size();
        for (int i = 0; i <= n - len; i++) {
            vector<int> temp(nums.begin() + i, nums.begin() + i + len);
            if (three_sum(temp)) {
                return true;
            }
        }
        return false;
    }
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 1, r = n;
        int res = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (fn(nums, mid)) {
                res = max(mid, res);
                l = mid + 1;
            } else
                r = mid - 1;
        }
        return res;
    }
};