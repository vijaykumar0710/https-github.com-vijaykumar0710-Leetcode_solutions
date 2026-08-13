class Solution {
public:
vector<int>BIT;
int MAXN=1e5+5;
void update(int i,int val){
    for(;i<=MAXN;i+=i&-i) BIT[i]+=val;
}
int query(int i){
    int cnt=0;
    for(;i>=1;i-=i&-i) cnt+=BIT[i];
    return cnt;
}
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        BIT.resize(100005);
        vector<int>copy;
        // Co-ordinate Compression
        copy=nums;
        sort(copy.begin(),copy.end());
        copy.erase(unique(copy.begin(),copy.end()),copy.end());
        for(int i=0;i<n;i++){
            int rank=lower_bound(copy.begin(),copy.end(),nums[i])-copy.begin();
            nums[i]=rank+1;
        }
        // Actual frequency related
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){
          int ans=query(nums[i]-1);
          res[i]=ans;
          update(nums[i],1);
        }
        return res;
    }
};