class Solution {
public:
void two_sum(vector<int>&nums,int target,int i,vector<vector<int>>&res){
    int n=nums.size();
    int j=n-1;
    while(i<j){
        if(nums[i]+nums[j]>target) j--;
        else if(nums[i]+nums[j]<target) i++;
        else{
            while(i<j && nums[i]==nums[i+1]) i++;
            while(i<j && nums[j]==nums[j-1]) j--;
            res.push_back({nums[i],nums[j],-target});
            i++,j--;
        }
    }
}
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target=-nums[i];
            two_sum(nums,target,i+1,res);
        }
        return res;
    }
};