class Solution {
public:
int N;
vector<int>BIT;
void update(int i,int val){
    for(;i<=N;i+=i&-i) BIT[i]=max(BIT[i],val);
}
int query(int i){
    int len=0;
    for(;i>0;i-=i&-i) len=max(len,BIT[i]);
    return len;
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>copy;
        copy=nums;
        sort(copy.begin(),copy.end());
        copy.erase(unique(copy.begin(),copy.end()),copy.end());
        for(int i=0;i<n;i++){
            int rank=lower_bound(copy.begin(),copy.end(),nums[i])-copy.begin();
            nums[i]=rank+1;
        }
        N=n;
        BIT.assign(N+1,0);
       int lis=1;
       for(int i=0;i<n;i++){
          int x=nums[i];
          int len=1+query(x-1);
          update(x,len);
          lis=max(lis,len);
       }
       return lis;
    }
};