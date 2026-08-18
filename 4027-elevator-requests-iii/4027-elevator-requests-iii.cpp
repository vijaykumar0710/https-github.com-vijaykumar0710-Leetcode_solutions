class Solution {
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        int k=requests.size();
        long long INF=1e18;
        vector<vector<long long>>dp(1<<k,vector<long long>(k,INF));
        for(int i=0;i<k;i++){
            long long dist=abs(start-requests[i][1]);
            long long arrival_time=requests[i][0];
            dp[1<<i][i]=max(dist,arrival_time);
        }
        for(int mask=1;mask<(1<<k);mask++){
            for(int i=0;i<k;i++){
                if((mask&(1<<i))!=0){
                    for(int j=0;j<k;j++){
                        if((mask&(1<<j))==0){
                            int new_mask=mask|(1<<j);
                            long long dist=abs(requests[i][1]-requests[j][1]);
                            long long arrival_time=requests[j][0];
                            long long new_time=max(dp[mask][i]+dist,arrival_time);
                            dp[new_mask][j]=min(dp[new_mask][j],new_time);
                        }
                    }
                }
            }
        }
        long long res=INF;
        int last_row=(1<<k)-1; 
        for(int i=0;i<k;i++){
            res=min(res,dp[last_row][i]);
        }
        return res;
    }
};