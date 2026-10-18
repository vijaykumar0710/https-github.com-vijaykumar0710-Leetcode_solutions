class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int i=0,j=0;
        while(true){
            char move=grid[i][j];
            grid[i][j]='V';
            int pi=i,pj=j;
            if(move=='L') j--;
            else if(move=='R') j++;
            else if(move=='D') i++;
            else if(move=='U') i--;
            if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='V') return {pi,pj};
        }
    }
};