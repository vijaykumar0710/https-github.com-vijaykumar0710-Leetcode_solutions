class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int res=0;
        for(auto x:nums) st.insert(x);
        for(auto num:st){
            int cnt=0;
            if(!st.count(num-1)){
                while(st.count(num)){
                    cnt++;
                    num++;
                }
            }
            res=max(res,cnt);
        }
        return res;
    }
};