class Solution {
public:
    bool checkDivisibility(int n) {
        int N=n;
        long long sum=0,pro=1;
        while(n){
            int x=n%10;
            sum+=x;
            pro*=x;
            n/=10;
        }
        cout<<sum<<" "<<pro;
        return (N%(sum+pro))==0;
    }
};