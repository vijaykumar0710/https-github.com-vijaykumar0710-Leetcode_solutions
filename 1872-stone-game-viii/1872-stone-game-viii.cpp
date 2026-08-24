class Solution {
public:
int t[100005][2];
int fn(int i,int fl,vector<int>&ps,int n){
    if(i==n-1){
        return fl==0?ps[i]:-ps[i];
    }
    if(t[i][fl]!=-1) return t[i][fl];
    int res=0;
    if(fl==0){
        int take=ps[i]+fn(i+1,1,ps,n);
        int skip=fn(i+1,0,ps,n);
        res=max(take,skip);
    }
    else{
        int take=-ps[i]+fn(i+1,0,ps,n);
        int skip=fn(i+1,1,ps,n);
        res=min(take,skip);
    }
    return t[i][fl]=res;
}
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
        vector<int>ps(n,0);
        ps[0]=stones[0];
        for(int i=1;i<n;i++) ps[i]=ps[i-1]+stones[i];
        memset(t,-1,sizeof(t));
        return fn(1,0,ps,n);
    }
};