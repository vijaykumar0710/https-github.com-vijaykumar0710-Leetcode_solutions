class Solution {
public:
long long check(long long target, const vector<int>& coins, int n) {
        long long total_count = 0;
        int total_subsets = (1 << n); 
        for (int mask = 1; mask < total_subsets; mask++) {
            long long subset_lcm = 1;
            int set_bits = 0;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    set_bits++;
                    subset_lcm =lcm(subset_lcm, (long long)coins[i]);
                    if (subset_lcm > target) {
                        break;
                    }
                }
            }
            if (subset_lcm <= target) {
                long long multiples = target / subset_lcm;
                if (set_bits % 2 == 1) {
                    total_count += multiples;
                } else {
                    total_count -= multiples;
                }
            }
        }
        return total_count;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        long long low = 1;
        long long min_coin = *min_element(coins.begin(), coins.end());
        long long high = min_coin * (long long)k; 
        long long ans = high;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, coins, n) >= k) {
                ans = mid;      
                high = mid - 1;    
            } else {
                low = mid + 1;   
            }
        }
        return ans;
    }
};