class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<unordered_set<int>>>t(m,vector<unordered_set<int>>(n));
        int x=0;
        for(int i=0;i<m;i++){
            x^=grid[i][0];
            t[i][0].insert(x);
        }
        x=0;
        for(int j=0;j<n;j++){
            x^=grid[0][j];
            t[0][j].insert(x);
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                auto &st=t[i-1][j];
                for(auto &x:st) t[i][j].insert(x^grid[i][j]);
                auto &st1=t[i][j-1];
                for(auto &x:st1) t[i][j].insert(x^grid[i][j]);
            }
        }
        auto &st=t[m-1][n-1];
        int res=INT_MAX;
        for(auto &x:st){
           res=min(res,x);
        }
        return res;
    }
};