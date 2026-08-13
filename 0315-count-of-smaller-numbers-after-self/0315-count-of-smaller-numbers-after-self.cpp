class Solution {
public:
vector<int>res;
vector<int>BIT;
int m;
void update(int i){
for(;i<=m;i+=i&-i) BIT[i]+=1;
}
int query(int i){
int res=0;
for(;i>0;i-=(i&-i)){
    res+=BIT[i]; 
  }
  return res;
}
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        res.resize(n);
        BIT.resize(100005);
        m=100005;
       vector<int>copy;
       copy=nums;
       sort(copy.begin(),copy.end());
       copy.erase(unique(copy.begin(),copy.end()),copy.end());
       for(int i=0;i<n;i++){
        int rank=lower_bound(copy.begin(),copy.end(),nums[i])-copy.begin();
        nums[i]=rank+1;
       }
        for(int i=n-1;i>=0;i--){
            int x=query(nums[i]-1);
            res[i]=x;
            update(nums[i]);
        }
        return res;
    }
};