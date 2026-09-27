class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n=nums.size();
        int res=0,maxi=0;
        map<pair<int,int>,int>mp;
        for(int i=0;i<n-1;i++){ 
         if(nums[i]==nums[i+1]) res++;
         else mp[{max(nums[i],nums[i+1]),min(nums[i],nums[i+1])}]++;
         maxi=max(maxi,mp[{max(nums[i],nums[i+1]),min(nums[i],nums[i+1])}]);
        }
        return res+maxi;
    }
};