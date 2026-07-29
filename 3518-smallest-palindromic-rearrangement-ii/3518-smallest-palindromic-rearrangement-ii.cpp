class Solution {
public:
long long LIMIT = 1e6 + 1;
   long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r > n / 2) r = n - r; 
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
            if (res > LIMIT) return LIMIT; 
        }
        return res;
    }
    long long getWays(const vector<int>& f) {
        long long ways = 1;
        int len = 0;
        for (int i = 0; i < 26; ++i) {
            if (f[i] > 0) {
                len += f[i];
                ways = ways * nCr(len, f[i]);
                if (ways > LIMIT) return LIMIT;
            }
        }
        return ways;
    }
    string smallestPalindrome(string s, int k) {
       int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        int odd_count = 0;
        char mid_char = 0;
        vector<int> half_freq(26, 0);
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                odd_count++;
                mid_char = i + 'a';
            }
            half_freq[i] = freq[i] / 2;
        }
        if (odd_count > 1) return "";
        int half_len = n / 2;
        if (getWays(half_freq) < k) return "";
        string left_half = "";
        for (int i = 0; i < half_len; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half_freq[c] > 0) {
                    half_freq[c]--;
                    long long ways = getWays(half_freq);
                    if (k <= ways) {
                        left_half += (char)(c + 'a');
                        break;
                    } else {
                        k -= ways;
                        half_freq[c]++;
                    }
                }
            }
        }
        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());
        if (n % 2 != 0) {
            return left_half + mid_char + right_half;
        }
        return left_half + right_half;
    }
};