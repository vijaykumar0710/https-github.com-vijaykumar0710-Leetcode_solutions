class Solution {
public:
int n;
int t[1001][5001];
int solve(int i,int sum,vector<int>&nums){
    if(sum==0) return 0;
    if(i==n || sum<0) return 1e9;
    if(t[i][sum]!=-1) return t[i][sum];
    int ans=1e9;
    // skip
    ans=min(ans,solve(i+1,sum,nums));
    // take 
    int div_val=nums[i];
    int div_cost=0;
    while(true){
        long long mul_val=div_val;
        int mul_cost=0;
        while(mul_val<=sum){
            if(mul_val>0){
                int total_cost=div_cost+mul_cost;
                ans=min(ans,total_cost+solve(i+1,sum-mul_val,nums));
            }
            if(mul_val==0) break;
            mul_val*=2;
            mul_cost++;
        }
        if(div_val==0) break;
        div_val/=2;
        div_cost++;
    }
    return t[i][sum]=ans;
}
    int minOperations(vector<int>& nums, int sum) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        int res=solve(0,sum,nums);
        return res==1e9?-1:res;
    }
};