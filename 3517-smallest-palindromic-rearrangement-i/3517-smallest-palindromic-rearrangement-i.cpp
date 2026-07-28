class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        sort(s.begin(),s.begin()+n/2);
        n++;
        sort(s.begin()+n/2,s.end(),greater<int>());
        return s;
    }
};