class Solution {
public:
long long MAXN;
vector<long long>BIT;
void update(int i,int val){
    for(;i<=MAXN;i+=(i&-i)) BIT[i]+=val;
}
long long query(int i){
    long long res=0;
    for(;i>0;i-=(i&-i)) res+=BIT[i];
    return res;
}
long long countRangeSum(vector<int>&nums,int lower,int upper){
 int n=nums.size();
 if(lower>upper) return (1LL*n*(n+1))/2;
 vector<long long>pref(n+1,0);
 for(int i=0;i<n;i++) pref[i+1]=pref[i]+nums[i];
 vector<long long>temp=pref;
 for(auto p:pref){
    temp.push_back(p-lower);
    temp.push_back(p-upper);
 }
 sort(temp.begin(),temp.end());
 temp.erase(unique(temp.begin(),temp.end()),temp.end());
 MAXN=temp.size()+5;
 BIT.assign(MAXN+1,0);
 long long res=0;
 for(auto p:pref){
    int r=lower_bound(temp.begin(),temp.end(),p-lower)-temp.begin()+1;
    int l=lower_bound(temp.begin(),temp.end(),p-upper)-temp.begin()+1;
    res+=query(r)-query(l-1);
    int rank=lower_bound(temp.begin(),temp.end(),p)-temp.begin()+1;
    update(rank,1);
 }
 return (1LL*n*(n+1))/2-res;
}
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        int lo=min(goal+k,goal-k);
        int up=max(goal+k,goal-k);
        return countRangeSum(nums,lo+1,up-1);
    }
};