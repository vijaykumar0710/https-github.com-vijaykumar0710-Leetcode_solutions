class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>fre(101,0);
        for(auto num:nums) fre[num]++;
        vector<int>res;
        for(int i=0;i<n;i++){
            for(int j=1;j<101;j++){
                if(fre[j]>0) res.push_back(j);
                fre[j]--;
            }
        }
        return res;
    }
};