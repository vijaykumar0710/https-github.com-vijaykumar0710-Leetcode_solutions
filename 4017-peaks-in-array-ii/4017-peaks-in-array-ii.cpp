class Solution {
    public:
    int n;
    vector<long long> bit;
    vector<int> a;
    set<int> s;
    void update(int i, long long v) {
        for(; i <= n; i += i & -i) bit[i] += v;
    }
    long long query(int i) {
        long long sum = 0;
        for(; i>0; i -= i & -i) sum += bit[i];
        return sum;
    }
    void in(int x) {
        auto it = s.lower_bound(x);
        int p = (it == s.begin()) ? -1 : *prev(it);
        if(it != s.end()) {
            if(p != -1) update(*it, -1LL * *it * (*it - p));
            update(*it, 1LL * *it * (*it - x));
        }
        if(p != -1) update(x, 1LL * x * (x - p));
        s.insert(x);
    }
    void out(int x) {
        auto it = s.find(x);
        auto nx = next(it);
        int p = (it == s.begin()) ? -1 : *prev(it);
        if(p != -1) update(x, -1LL * x * (x - p));
        if(nx != s.end()) {
            update(*nx, -1LL * *nx * (*nx - x));
            if(p != -1) update(*nx, 1LL * *nx * (*nx - p));
        }
        s.erase(it);
    }
    bool peak(int i) {
        return i > 0 && i < n - 1 && a[i] > a[i - 1] && a[i] > a[i + 1];
    }
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        a = nums;
        bit.assign(n + 1, 0);
        s.clear();
        vector<long long> ans;
        for(int i = 1; i < n - 1; i++) {
            if(peak(i)) in(i);
        }
        for(auto &v : queries) {
            int x = v[1], y = v[2];
            if(v[0] == 2) {
                for(int i = x - 1; i <= x + 1; i++) {
                    if(s.count(i)) out(i);
                }
                a[x] = y;
                for(int i = x - 1; i <= x + 1; i++) {
                    if(peak(i)) in(i);
                }
            } else {
                auto it = s.lower_bound(x + 1);
                if(it == s.end() || *it >= y) {
                    ans.push_back(0);
                    continue;
                }       
                int f = *it, l = *prev(s.lower_bound(y));
                ans.push_back(1LL * y * (l - x) - 1LL * f * (f - x) - query(l) + query(f));
            }
        }
        return ans;
    }
};