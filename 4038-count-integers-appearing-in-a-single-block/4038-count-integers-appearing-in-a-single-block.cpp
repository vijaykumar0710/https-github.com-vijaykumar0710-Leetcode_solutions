class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);
        int res=0;
        for(auto [num,vec]:mp){
            bool fl=true;
            for(int i=0;i<vec.size()-1;i++){
                if(vec[i+1]-vec[i]!=1) fl=false;
            }
        if(fl) res++;
        }
    return res;
    }
};