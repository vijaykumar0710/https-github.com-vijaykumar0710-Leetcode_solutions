class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>t(n,vector<int>(2,1));
        int res=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) t[i]=t[i-1];
            if(nums[i]-nums[i-1]==1) t[i][0]=max(t[i][0],t[i-1][0]+1);
            if(nums[i]-nums[i-1]==2) t[i][0]=max(t[i][0],t[i-1][1]+1);
            if(nums[i]-nums[i-1]==0) t[i][1]=max(t[i][1],t[i-1][0]+1);
            if(nums[i]-nums[i-1]==1) t[i][1]=max(t[i][1],t[i-1][1]+1);
            res=max({res,t[i][0],t[i][1]});
        }
        return res;
    }
};