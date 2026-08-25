class Solution {
public:
vector<int>seg;
const int maxi=100005;
void update(int i,int idx,int val,int l,int r){
    if(l==r){
        seg[i]=val;
        return;
    }
    int mid=l+(r-l)/2;
    if(idx<=mid) update(2*i+1,idx,val,l,mid);
    else update(2*i+2,idx,val,mid+1,r);
    seg[i]=max(seg[2*i+1],seg[2*i+2]);
}
int query(int i,int l,int r,int st,int end){
    if(l>end || r<st) return 0;
    if(l>=st && r<=end) return seg[i];
    int mid=l+(r-l)/2;
    return max(query(2*i+1,l,mid,st,end),query(2*i+2,mid+1,r,st,end));
}
    int lengthOfLIS(vector<int>& nums, int k) {
        int n=nums.size();
        seg.assign(4*maxi,0);
        int lis=0;
        for(int i=0;i<n;i++){
            int l=max(1,nums[i]-k);
            int r=nums[i]-1;
            int len=1+query(0,0,maxi,l,r);
            lis=max(lis,len);
            update(0,nums[i],len,0,maxi);
        }
        return lis;
    }
};