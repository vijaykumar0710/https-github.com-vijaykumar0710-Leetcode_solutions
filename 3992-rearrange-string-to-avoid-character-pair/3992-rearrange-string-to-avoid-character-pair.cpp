class Solution {
public:
    string rearrangeString(string s, char x, char y) {
       string s1="",s2="",s3="";
      for(int i=0;i<s.size();i++){
        if(s[i]==x) s3+=s[i];
        else if(s[i]==y) s1+=s[i];
        else s3+=s[i];
      }
        return s1+s2+s3;
    }
};