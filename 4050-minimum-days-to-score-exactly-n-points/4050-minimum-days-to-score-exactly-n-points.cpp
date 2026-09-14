class Solution {
public:
int t[100001];
int solve(long long sum){
    if(sum==0) return 0;
    if(t[sum]!=-1) return t[sum];
   int res=INT_MAX;
   for(int i=1;(i*(i+1))/2<=sum;i++){
    long long x=(i*(i+1))/2;
    if(sum-x>0){
        int sub=solve(sum-x);
        if(sub!=INT_MAX){
            res=min(res,(i+1+sub));
        }
    }else if(sum-x==0){
        res=min(res,i);
    }
   }
   return t[sum]=res;
}
    int minDays(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};