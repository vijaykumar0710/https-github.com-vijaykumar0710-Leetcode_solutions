class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<unordered_set<int>>> t(m, vector<unordered_set<int>>(n));
        if (grid[0][0] == '(')
            t[0][0].insert(1);
        else
            return false;
        for (int j = 1; j < n; j++) {
            if (grid[0][j] == '(') {
               if(!t[0][j - 1].empty() &&*t[0][j - 1].begin()>=0) t[0][j].insert(*t[0][j - 1].begin() + 1);
            } else {
                if (!t[0][j - 1].empty() && *t[0][j - 1].begin()>0)
                t[0][j].insert(*t[0][j - 1].begin() - 1);
            }
        }
        for (int i = 1; i < m; i++) {
            if (grid[i][0] == '('){
               if(!t[i-1][0].empty() && *t[i - 1][0].begin()>=0) t[i][0].insert(*t[i - 1][0].begin() + 1);
               }
            else {
                if (!t[i-1][0].empty() && *t[i - 1][0].begin()>0)
                t[i][0].insert(*t[i - 1][0].begin() - 1);
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                auto st = t[i][j - 1];
                if (!st.empty()) {
                    for (auto x : st) {
                        if (grid[i][j] == '('){
                           if(x>=0) t[i][j].insert(x + 1);
                           }
                        else if (x > 0){
                            t[i][j].insert(x - 1);
                            }
                    }
                }
                st = t[i - 1][j];
                if (!st.empty()) {
                    for (auto x : st) {
                        if (grid[i][j] == '('){
                          if(x>=0) t[i][j].insert(x + 1);
                          }
                        else if (x > 0){
                            t[i][j].insert(x - 1);
                            }
                    }
                }
            }
        }
        auto st = t[m - 1][n - 1];
        for (auto x : st) {
            if (x == 0)
                return true;
        }
        return false;
    }
};