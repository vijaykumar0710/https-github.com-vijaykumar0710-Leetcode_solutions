class Solution {
public:
    long long f(long long n) {
        long long num = 0;
        while (n) {
            int x = n % 10;
            num += (x * x);
            n /= 10;
        }
        return num;
    }
    bool isHappy(int n) {
        if(n==1) return true;
        unordered_set<int>st;
        long long num=n;
        while(num>=1){ 
        num=f(num);
        if(num==1) return true;
        if(st.count(num)) return false;
        st.insert(num);
        }
        return true;
    }
};