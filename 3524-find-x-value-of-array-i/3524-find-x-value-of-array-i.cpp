class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<long long>> t(n, vector<long long>(k, 0));
        for (int i = 0; i < n; i++)
            nums[i] = nums[i] % k;
        t[0][nums[0]] = 1;
        for (int i = 1; i < n; i++) {
            t[i][nums[i]]++;
            for (int r = 0; r < k; r++) {
                if (t[i - 1][r] > 0) {
                    int c = (r * nums[i])%k;
                    t[i][c] += t[i - 1][r];
                }
            }
        }
        vector<long long> res(k, 0);
        for (int i = 0; i < k; i++) {
            long long ans = 0;
            for (int j = 0; j < n; j++) {
                ans += t[j][i];
            }
            res[i] = ans;
        }
        return res;
    }
};