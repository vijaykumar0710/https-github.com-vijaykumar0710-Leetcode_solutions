class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        const long long INF=(1LL<<62);
        vector<long long>t(n+1,INF);
        t[0]=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=3;k++){
                int i=j-k;
                if(i>=0){
                    long long jumpCost=costs[j-1]+1LL*k*k;
                    t[j]=min(t[j],t[i]+jumpCost);
                }
            }
        }
        return t[n];
    }
};