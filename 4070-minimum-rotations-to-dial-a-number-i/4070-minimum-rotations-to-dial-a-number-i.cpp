class Solution {
public:
    int minRotations(string s) {
        int res =min(s[0]-'0','0'+10-s[0]);
        for (int i = 0; i < s.size() - 1; i++) {
            int x = min(s[i], s[i + 1]);
            int y = max(s[i], s[i + 1]);
            int dist = min(y - x, x + 10 - y);
            res += dist;
        }
        return res;
    }
};