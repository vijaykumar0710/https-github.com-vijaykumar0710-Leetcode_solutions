class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<pair<int, int>> vec(26, {-1, -1});
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            if (vec[idx].first == -1)
                vec[idx].first = i;
            vec[idx].second = i;
        }
        vector<pair<int, int>> pai;
        for (auto x : vec) {
            if (x.first == -1)
                continue;
            pai.push_back(x);
        }
        sort(pai.begin(), pai.end());
        if(pai.size()<=1) return {s};
        set<pair<int,int>>ans;
        int prev_len=INT_MAX;
        for (int i = 0; i < pai.size(); i++) {
            set<pair<int,int>>st;
            int last = pai[i].second;
            int len = pai[i].second - pai[i].first + 1;
            st.insert({pai[i]});
            for (int j = i + 1; j < pai.size(); j++) {
                if (pai[j].first > last) {
                    len += pai[j].second - pai[j].first + 1;
                    last = pai[j].second;
                    st.insert(pai[j]);
                }
            }
            if(st.size()>ans.size()){
                ans=st;
            }else if(st.size()==ans.size() && len<prev_len){
                 ans=st;
                 prev_len=len;
            }
        }
        vector<string>res;
        for(auto x:ans){
            string str=s.substr(x.first,x.second-x.first+1);
            res.push_back(str);
        }
        return res;
    }
};