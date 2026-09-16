const int M=1e9+7;
class Solution {
public:
int t[1001][1001];
int solve(int i,int k,int n){
    if(k==0) return 1;
    if(i>n) return 0;
    if(n-i<k) return 0;
    if(t[i][k]!=-1) return t[i][k];
    int cnt=0;
    cnt=(cnt%M + solve(i + 1, k, n)%M) % M;
    for(int j=i+1;j<=n;j++)
    cnt=(cnt%M+solve(j,k-1,n))%M;
    return t[i][k]=cnt;
}
    int numberOfSets(int n, int k) {
        memset(t,-1,sizeof(t));
        return solve(0,k,n-1);
    }
};