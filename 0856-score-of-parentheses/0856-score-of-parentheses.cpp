class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        vector<vector<int>>t(n,vector<int>(n,0));
        for(int len=2;len<=n;len+=2){
            for(int i=0;i<=n-len;i++){
                int j=len+i-1;
                if(len==2){
                    if(s[i]=='(' & s[j]==')') t[i][j]=1;
                    continue;
                }
                if(s[i]=='(' && s[j]==')'){
                    if(t[i+1][j-1]!=0) t[i][j]=2*t[i+1][j-1];
                    else{
                        for(int k=i;k<j;k++){
                            if(t[i][k]!=0 && t[k+1][j]!=0){
                                t[i][j]=t[i][k]+t[k+1][j];
                                break;
                            }
                        }
                    }
                }
            }
        }
        return t[0][n-1];
    }
};