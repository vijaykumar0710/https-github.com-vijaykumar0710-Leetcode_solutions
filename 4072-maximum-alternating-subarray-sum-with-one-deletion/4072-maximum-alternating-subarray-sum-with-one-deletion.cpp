class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long res=-1e16;
        long long e0=-1e16,o0=-1e16;
        long long e1=-1e16,o1=-1e16;
        for(int i=0;i<nums.size();i++){
          long long ne0=max(1LL*nums[i],o0+nums[i]);
          long long no0=e0-nums[i];
          long long ne1=max(e0,o1+nums[i]);
          long long no1=max(o0,e1-nums[i]);
          e0=ne0;
          o0=no0;
          e1=ne1;
          o1=no1;
          res=max({res,e0,o0,e1,o1});
        }
        return res;
    }
};