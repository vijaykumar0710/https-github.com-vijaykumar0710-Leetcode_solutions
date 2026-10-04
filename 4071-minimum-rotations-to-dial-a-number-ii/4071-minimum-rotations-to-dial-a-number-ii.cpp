class Solution {
public:
    int minRotations(int n, string s) {
        int original=min(s[0]-'0','0'+10-s[0]);
        for (int i = 0; i < s.size() - 1; i++) {
            int x = min(s[i], s[i + 1]);
            int y = max(s[i], s[i + 1]);
            int dist = min(y - x, x + 10 - y);
            original += dist;
        }
        int res=original;
        int temp=original;
        temp-=min(s[0]-'0','0'+10-s[0]);
        temp+=min(s[n-1]-'0','0'+10-s[n-1]);
        res=min(res,temp);
        for(int i=1;i<n;i++){
          int temp=original;
          int x = min(s[i], s[i - 1]);
          int y = max(s[i], s[i - 1]);
          temp-=min(y - x, x + 10 - y);
          x=min(s[i-1], s[n-1]);
          y=max(s[i-1], s[n - 1]);
          temp+=min(y - x, x + 10 - y);
          res=min(res,temp);
        }
        return res;
    }
};