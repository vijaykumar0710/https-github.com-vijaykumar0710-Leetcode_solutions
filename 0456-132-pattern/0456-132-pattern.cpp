class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int>left_min(n),PGE(n,INT_MIN);
        left_min[0]=nums[0];
        for(int i=1;i<n;i++) left_min[i]=min(nums[i],left_min[i-1]);
        stack<int>st;
        PGE[0]=-1,st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
            if(!st.empty()) PGE[i]=st.top();
            st.push(i);
        }
        for(int i=1;i<n;i++){
            int z=nums[i];
            int y,x;
            if(PGE[i]>0){
                y=nums[PGE[i]];
                x=left_min[PGE[i]];
            }
            if(x<z && y>z) return true;
        }
        return false;
    }
};