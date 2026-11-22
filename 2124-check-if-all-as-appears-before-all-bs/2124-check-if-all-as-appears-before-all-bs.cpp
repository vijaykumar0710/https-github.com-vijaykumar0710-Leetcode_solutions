class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        int i=0;
        while(i<n && s[i]=='a')i++;
        int j=i;
        while(j<n){
            if(s[j]=='a') return false;
            j++;
        }
        return j>=n;
    }
};