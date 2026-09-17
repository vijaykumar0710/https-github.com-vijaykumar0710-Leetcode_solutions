class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<pair<int, int>> vec;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int pref = 0;
        for (int i = 0; i < n; i++) {
            pref += arr[i];
            if (mp.count(pref - target))
                vec.push_back({mp[pref - target]+1, i});
            mp[pref] = i;
        }
        sort(vec.begin(), vec.end());
        int res = INT_MAX;
        int min_len=INT_MAX;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<vec.size();i++){
            while(!pq.empty() && pq.top().first<vec[i].first){
             min_len=min(min_len,pq.top().second);
             pq.pop();
            }
            if(min_len!=INT_MAX) res=min(res,min_len+vec[i].second-vec[i].first+1);
            pq.push({vec[i].second,vec[i].second-vec[i].first+1});
        }
        return res >= INT_MAX ? -1 : res;
    }
};