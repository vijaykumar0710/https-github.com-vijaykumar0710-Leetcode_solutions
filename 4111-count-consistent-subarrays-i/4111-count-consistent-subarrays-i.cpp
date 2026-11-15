class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            int mini=nums[i];
            int xor_val=nums[i];
            for(int j=i;j<n;j++){
                mini=min(mini,nums[j]);
                xor_val=xor_val&nums[j];
                if(xor_val==mini) res++;
            }
        }
        return res;
    }
};