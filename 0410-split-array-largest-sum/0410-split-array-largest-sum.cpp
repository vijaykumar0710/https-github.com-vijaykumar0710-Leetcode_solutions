class Solution {
public:
    bool isValid(int k, vector<int>& nums, long long mid) {
        int n = nums.size();
        int cnt_sub = 0;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum + nums[i] > mid) {
                cnt_sub++;
                sum = nums[i];
            } else {
                sum += nums[i];
            }
        }
        return cnt_sub<=k-1;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int l = INT_MIN;
        long long r = 0;
        for (auto num : nums) {
            l = max(l, num);
            r += num;
        }
        long long res = r;
         while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (isValid(k, nums, mid)) {
                res = min(res,mid);
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return res;
    }
};