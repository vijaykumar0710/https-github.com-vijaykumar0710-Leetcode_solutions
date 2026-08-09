class Solution {
public:
vector<int>segTree;
void buildSegtree(int i,int l,int r,vector<int>& heights){
    if(l==r){
        segTree[i]=l;
        return;
    }
    int mid=l+(r-l)/2;
    buildSegtree(2*i+1,l,mid,heights);
    buildSegtree(2*i+2,mid+1,r,heights);
    
    segTree[i]=(heights[segTree[2*i+1]]>=heights[segTree[2*i+2]])?segTree[2*i+1]:segTree[2*i+2];
}
int RMIQ(int i,int l,int r,int start,int end,vector<int>& heights){
   if(l>end || r<start) return -1;
   if(l>=start && r<=end) return segTree[i];
   int mid=l+(r-l)/2;
   int left_max_idx=RMIQ(2*i+1,l,mid,start,end,heights);
   int right_max_idx=RMIQ(2*i+2,mid+1,r,start,end,heights);
   if(left_max_idx==-1) return right_max_idx;
   if(right_max_idx==-1) return left_max_idx;
   return (heights[left_max_idx] >= heights[right_max_idx]) ? left_max_idx : right_max_idx;
}

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
         segTree.resize(4*n);
         buildSegtree(0,0,n-1,heights);
         vector<int>res;
        for(auto &q:queries){
            int max_idx=max(q[0],q[1]);
            int min_idx=min(q[0],q[1]);
            if(max_idx==min_idx) res.push_back(min_idx);
            else if(heights[max_idx]>heights[min_idx]) res.push_back(max_idx);
            else{
                int l=max_idx+1;
                int r=n-1;
                int val=max(heights[max_idx],heights[min_idx]);
                int idx=INT_MAX;
                while(l<=r){
                   int mid=l+(r-l)/2;
                   int left_idx=RMIQ(0,0,n-1,l,mid,heights);
                   if(heights[left_idx]>val){
                    idx=min(idx,left_idx);
                    r=mid-1;
                   }else{
                    l=mid+1;
                   }
                }
                if(idx==INT_MAX) res.push_back(-1);
                else res.push_back(idx);
            }
        }
        return res;
    }
};