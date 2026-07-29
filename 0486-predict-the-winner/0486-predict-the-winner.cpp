class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>t(n,vector<int>(n,0));
        for(int len=1;len<=n;len++){
            for(int i=0;len+i-1<n;i++){
                int j=len+i-1;
                if(len==1) t[i][i]=nums[i];
                else t[i][j]=max(nums[i]-t[i+1][j],nums[j]-t[i][j-1]);
            }
        }
        return t[0][n-1]>=0;
    }
};