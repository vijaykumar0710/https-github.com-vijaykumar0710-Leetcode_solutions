class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int len=1;
        for(int i=0;i<n;i++){
            int l=nums[i];
            int g=nums[i];
            int p=nums[i];
            for(int j=i+1;j<n;j++){
                l=lcm(l,nums[j]);
                g=gcd(g,nums[j]);
                p=1LL*p*nums[j];
                if(p==(l*g)) len=max(len,j-i+1);
            }
        }
        return len;
    }
};