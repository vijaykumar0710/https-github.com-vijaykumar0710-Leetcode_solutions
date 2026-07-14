class Solution {
public:
const int M=1e9+7;
int t[201][201][201];
int f(int i,vector<int>&nums,int gcd1,int gcd2,int n){
   if(i>=n){
    if(gcd1==gcd2) return 1;
    return 0;
   }
   int res=0;
   if(t[i][gcd1][gcd2]!=-1) return t[i][gcd1][gcd2];
   res=(res+f(i+1,nums,gcd1,gcd2,n))%M;
   res=(res+f(i+1,nums,gcd(gcd1,nums[i]),gcd2,n))%M;
   res=(res+f(i+1,nums,gcd1,gcd(gcd2,nums[i]),n))%M;
   return t[i][gcd1][gcd2]=res%M;
}
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        memset(t,-1,sizeof(t));
        return f(0,nums,0,0,n)-1;
    }
};