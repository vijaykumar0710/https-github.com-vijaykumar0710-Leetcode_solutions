class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int x=0,y=0;
            for(int j=i;j<n;j++){
                if(nums[j]%2==1) y++;
                else x++;
                if(y>0 && b*x-a*y<=0) cnt++;
            }
        }
        return cnt;
    }
};