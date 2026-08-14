class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int k=2;
        unordered_map<int,int>mp;
        int i=0,res=0;
        for(int j=0;j<n;j++){
          mp[s[j]]++;
          while(mp[s[j]]>k){
            mp[s[i]]--;
            if(mp.count(s[i])==0) mp.erase(s[i]);
            i++;
          }
        res=max(res,j-i+1);
        }
        return res;
    }
};