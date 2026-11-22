class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n=nums.size();
        long long res=LLONG_MAX;
        for(int i=1;i<n-1;i++){
            int j=i-1;
            while(j>=0 && nums[j]==nums[i]) j--;
            long long cost=1LL*(j+1)*nums[i];
            j=i+1;
            while(j<n && nums[j]==nums[i]) j++;
            cost=cost+1LL*(n-j)*nums[i];
            res=min(res,cost);
            i=j-1;
        }
        return res;
    }
};