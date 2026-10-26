class Solution {
public:
vector<vector<int>>directions={{0,-1},{0,1},{-1,0},{1,0}};
bool bfs(int r,int c,vector<vector<int>>& grid,int k){
    int m=grid.size(),n=grid[0].size();
    queue<pair<int,int>>q;
    q.push({r,c});
    int sum=grid[r][c]%k;
    grid[r][c]=0;
    while(!q.empty()){
        int i=q.front().first,j=q.front().second;
        q.pop();
        for(auto dir:directions){
            int n_i=i+dir[0],n_j=j+dir[1];
            if(n_i<0 || n_i>=m || n_j<0 || n_j>=n || grid[n_i][n_j]==0) continue;
            sum=(sum+grid[n_i][n_j])%k;
            q.push({n_i,n_j});
            grid[n_i][n_j]=0;
        }
    }
    return sum%k==0;
}
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0 && bfs(i,j,grid,k)) cnt++;
            }
        }
        return cnt;
    }
};