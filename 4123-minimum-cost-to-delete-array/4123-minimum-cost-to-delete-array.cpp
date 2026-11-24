class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n=nums.size();
        vector<int>odds;
        int mini_even=INT_MAX;
        long long res=0LL;
        for(int i=1;i<n-1;i++){
        if(nums[i]>=0) mini_even=min(mini_even,nums[i]);
        if(nums[i]<0) odds.push_back(nums[i]);
        }
        sort(odds.begin(),odds.end());
        long long sum=accumulate(odds.begin(),odds.end(),0LL);
        if(odds.size()%2==0)
            res=sum+nums[0]+nums[n-1];
        else{
            long long ans=min(sum+mini_even,sum-odds[odds.size()-1]);
            res=ans+nums[0]+nums[n-1];
        }
        return res;
    }
};