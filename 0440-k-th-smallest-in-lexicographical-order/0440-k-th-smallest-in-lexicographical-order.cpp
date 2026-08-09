class Solution {
public:
int cntSteps(long long curr,long long n){
    long long steps=0;
    long long first=curr,last=curr;
    while(first<=n){
        steps+=(min(last,n)-first+1);
        first*=10;
        last=last*10+9;
    }
    return steps;
}
    int findKthNumber(int n, int k) {
        long long curr=1;
        k--;
        while(k>0){
            int steps=cntSteps(curr,n);
           if(steps<=k){
            k-=steps;
            curr++;
           }else{
            curr*=10;
            k--;
           }
        }
        return curr;
    }
};