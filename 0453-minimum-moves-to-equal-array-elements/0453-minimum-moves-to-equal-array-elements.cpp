class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=0;i<n;i++)
            res+=nums[i]-nums[0];
        return res;
    }
};