class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=min(strs[0].size(),strs[strs.size()-1].size());
        string s1=strs[0],s2=strs[strs.size()-1];
        int i=0;
        for(;i<n;i++){
            if(s1[i]!=s2[i]){
                return s1.substr(0,i);
            }
        }
        if(i>=n) return s1.substr(0,i);
        return "";
    }
};