class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        vector<int>basis;
        for(auto x:nums){
            for(auto b:basis) x=min(x,x^b);
            if(x>0) basis.push_back(x);
        }
        int d=basis.size();
        return 1<<d;
    }
};