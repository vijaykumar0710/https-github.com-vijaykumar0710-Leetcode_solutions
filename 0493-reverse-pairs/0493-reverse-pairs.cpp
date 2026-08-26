class Solution {
public:
vector<int>BIT;
int MAXN=-1;
void update(int i,int val){
    for(;i<=MAXN;i+=i&-i) BIT[i]+=val;
}
int query(int i){
    int cnt=0;
    for(;i>0;i-=i&-i) cnt+=BIT[i];
    return cnt;
}
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        vector<long long>copy;
        for(auto x:nums) copy.push_back(x);
        sort(copy.begin(),copy.end());
        copy.erase(unique(copy.begin(),copy.end()),copy.end());
        MAXN=copy.size();
        BIT.assign(MAXN+1,0);
        int res=0;
        for(int i=0;i<n;i++){
            int tar_rank=upper_bound(copy.begin(),copy.end(),2LL*nums[i])-copy.begin()+1;
            res+=query(MAXN)-query(tar_rank-1);
            int rank=lower_bound(copy.begin(),copy.end(),nums[i])-copy.begin()+1;
            update(rank,1);
        }
        return res;
    }
};