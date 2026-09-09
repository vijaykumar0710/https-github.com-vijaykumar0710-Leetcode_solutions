class Solution {
public:
    int longestValidParentheses(string s) {
       int n=s.size();
       if(n<=1) return 0;
       int op=0,cl=0,ans=0;
       for(int i=0;i<n;i++){
        if(s[i]=='(') op++;
        else cl++;
        if(op==cl) ans=max(ans,2*op);
        if(cl>op){
            op=0;
            cl=0;
        }
       }
       op=cl=0;
       for(int i=n-1;i>=0;i--){
        if(s[i]=='(') op++;
        else cl++;
        if(op==cl) ans=max(ans,2*op);
        if(op>cl){
            op=0;
            cl=0;
        }
       }
       return ans;
    }
};