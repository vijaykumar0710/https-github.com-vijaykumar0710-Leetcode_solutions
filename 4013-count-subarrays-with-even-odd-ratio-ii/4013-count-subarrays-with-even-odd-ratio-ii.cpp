class Solution {
public:
long long res=0;
map<long long,int>BIT;
long long m;
void update(long long i){
for(;i<=m;i+=i&-i) BIT[i]+=1;
}
long long query(long long i){
    long long ans=0;
    for(;i>0;i-=(i&-i)) res+=BIT[i];
    return ans;
}
long long countInversion(vector<long long>&pref){
    int n=pref.size();
    long long maxi=2e18+1;
    m=2*maxi+1;
    for(int i=n-1;i>=0;i--){
        long long x=query(pref[i]+maxi);
        res+=x;
        update(pref[i]+maxi);
    }
    return res;
}
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2) nums[i]=-a;
            else nums[i]=b;
        }
        vector<long long>pref(n+1,0);
        for(int i=0;i<n;i++) pref[i+1]=pref[i]+nums[i];
        return countInversion(pref);
    }
};