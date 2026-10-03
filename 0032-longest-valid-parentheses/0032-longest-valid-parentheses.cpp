class Solution {
public:
    int longestValidParentheses(string s) {
        //"Measure the distance from my current
        // position back to the last invalid bracket."
        int res=0;
        stack<int>st;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            if(s[i]==')'){
                st.pop();
                if(st.empty()) st.push(i);
                else res=max(res,i-st.top());
            }else st.push(i);
        }
        return res;
    }
};