class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>>t(n,vector<int>(n,0));
        for(int len=1;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=len+i-1;
                if(len==1){
                    if(s[i]=='*') t[i][i]=1;
                    continue;
                }
                if(len==2){
                    if(s[i]==')' || s[j]=='(') t[i][j]=0;
                    else t[i][j]=1;
                    continue;
                }
                if(s[i]==')' || s[j]=='('){
                    continue;
                }
                if(t[i+1][j-1]){
                    t[i][j]=1;
                    continue;
                }
                for(int k=i;k<j;k++){
                    if(t[i][k]&&t[k+1][j]){
                      t[i][j]=1;
                        break;
                    }
                }
            }
        }
        return t[0][n-1];
    }
};