class Solution {
public:
int t[1001][51];
int n;
int solve(int i,int cuts,vector<int>&prefix){
if(cuts==0) return prefix[n]-prefix[i];
if(i>=n) return INT_MAX;
if(t[i][cuts]!=-1) return t[i][cuts];
int res=INT_MAX;
for(int j=i+1;j<n;j++){
    int sum=prefix[j]-prefix[i];
    res=min(res,max(sum,solve(j,cuts-1,prefix)));
}
return t[i][cuts]=res;
}
    int splitArray(vector<int>& nums, int k) {
        n=nums.size();
        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++) prefix[i+1]=prefix[i]+nums[i];
        memset(t,-1,sizeof(t));
        return solve(0,k-1,prefix);
    }
};