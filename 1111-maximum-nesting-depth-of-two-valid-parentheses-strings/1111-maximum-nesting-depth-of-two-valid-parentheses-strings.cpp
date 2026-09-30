class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> res(n);
        stack<pair<int,int>> st;
        for (int i = 0; i < n; i++) {
            if(seq[i]==')'){
                auto p=st.top();
                res[i]=p.second;
                res[p.first]=p.second;
                st.pop();
            }
            else{
                if(st.empty()) st.push({i,0});
                else st.push({i,1-st.top().second});
            }
        }
        return res;
    }
};