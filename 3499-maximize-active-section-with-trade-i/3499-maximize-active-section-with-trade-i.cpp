class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones=count(s.begin(),s.end(),'1');
        vector<pair<char, int>> vec;
        int cnt=1,i=1;
        for(;i<n;i++){
          if(s[i-1]==s[i]) cnt++;
          else{
            vec.push_back({s[i-1],cnt});
            cnt=1;
          }
        }
        vec.push_back({s[i-1],cnt});
        int res=0;
        for(int i=0;i<vec.size();i++){
            if(vec[i].first=='1'){
                int ans=ones;
                if(i+1<vec.size() && i-1>=0){ 
                ans+=vec[i-1].second+vec[i+1].second;
                }
                res=max(res,ans);
            }
        }
        return res;
    }
};