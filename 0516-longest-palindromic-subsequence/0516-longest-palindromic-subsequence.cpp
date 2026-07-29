class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>t(n,vector<int>(n,0));
        for(int len=1;len<=n;len++){
            for(int i=0;len+i-1<n;i++){
                int j=len+i-1;
                if(len==1) t[i][i]=1;
                else{
                    if(s[i]==s[j]) t[i][j]=2+t[i+1][j-1];
                    else t[i][j]=max(t[i+1][j],t[i][j-1]);
                }
            }
        }
        return t[0][n-1];
    }
};