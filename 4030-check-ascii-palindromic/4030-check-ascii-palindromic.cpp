class Solution {
public:
    bool isPalindromic(string s) {
        string str;
        for(auto ch:s){ 
        int n=ch;
        string st=bitset<8>(n).to_string();
        str+=st;
        }
        int i=0,j=str.size()-1;
        while(i<=j){
            if(str[i]!=str[j]){
                return false;
            }
            i++,j--;
        }
        return true;
    }
};