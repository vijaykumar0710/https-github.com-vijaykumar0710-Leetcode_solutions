class Solution {
public:
const int M=1e9+7;
    int distinctSubseqII(string s) {
        vector<int>last_seen(26,0);
        int total=0;
        for(auto ch:s){
            int val=(total+1)%M;
            int idx=ch-'a';
            total=(total-last_seen[idx]+M)%M;
            total=(total+val)%M;
            last_seen[idx]=val;
        }
        return total;
    }
};