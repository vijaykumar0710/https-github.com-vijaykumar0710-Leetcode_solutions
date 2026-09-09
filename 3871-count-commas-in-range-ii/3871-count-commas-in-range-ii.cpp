class Solution {
public:
    long long countCommas(long long n) {
        long long num=n;
       int sz=0;
       while(num){
        sz++;
        num/=10;
       }
       vector<long long>vec(17);
       vec[0]=0;
       vec[1]=9;
       for(int i=2;i<17;i++)
           vec[i]=1LL*vec[i-1]*10;
       long long res=0;
       for(int i=4;i<17;i++){
        if(i<sz){
            res=res+1LL*((i-1)/3)*vec[i];
        }else if(i==sz){
            long long num=1;
            sz--;
            while(sz--) num=1LL*num*10;
            res=res+1LL*((i-1)/3)*(n-num+1);
            break;
        }
       }
       return res;
    }
};