class Solution {
public:
int a,b,K;
vector<pair<int,int>>cells;
vector<string>grid;
int countPaths(){
vector<vector<int>>dp(a,vector<int>(b,0));
for(int j=0;j<b;j++){
    if(grid[0][j]=='#') break;
    dp[0][j]=1;
  }
  for(int i=1;i<a;i++){
    if(grid[i][0]=='#') break;
    dp[i][0]=1;
  }
  for(int i=1;i<a;i++){
    for(int j=1;j<b;j++){
        if(grid[i][j]=='#') continue; 
        dp[i][j]=dp[i-1][j]+dp[i][j-1];
    }
  }
  return dp[a-1][b-1];
}

bool generate(int idx){
if(idx==cells.size()) return countPaths()==K;
auto [i,j]=cells[idx];
grid[i][j]='.';
if(generate(idx+1)) return true;
grid[i][j]='#';
if(generate(idx+1)) return true;
return false;
}
    vector<string> createGrid(int m, int n, int k) {
        a=min(m,k),b=min(n,k),K=k;
        grid.assign(a,string(b,'.'));
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                cells.push_back({i,j});
            }
        }
      if(!generate(0)) return {};
      vector<string>res(m,string(n,'#'));
      for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            res[i][j]=grid[i][j];
        }
      }
      for(int j=b;j<n;j++) res[a-1][j]='.';
      for(int i=a;i<m;i++) res[i][n-1]='.';
      return res;
     }
};