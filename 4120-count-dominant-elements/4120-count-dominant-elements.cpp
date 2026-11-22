class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int res=0;
        if(nums[0]>=nums[1]) res++;
        if(nums[n-1]>=nums[n-2]) res++;
        for(int i=1;i<n-1;i++){
            float avg=(nums[i-1]+nums[i+1])/2.0;
            if(nums[i]>=avg) res++;
        }
        return res;
    }
};