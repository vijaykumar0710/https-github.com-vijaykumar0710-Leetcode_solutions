class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            int val=nums[i];
            for(int j=i;j<n;j++){
                mini=min(mini,nums[j]);
                val=val&nums[j];
                if(val==mini) res++;
            }
        }
        return res;
    }
};