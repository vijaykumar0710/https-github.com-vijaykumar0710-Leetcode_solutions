class Solution {
public:
const int M=1e9+7;
int modPow(long a,long b){
    long long res=1;
    a%=M;
    while(b){
        if(b&1) res=(res%M*a%M)%M;
        a=(a%M*a%M)%M;
        b/=2;
    }
    return res; 
}
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=n/2;
        long long res=modPow(5,even)%M;
        res=(res%M*modPow(4,odd)%M)%M;
        return res;
    }
};