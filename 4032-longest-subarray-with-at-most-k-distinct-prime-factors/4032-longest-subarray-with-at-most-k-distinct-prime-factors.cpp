class Solution {
public:
vector<int>prime_factor(int n){
    vector<int>prime;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            prime.push_back(i);
            while(n%i==0) n/=i;
        }
    }
    if(n>1) prime.push_back(n);
    return prime;
}
    int longestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int i=0,res=0;
        for(int j=0;j<n;j++){
            vector<int>p;
            p=prime_factor(nums[j]);
            for(auto x:p) mp[x]++;
            while(mp.size()>k){
                vector<int>q;
                q=prime_factor(nums[i]);
                for(auto x:q){
                    mp[x]--;
                    if(mp[x]==0) mp.erase(x);
                }
                i++;
            }
            res=max(res,j-i+1);
        }
        return res;
    }
};