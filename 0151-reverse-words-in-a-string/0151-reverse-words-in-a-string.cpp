class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        vector<string>vec;
        int i=0;
        while(i<n){
            string temp;
            while(i<n && s[i]!=' '){
                temp+=s[i];
                i++;
            }
            if(temp.size()!=0) vec.push_back(temp);
            i++;
        }
        string res;
        for(int i=vec.size()-1;i>=0;i--)
            res+=vec[i]+' ';
        return res.substr(0,res.size()-1);
    }
};