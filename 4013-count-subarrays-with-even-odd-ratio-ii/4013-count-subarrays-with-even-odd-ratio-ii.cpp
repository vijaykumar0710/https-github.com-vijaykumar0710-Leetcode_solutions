class Solution {
public:
long long res=0;
map<long long,int>BIT;
long long m;
void update(long long i){
for(;i<=m;i+=i&-i) BIT[i]+=1;
}
int query(long long i){
long long res=0;
for(;i>0;i-=(i&-i)) res+=BIT[i]; 
  return res;
}
long long countInversion(vector<long long>& nums) {
        int n=nums.size();
        long long maxi=2e18+1;
        m=2*maxi+1;
        for(int i=n-1;i>=0;i--){
            long long x=query(nums[i]+maxi);
            res+=x;
            update(nums[i]+maxi);
        }
        return res;
    }
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2) nums[i]=-a;
            else nums[i]=b;
        }
        vector<long long>pre(n+1,0);
        for(int i=0;i<n;i++) pre[i+1]=pre[i]+nums[i];
        return countInversion(pre);
    }
};