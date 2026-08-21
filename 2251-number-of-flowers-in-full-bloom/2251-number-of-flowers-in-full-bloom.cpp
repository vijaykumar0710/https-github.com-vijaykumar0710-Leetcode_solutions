class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> t1;
        for (auto f : flowers) {
            t1.push_back(f[0]);
            t1.push_back(f[1] + 1);
        }
        for (auto p : people)
            t1.push_back(p);
        sort(t1.begin(), t1.end());
        t1.erase(unique(t1.begin(), t1.end()), t1.end());
         int n = t1.size();
        vector<int> d(n + 1, 0);
        for (auto f : flowers) {
            int l = lower_bound(t1.begin(), t1.end(), f[0]) - t1.begin();
            int r = lower_bound(t1.begin(), t1.end(), f[1] + 1) - t1.begin();
            d[l] += 1;
            d[r] -= 1;
        }
        for (int i = 1; i < n; i++)
            d[i] += d[i - 1];
        vector<int> res;
        for (auto p:people) {
            int idx = lower_bound(t1.begin(), t1.end(), p) - t1.begin();
            res.push_back(d[idx]);
        }
        return res;
    }
};