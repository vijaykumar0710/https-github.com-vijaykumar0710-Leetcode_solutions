class Solution {
public:
    int power(int a, int b, int m) {
        int res = 1;
        a %= m;
        while (b) {
            if (b % 2)
                res = (res * a) % m;
            a = (a * a) % m;
            b /= 2;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        int m = 1140;
        int n = 0;
        for (auto x : b)
            n = (n * 10 + x) % m;
        int res = power(a, n+1140, 1337);
        return res;
    }
};