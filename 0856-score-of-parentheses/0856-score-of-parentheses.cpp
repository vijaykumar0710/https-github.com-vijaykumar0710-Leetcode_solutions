class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        for(auto ch:s){
            if(ch=='(') st.push(0);
            else{
                int ans=0;
                if(st.top()==0) ans=1;
                else ans=2*st.top();
                st.pop();
                int x=st.top();
                st.pop();
                st.push(x+ans);
            }
        }
        return st.top();
    }
};