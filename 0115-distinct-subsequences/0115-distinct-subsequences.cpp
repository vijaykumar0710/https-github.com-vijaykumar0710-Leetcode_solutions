class Solution {
public:
int memo[1001][1001];
int m,n;
int solve(int i,int j,string &s1,string s2){
if(j>=n) return 1;
if(i>=m) return 0;
if(memo[i][j]!=-1) return memo[i][j];
int cnt=0;
if(s1[i]==s2[j]) cnt+=solve(i+1,j+1,s1,s2);
cnt+=solve(i+1,j,s1,s2);
return memo[i][j]=cnt;
}
    int numDistinct(string s, string t) {
    m=s.size(),n=t.size();   
    memset(memo,-1,sizeof(memo));
    return solve(0,0,s,t); 
    }
};