class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
          if(nums[n/2]==k) return 0;
          if(k>nums[n/2]){
            long long res=0;
             for(int i=n/2;i<n;i++){
                if(k>nums[i]) res+=(k-nums[i]);
             }
             return res;
          }
          if(k<nums[n/2]){
            long long res=0;
            for(int i=n/2;i>=0;i--){
                if(nums[i]>k) res+=(nums[i]-k);
            }
            return res;
          }
        return -1;
    }
};