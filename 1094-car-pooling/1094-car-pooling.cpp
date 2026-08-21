class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> vec(1005, 0);
        for (auto t : trips) {
            int val = t[0], x = t[1], y = t[2];
            vec[x+1] += val;
            vec[y+1] -= val;
        }
        for (int i = 1; i < 1005; i++) {
            vec[i] += vec[i - 1];
            if(vec[i]>capacity) return false;
        }
        return true;
    }
};