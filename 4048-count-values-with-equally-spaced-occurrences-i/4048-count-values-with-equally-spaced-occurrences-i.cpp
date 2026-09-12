class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);
        int res=0;
        for(auto [num,vec]:mp){
            if(vec.size()==3){
                int diff=vec[1]-vec[0];
                bool fl=true;
                for(int i=2;i<vec.size();i++){
                    if(vec[i]-vec[i-1]!=diff){
                        fl=false;
                        break;
                    }
                }
                if(fl) res++;
            }
        }
        return res;
    }
};