class Solution {
public:
    bool three_sum(vector<int> temp) {
        int n=temp.size();
        vector<int> nums = temp;
        sort(nums.begin(), nums.end());
        set<int>st(temp.begin(),temp.end());
        for (int i = 0; i < nums.size(); i++) {
           for(int j=i+1;j<n;j++){
             if(st.count(nums[i]+nums[j])) return false;
           }
        }
        return true;
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