class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) nums[i]=abs(nums[i]);
        sort(nums.rbegin(),nums.rend());
        long long res=0LL;
        int i=0,j=n-1;
        while(i<=j){
          if(i==j) res+=nums[i]*nums[i];
          else{
            res+=nums[i]*nums[i];
            res-=nums[j]*nums[j];
          }
          i++,j--;
        }
        return res;
    }
};