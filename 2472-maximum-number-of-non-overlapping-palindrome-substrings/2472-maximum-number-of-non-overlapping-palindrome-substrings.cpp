class Solution {
public:
    vector<vector<bool>> palin;
    void pal(string& s) {
        int n = s.size();
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = len + i - 1;
                if (len == 1)
                    palin[i][i] = true;
                else {
                    if (s[i] == s[j] && (palin[i + 1][j - 1] || len == 2)) {
                        palin[i][j] = true;
                    }
                }
            }
        }
    }
    int t[2001][2001];
    int solve(int i, int j, string& s, int k, int n) {
        if (i > n - 1 || j > n - 1)
            return 0;
        if(t[i][j]!=-1) return t[i][j];
        int op1 = 0;
        if (j - i + 1 >= k && palin[i][j])
            op1 = 1 + solve(j + 1, j + 1, s, k, n);
        int op2 = max({solve(i + 1, j + 1, s, k, n), solve(i + 1, j, s, k, n),
                      solve(i, j + 1, s, k, n)});
        return t[i][j]=max(op1, op2);
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        palin.assign(n, vector<bool>(n, false));
        pal(s);
        memset(t,-1,sizeof(t));
        return solve(0, 0, s, k, n);
    }
};