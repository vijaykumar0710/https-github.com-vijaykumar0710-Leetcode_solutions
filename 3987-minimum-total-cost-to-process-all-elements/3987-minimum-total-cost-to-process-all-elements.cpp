class Solution {
public:
const int M=1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        int n=nums.size();
        long long op=0,reso=k;
        for(int i=0;i<n;i++){
            if(nums[i]>reso){
                int need=nums[i]-reso;
                int cur_op=(need+k-1)/k;
                op+=cur_op;
                reso+=cur_op*k;
            }
           reso-=nums[i];
        }
        if(op%2==0){
            long long a=(op/2)%M;
            long long b=(op+1)%M;
            return (a*b)%M;
        }
        long long a=op%M;
        long long b=((op+1)/2)%M;
        return (a*b)%M;
    }
};