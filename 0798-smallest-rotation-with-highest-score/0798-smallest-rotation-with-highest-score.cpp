class Solution {
public:
    int f(vector<int> nums, int k) {
        int m = nums.size();
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            int a = i - nums[i];
            mp[a]++;
            if (a >= 0)
                cnt++;
        }
        int best_cnt = cnt, st = 0;
        for (int l = 0; l < m - k; l++) {
            if (l - nums[l] >= l)
                cnt--;
            mp[l - nums[l]]--;
            mp[(l + k) - nums[l + k]]++;
            if ((l + k) - nums[l + k] >= l + 1)
                cnt++;
            cnt -= mp[l];
            if (best_cnt < cnt) {
                best_cnt = cnt;
                st = l+1;
            }
        }
        return st;
    }
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> vec;
        vec = nums;
        for (auto& x : nums)
            vec.push_back(x);
        return f(vec, n);
    }
};