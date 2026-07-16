class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>PG;
        PG.push_back(nums[0]);
        int mx=nums[0];
        long long sum=0;
        for(int i=1;i<n;i++){
            mx=max(mx,nums[i]);
            PG.push_back(gcd(nums[i],mx));
        }
        sort(PG.begin(),PG.end());
        for(int i=0;i<n/2;i++) sum=(long long)sum+gcd(PG[i],PG[n-i-1]);
        return sum;
    }
};