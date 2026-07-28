class Solution {
public:
int t[2001][2001];
int solve(string &s,int i,int j,vector<vector<bool>>&dp){
if(t[i][j]!=-1) return t[i][j];
if(i>=j || dp[i][j]) return 0;
int mini=INT_MAX;
for(int k=i;k<j;k++){
    if(dp[i][k]){
        int temp=1+solve(s,k+1,j,dp);
        mini=min(mini,temp);
    }
}
return t[i][j]=mini;
}
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; len + i - 1 < n; i++) {
                int j = len + i - 1;
                if (len == 1)
                    dp[i][j] = true;
                else {
                    if (s[i] == s[j] && (dp[i + 1][j - 1] || len == 2))
                        dp[i][j] = true;
                }
            }
        }
        int i=0,j=n-1;
        memset(t,-1,sizeof(t));
        return solve(s,i,j,dp);
    }
};