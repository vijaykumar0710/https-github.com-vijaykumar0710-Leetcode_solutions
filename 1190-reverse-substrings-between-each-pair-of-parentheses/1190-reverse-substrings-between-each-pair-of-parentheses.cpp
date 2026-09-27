class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
              string str="";
            while(!st.empty()&&st.top()!='('){
                str+=st.top();
                st.pop();
            }
            st.pop();
            for(auto ch:str) st.push(ch);
            }else st.push(s[i]);
        }
        string res="";
        while(!st.empty()){
            if(st.top()=='(') continue;
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};