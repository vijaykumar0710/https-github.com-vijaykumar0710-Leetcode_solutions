class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        map<int,int>mp;
        for(int i=0;i<n;i++) mp[abs(nums1[i]-nums2[i])]++;
        long long limit=k1+k2;
        int x=!mp.empty()?mp.rbegin()->first:-1;
        while(limit>0){
        if(!mp.empty()) x=mp.rbegin()->first;
        else break;
        int mini=min(limit,1LL*mp[x]);
        if(x-1>0) mp[x-1]+=mini;
         mp[x]-=mini;
         limit-=mini;
         if(mp[x]==0) mp.erase(x);
        }
        long long res=0LL;
        for(auto [x,y]:mp) res+=1LL*x*x*y;
        return res;
    }
};