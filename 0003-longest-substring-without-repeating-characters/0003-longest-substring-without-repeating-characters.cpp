class Solution {
public:
bool isValid(string &s,int mid){
    int n=s.size();
    unordered_map<char,int>st;
    int i=0;
    for(int j=0;j<n;j++){
     st[s[j]]++;
     if(j-i+1==mid){
        if(st.size()==mid) return true;
        st[s[i]]--;
        if(st[s[i]]==0) st.erase(s[i]);
        i++;
     }
    }
    return false;
}
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int res=0;
        int l=1,r=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isValid(s,mid)){
                res=mid;
                l=mid+1;
            }else r=mid-1;
        }
        return res;
    }
};