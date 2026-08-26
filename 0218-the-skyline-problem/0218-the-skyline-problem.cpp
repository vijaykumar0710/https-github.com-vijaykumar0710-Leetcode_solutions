class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        int n = b.size();
        vector<pair<int, int>> vec;
        for (auto x : b) {
            vec.push_back({x[0], -x[2]});
            vec.push_back({x[1], x[2]});
        }
        sort(vec.begin(), vec.end());
        vector<vector<int>> res;
        multiset<int>ms;
        ms.insert(0);
        int prev=0;
        for(auto p:vec){
            int x=p.first,h=p.second;
            if(h<0) ms.insert(-h);
            else ms.erase(ms.find(h));
            int curr=*ms.rbegin();
            if(curr!=prev){
                res.push_back({x,curr});
                prev=curr;
            }
        }
        return res;
    }
};