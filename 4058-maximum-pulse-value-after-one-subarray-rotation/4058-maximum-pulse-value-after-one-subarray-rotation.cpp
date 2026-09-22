class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>A(n);
        long long pulse=0;
        for(int i=0;i<n;i++){
            if(i%2) A[i]=-1*nums[i];
            else A[i]=nums[i];
            pulse+=A[i];
        }
       long long even_len=0;
       long long odd_len=-1e15;
       long long pref_sum=0;
       long long change=LLONG_MAX;
       for(int i=0;i<n;i++){
          pref_sum+=A[i];
         if((i+1)%2){
            if(odd_len!=-1e15)
            change=min(change,pref_sum-odd_len);
            odd_len=max(odd_len,pref_sum);
         }
         else{
            change=min(change,pref_sum-even_len);
            even_len=max(even_len,pref_sum);
         }
       }
       if(change==LLONG_MAX || change>0) change=0;
       return 1LL*pulse-2*change;
    }
};