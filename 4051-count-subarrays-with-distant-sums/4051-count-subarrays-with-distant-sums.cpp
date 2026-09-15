class Solution {
public:
long long maxn;
vector<long long>BIT;
void update(int i,int val){
for(;i<=maxn;i+=(i&-i)) BIT[i]+=val;
}
long long query(int i){
    long long res=0;
    for(;i>0;i-=(i&-i)) res+=BIT[i];
    return res;
}
    long long countRangeSum(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        if(lower>upper) return (1LL*n*(n+1))/2;
        vector<long long>pre(n+1,0);
        for(int i=0;i<n;i++) pre[i+1]=pre[i]+nums[i];
        vector<long long>temp=pre;
        for(auto p:pre){
            temp.push_back(p-lower);
            temp.push_back(p-upper);
        }
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        maxn=temp.size()+5;
        BIT.assign(maxn+1,0);
        long long res=0;
        for(auto p:pre){
            int up=lower_bound(temp.begin(),temp.end(),p-lower)-temp.begin()+1;
            int lo=lower_bound(temp.begin(),temp.end(),p-upper)-temp.begin()+1;
            int rank=lower_bound(temp.begin(),temp.end(),p)-temp.begin()+1;
            res+=query(up)-query(lo-1);
            update(rank,1);
        }
        return (1LL*n*(n+1))/2-res;
    }
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        int lo=goal-k+1;
        int up=goal+k-1;
        return countRangeSum(nums,lo,up);
    }
};