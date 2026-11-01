class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n=nums.size();
        int res=INT_MAX;
        for(int i=0;i<n-1;i+=2){
           string st=to_string(nums[i])+to_string(nums[i+1]);
           res=min(res,stoi(st));
        }
        return res;
    }
};