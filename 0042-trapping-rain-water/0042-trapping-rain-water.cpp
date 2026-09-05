class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
         vector<int>PGE(n),NGE(n);
         PGE[0]=height[0];
         for(int i=1;i<n;i++){
            PGE[i]=max(PGE[i-1],height[i]);
         }
         for(auto x:PGE) cout<<x<<" ";
         NGE[n-1]=height[n-1];
         for(int i=n-2;i>=0;i--){
            NGE[i]=max(NGE[i+1],height[i]);
         }
         int res=0;
         for(int i=1;i<n-1;i++){
            int h=min(PGE[i-1],NGE[i+1]);
            if(h>height[i])
            res+=h-height[i];
         }
         return res;
    }
};