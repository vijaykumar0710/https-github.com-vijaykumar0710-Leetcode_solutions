class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(n==2){
            if(nums[0]==0) return 0;
            return 1;
        } 
        bool flag=true;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0) idx=i;
            if((nums[i]+1)%n!=nums[(i+1)%n]) flag=false;
        }
        if(flag) return min(idx,n-idx+2);
        flag=true;
        for(int i=0;i<n;i++){
            if(nums[i]==0) idx=i;
            if((nums[i]-1+n)%n!=nums[(i+1)%n]) flag=false;
        }
        if(flag) return min(idx+2,n-idx);
        return -1;
    }
};