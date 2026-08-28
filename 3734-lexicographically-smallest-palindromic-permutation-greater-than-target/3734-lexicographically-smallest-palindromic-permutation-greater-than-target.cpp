class Solution {
public:
    string ans = "";
    bool build(int i, bool is_greater, vector<int>& freq, string& curr,
               string& target, int n) {
        if (i == (n + 1) / 2) {
            string full = curr;
            if (n % 2 != 0)
                full.pop_back();
            string right = curr;
            reverse(right.begin(), right.end());
            full += right;
            if (is_greater || full > target) {
                ans = full;
                return true;
            }
            return false;
        }
        int start_char = is_greater ? 0 : (target[i] - 'a');
        for (int c = start_char; c < 26; c++) {
            int needed = (n % 2 != 0 && i == n / 2) ? 1 : 2;
            if (freq[c] >= needed) {
                freq[c] -= needed;
                curr.push_back(c + 'a');
                bool next_greater = is_greater || (c > (target[i] - 'a'));
                if (build(i + 1, next_greater, freq, curr, target, n)) {
                    return true;
                }
                curr.pop_back();
                freq[c] += needed;
            }
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char ch : s)
            freq[ch - 'a']++;
        int odd_count = 0;
        for (int f : freq)
            if (f % 2 != 0)
                odd_count++;
        if (odd_count > 1)
            return "";
        string curr = "";
        build(0, false, freq, curr, target, n);
        return ans;
    }
};