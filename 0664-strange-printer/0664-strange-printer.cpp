class Solution {
public:
    int strangePrinter(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int len=1;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                if(len==1){
                    dp[i][i]=1;
                    continue;
                }
                int j=i+len-1;
                dp[i][j]=dp[i][j-1]+1;
                for(int k=i;k<j;k++){
                    if(s[k]==s[j]){
                        int left_cost=dp[i][k];
                        int right_cost=dp[k+1][j-1];
                        dp[i][j]=min(dp[i][j],left_cost+right_cost);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};