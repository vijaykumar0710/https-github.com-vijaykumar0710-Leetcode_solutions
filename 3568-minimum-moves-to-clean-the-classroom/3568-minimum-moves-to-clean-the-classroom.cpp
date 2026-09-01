class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int minMoves(vector<string>& grid, int energy) {
        int m = grid.size();
        int n = grid[0].size();
        int r = -1, c = -1, cnt = 0;
        vector<vector<int>> id(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    r = i, c = j;
                } else if (grid[i][j] == 'L') {
                    id[i][j] = cnt++;
                }
            }
        }
        int tar_mask = (1 << cnt) - 1;
        queue<vector<int>> q;
        vector<vector<vector<int>>> vis(
            m, vector<vector<int>>(n, vector<int>(1 << cnt, -1)));
        q.push({r, c, 0, energy, 0});
        vis[r][c][0] = energy;
        while (!q.empty()) {
            auto vec = q.front();
            q.pop();
            if (vec[2] == tar_mask)
                return vec[4];
            if (vec[3] == 0)
                continue;
            for (auto dir : directions) {
                int n_r = vec[0] + dir[0];
                int n_c = vec[1] + dir[1];
                if (n_r >= 0 && n_r < m && n_c >= 0 && n_c < n &&
                    grid[n_r][n_c] != 'X') {
                    int n_energy = vec[3] - 1;
                    int n_mask = vec[2];
                    if (grid[n_r][n_c] == 'L') {
                        n_mask |= (1 << id[n_r][n_c]);
                    }
                    if (grid[n_r][n_c] == 'R') {
                        n_energy = energy;
                    }
                    if (n_energy > vis[n_r][n_c][n_mask]) {
                        vis[n_r][n_c][n_mask] = n_energy;
                        q.push({n_r, n_c, n_mask, n_energy, vec[4] + 1});
                    }
                }
            }
        }
        return -1;
    }
};