class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="",cur="";
        int b=0;
        for(int i=0;i<s.size();i++){
           s[i]=='('?b++:b--;
           cur+=s[i];
           b==0?res+=cur.substr(1,cur.size()-2),cur="":res;
        }
        return res;
    }
};