class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int res=n+1;
        int pre=0;
        for(int i=0;i<n;i++){
            pre+=nums[i];
            mp[pre]=i;
            if(pre==x) res=min(res,i+1);
        }
        int suf=0;
        for(int i=n-1;i>=0;i--){
            suf+=nums[i];
            if(suf==x) res=min(res,n-i);
            int tar=x-suf;
            if(tar>0 && mp.count(tar)){
                if(mp[tar]<i) res=min(res,n-i+mp[tar]+1);
            }
        }
        return res==n+1?-1:res;
    }
};