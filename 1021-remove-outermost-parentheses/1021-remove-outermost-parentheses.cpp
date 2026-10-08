class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        string cur="";
        int b=0;
        for(int i=0;i<s.size();i++){
           if(s[i]=='(') b++;
           else b--;
           cur+=s[i];
           if(b==0){
             cur.pop_back();
             res+=cur.substr(1);
             cur="";
           }
        }
        return res;
    }
};