class Solution {
public:
vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
void bfs(int r,int c,vector<vector<int>>& grid,bool &flag){
    int m=grid.size();
    int n=grid[0].size();
    queue<pair<int,int>>q;
    q.push({r,c});
    grid[r][c]=1;
    while(!q.empty()){
    int x=q.front().first;
    int y=q.front().second;
    q.pop();
    for(auto dir:directions){
        int n_r=x+dir[0];
        int n_c=y+dir[1];
        if(n_r<0 || n_r>=m || n_c<0 || n_c>=n) flag=false;
        if(n_r>=0 && n_r<m &&n_c>=0 && n_c<n && grid[n_r][n_c]==0){
            grid[n_r][n_c]=1;
            q.push({n_r,n_c});
        }
    }
  }
}
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size(); 
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    bool flag=true;
                    bfs(i,j,grid,flag);
                    if(flag) res++;
                }
            }
        }
        return res;
    }
};