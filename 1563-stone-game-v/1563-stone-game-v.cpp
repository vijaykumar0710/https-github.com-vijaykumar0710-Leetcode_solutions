class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int>pref(n+1,0);
        for(int i=0;i<n;i++) pref[i+1]=pref[i]+stoneValue[i];
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=len+i-1;
                for(int k=i;k<j;k++){
                    int left=pref[k+1]-pref[i];
                    int right=pref[j+1]-pref[k+1];
                    if(left==right) dp[i][j]=max(dp[i][j],left+max(dp[i][k],dp[k+1][j]));
                    else if(left<right) dp[i][j]=max(dp[i][j],left+dp[i][k]);
                    else dp[i][j]=max(dp[i][j],right+dp[k+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};