class Solution {
public:
    int t[100005];
    int solve(long long sum) {
        if (sum == 0) return 0;
        if (t[sum] != -1) return t[sum];
        int res = INT_MAX;
        for (long long i = 1; (i * (i + 1)) / 2 <= sum; i++) {
            long long T = (i * (i + 1)) / 2;
            if (sum - T > 0) {
                int sub = solve(sum - T);
                if (sub != INT_MAX) {
                    res = min(res, (int)(1 + i + sub));
                }
            } else if (sum - T == 0) {
                res = min(res, (int)i); 
            }
        }
        return t[sum] = res;
    }
    int minDays(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};