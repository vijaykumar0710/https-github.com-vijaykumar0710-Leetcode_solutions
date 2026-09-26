class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto k:knowledge) mp[k[0]]=k[1];
        string res="";
        for(int i=0;i<s.size();i++){
          if(s[i]=='('){
            string st="";
            i++;
            while(s[i]!=')'){ 
              st+=s[i];
              i++;
            }
            if(mp.find(st)!=mp.end()) res+=mp[st];
            else res+='?';
          }
          else res+=s[i];
        }
        return res;
    }
};