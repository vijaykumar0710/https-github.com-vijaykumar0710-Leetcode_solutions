class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res;
        int nines=sum/9;
        while(nines--) res+='9';
        int rem=sum%9;
        if(rem>0)res+=to_string(rem);
        int sz=num-res.size();
        if(sz<0) return "";
        while(sz--) res+='0';
        return res;
    }
};