class Solution {
public:
const int M=1e9+7;
long long power(long long x,long long y){
    long long ans=1;
    x%=M;
    while(y){
        if(y%2) ans=(ans*x)%M;
        x=(x*x)%M;
        y/=2;
    }
    return ans;
}
    int sumDecoded(vector<long long>& nums) {
        int n=nums.size();
        long long res=0;
        for(int i=0;i<n;i++){
            long long w=nums[i]%10;
            long long d=nums[i]/10;
            int len=log10(d)+1;
            long long x=d/(power(10,len-w));
            long long y=d%(power(10,len-w));
            res=(res+power(x,y))%M;
        }
        return res;
    }
};