class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n=nums.size();
        map<pair<int,int>,int>mp;
        int res=0,max_fre=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]) res++;
            else{
                mp[{max(nums[i],nums[i+1]),min(nums[i],nums[i+1])}]++;
                max_fre=max(max_fre,mp[{max(nums[i],nums[i+1]),min(nums[i],nums[i+1])}]);
            }
        }
        return res+max_fre;
    }
};