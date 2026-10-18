class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = 0, j = 0;
       while (true) {
            char dir = grid[i][j];
            grid[i][j] = 'V';
            int ni = i, nj = j;
            if (dir == 'L') nj--;
            else if (dir == 'R') nj++;
            else if (dir == 'D') ni++;
            else if (dir == 'U') ni--;
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || grid[ni][nj] == 'V') {
                return {i, j};
            }
            i = ni;
            j = nj;
        }
    }
};