class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i){
                a.push_back(nums[i]);
                a.push_back(i);
                }
        }
        int res=0;
        if(!a.empty()) res=a[0];
        for (int i = 1; i < a.size(); i++) {
            res &= a[i];
        }
        return res;
    }
};