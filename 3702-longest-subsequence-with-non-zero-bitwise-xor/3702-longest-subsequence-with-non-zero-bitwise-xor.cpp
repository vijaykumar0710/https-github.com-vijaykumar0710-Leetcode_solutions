class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size(),val=0,flag=1;
        for(auto x:nums){
            val^=x;
            if(val!=0) flag=0;
        }
        if(flag) return 0;
        return val!=0?n:n-1;
    }
};