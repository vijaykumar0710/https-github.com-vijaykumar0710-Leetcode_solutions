class Solution {
public:
long long typedef ll;
struct RollingHash{
ll M=1e9+7;
ll base=131;
vector<ll>prefix;
vector<ll>power;
RollingHash(vector<int>&nums){
int n=nums.size();
prefix.assign(n+1,0);
power.assign(n+1,1);
for(int i=0;i<n;i++){
prefix[i+1]=(prefix[i]*base+nums[i])%M;
power[i+1]=(power[i]*base)%M;
  }
}
ll get_hash(int l,int r){
 return (prefix[r+1]-(prefix[l]*power[r-l+1])%M+M)%M;
  }  
};
bool isValid(vector<int>&nums,int mid,RollingHash&rh){
int n=nums.size();
unordered_map<ll,int>mp;
for(int i=0;i<=n-mid;i++){
  ll val=rh.get_hash(i,i+mid-1);
  mp[val]++;
 }
for(auto x:mp){
    if(x.second==1) return true;
}
return false;
}
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        RollingHash rh(nums);
        int l=1,r=n;
        int len=n;
        while(l<=r){
          int mid=l+(r-l)/2;
          if(isValid(nums,mid,rh)){
            len=mid;
            r=mid-1;
          }else l=mid+1;
         }
        return len;
    }
};