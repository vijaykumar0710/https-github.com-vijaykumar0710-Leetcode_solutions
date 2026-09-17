class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,long long>>NSE(n,{n,0});
        unordered_map<int,vector<int>>mp;
        stack<int>st;
        st.push(n-1);
        mp[nums[n-1]].push_back(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty()) NSE[i].first=st.top();
            auto &vec=mp[nums[i]];
            int lo=upper_bound(vec.rbegin(),vec.rend(),NSE[i].first)-vec.rbegin();
            vec.erase(vec.begin()+lo,vec.end());
            NSE[i].second=lo;
            st.push(i);
            mp[nums[i]].push_back(i);
        }
        long long res=0;
        for(int i=0;i<n-1;i++){
            int idx=NSE[i].first-1;
            int dupli=NSE[i].second;
            if(idx-i>0) res=res+(idx-i-dupli);
        }
        return res;
    }
};