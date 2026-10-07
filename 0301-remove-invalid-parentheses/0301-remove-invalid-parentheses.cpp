class Solution {
public:
    bool isValid(string& s) {
        int n = s.size();
        int b = 0;
        for (auto ch : s) {
            if (ch == '(')
                b++;
            else if (ch == ')')
                b--;
            if (b < 0)
                return false;
        }
        return b == 0;
    }
    void solve(int i, string &cur, string& s,int b, unordered_set<string>&ans) {
        if (cur.size() + (s.size() - i) < b) return;
        if(cur.size()>b) return;
        if (i >= s.size()) {
            if ((int)cur.size()==b){
                 if(isValid(cur)) ans.insert(cur);
                }
            return;
        }
      if(!isalpha(s[i])) solve(i + 1, cur, s,b,ans);
       cur+=s[i];
       solve(i + 1, cur, s,b,ans);
       cur.pop_back();
       return;
    }
    vector<string> removeInvalidParentheses(string s) {
        int min_len = 0;
        int b = 0;
        for (auto ch : s) {
            if (ch == '(')
                b++;
            else if (ch == ')')
                b--;
            if (b < 0){
                min_len+=abs(b);
                b=0;
            }
        }
        b=s.size()-min_len-b;
        unordered_set<string>st;
        vector<string> ans;
        string cur="";
        solve(0, cur, s,b,st);
        for(auto str:st){
            ans.push_back(str);
        }
        if (ans.size() == 0)
            return {""};
        return ans;
    }
};