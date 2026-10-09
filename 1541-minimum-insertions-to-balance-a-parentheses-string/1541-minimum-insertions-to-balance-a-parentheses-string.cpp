class Solution {
public:
    int minInsertions(string s) {
        int res = 0;
        string str = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                str += s[i];
            else {
                str += ')';
                if (i + 1 < s.size() && s[i + 1] == ')')
                    i++;
                else
                    res++;
            }
        }
        int b = 0;
        for (auto ch : str) {
            if (ch == '(')
                b++;
            else
                b--;
            if(b<0) res+=abs(b),b=0;
        }
        res += 2*b;
        return res;
    }
};