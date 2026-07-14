class Solution {
public:
const int M=1e9+7;
int t[201][201][201];
int f(int i,int gcd1,int gcd2,vector<int>&nums,int n){
    if(i>=n){
        if(gcd1==gcd2) return 1;
        return 0;
    }
    if(t[i][gcd1][gcd2]!=-1) return t[i][gcd1][gcd2];
    int res=0;
    res=(res+f(i+1,gcd1,gcd2,nums,n))%M;
    res=(res+f(i+1,gcd(gcd1,nums[i]),gcd2,nums,n))%M;
    res=(res+f(i+1,gcd1,gcd(gcd2,nums[i]),nums,n))%M;
    return t[i][gcd1][gcd2]=res%M;
}
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return f(0,0,0,nums,n)-1;
    }
};