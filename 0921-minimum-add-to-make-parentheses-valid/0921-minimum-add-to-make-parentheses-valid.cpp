class Solution {
public:
    int minAddToMakeValid(string s) {
        int res=0,b=0; for(auto ch:s){ ch=='('?b++:b--; if(b<0) res+=abs(b),b=0; }
        return b+res;
    }
};