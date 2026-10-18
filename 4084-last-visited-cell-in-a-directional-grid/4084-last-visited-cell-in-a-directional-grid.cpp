class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (grid[i][j] == 'L') {
                grid[i][j] = 'V';
                j--;
                if(j<0) return {i,j+1};
                if (grid[i][j] == 'V') return {i, j+1};
            } else if (grid[i][j] == 'R') {
                grid[i][j] = 'V';
                j++;
                if(j>=n) return {i,j-1};
                if (grid[i][j] == 'V') return {i, j-1};
            } else if (grid[i][j] == 'D') {
                grid[i][j] = 'V';
                i++;
                if(i>=m) return {i-1,j};
                if (grid[i][j] == 'V') return {i-1, j};
            } else {
                grid[i][j] = 'V';
                i--;
                if(i<0) return {i+1,j};
                if (grid[i][j] == 'V') return {i+1, j};
            }
        }
        return {m-1,n-1};
    }
};