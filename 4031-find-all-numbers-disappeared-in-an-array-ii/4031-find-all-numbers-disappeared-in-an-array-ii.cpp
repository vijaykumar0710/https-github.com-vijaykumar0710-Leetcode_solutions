class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        vector<vector<int>>res;
        unordered_set<int>st(nums.begin(),nums.end());
        int start=-1,end=-1;
        int i=lower;
        while(i<=upper){
            if(!st.count(i)){
             start=i;
             while(!st.count(i) && i<=upper){
                i++;
             }
             end=i-1;
             if(start!=-1 && end!=-1) res.push_back({start,end});
            }
            i++;
        }
        return res;
    }
};