class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long res=-1e16;
        long long even0=-1e16,odd0=-1e16;
        long long even1=-1e16,odd1=-1e16;
        for(int i=0;i<n;i++){
           long long new_even0=max(1LL*nums[i],odd0+nums[i]);
           long long new_odd0=even0-nums[i];
           long long new_even1=max(even0,odd1+nums[i]);
           long long new_odd1=max(odd0,even1-nums[i]);
           res=max({res,new_even0,new_odd0,new_even1,new_odd1});
           even0=new_even0;
           odd0=new_odd0;
           even1=new_even1;
           odd1=new_odd1;
        }
        return res;
    }
};