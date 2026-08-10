class Solution {
    public:
    int n;
    // BIT (Fenwick Tree) telescoping sum store karne ke liye
    vector<long long> bit;
    // Original array ko globally store karne ke liye
    vector<int> a;
    // Sirf peaks ke indices (positions) store karne ke liye
    set<int> s;

    // BIT Point Update: Index 'i' par value 'v' add karta hai
    void update(int i, long long v) {
        for(; i <= n; i += i & -i) bit[i] += v;
    }

    // BIT Prefix Sum: 1 se lekar 'i' tak ka sum nikalta hai
    long long query(int i) {
        long long sum = 0;
        for(; i > 0; i -= i & -i) sum += bit[i];
        return sum;
    }

    // Naya Peak (C) Add karne ka function
    void in(int c) {
        // Right peak (R) ka iterator dhoondo
        auto r_it = s.lower_bound(c);
        
        // Left peak (L) dhoondo. Agar set ke start me hain, toh L nahi hai (-1)
        int l = (r_it == s.begin()) ? -1 : *prev(r_it);
        
        // Agar Right peak (R) exist karta hai
        if(r_it != s.end()) {
            int r = *r_it; // R ki actual value nikal li
            
            // L aur R ka direct connection todo (Purana value subtract karo)
            if(l != -1) update(r, -1LL * r * (r - l));
            
            // C aur R ka naya connection jodo
            update(r, 1LL * r * (r - c));
        }
        
        // Agar Left peak (L) exist karta hai, toh L aur C ka connection jodo
        if(l != -1) update(c, 1LL * c * (c - l));
        
        // Naye peak (C) ko Set me permanently daal do
        s.insert(c);
    }

    // Purana Peak (C) Remove karne ka function
    void out(int c) {
        // Current peak (C) ka iterator dhoondo
        auto c_it = s.find(c);
        
        // Right peak (R) ka iterator dhoondo
        auto r_it = next(c_it);
        
        // Left peak (L) dhoondo
        int l = (c_it == s.begin()) ? -1 : *prev(c_it);
        
        // L aur C ka connection todo
        if(l != -1) update(c, -1LL * c * (c - l));
        
        // Agar Right peak (R) exist karta hai
        if(r_it != s.end()) {
            int r = *r_it; // R ki actual value nikal li
            
            // C aur R ka connection todo
            update(r, -1LL * r * (r - c));
            
            // L aur R ko directly jod do (Kyunki beech ka C ab hat raha hai)
            if(l != -1) update(r, 1LL * r * (r - l));
        }
        
        // Peak (C) ko Set se nikal do
        s.erase(c_it);
    }

    // Check karne ke liye helper function ki index 'i' par peak hai ya nahi
    bool peak(int i) {
        return i > 0 && i < n - 1 && a[i] > a[i - 1] && a[i] > a[i + 1];
    }

    // Main Function
    vector<long long> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        a = nums;
        // BIT ko 1-based indexing ke liye n+1 size ka banaya
        bit.assign(n + 1, 0);
        s.clear();
        vector<long long> ans;
        
        // Initial array ke saare peaks Set aur BIT me daal do
        for(int i = 1; i < n - 1; i++) {
            if(peak(i)) in(i);
        }
        
        // Queries process karna shuru karo
        for(auto &v : queries) {
            int x = v[1], y = v[2]; // Query ke L aur R boundaries (X aur Y formula ke hisaab se)
            
            if(v[0] == 2) {
                // Type 2: Point Update (a[x] = y)
                // Step 1: Update se pehle check karo, agar x-1, x, x+1 peaks the, toh unhe hatao
                for(int i = x - 1; i <= x + 1; i++) {
                    if(s.count(i)) out(i);
                }
                
                // Step 2: Asli array update karo
                a[x] = y;
                
                // Step 3: Update ke baad check karo, agar x-1, x, x+1 naye peaks ban gaye, toh unhe add karo
                for(int i = x - 1; i <= x + 1; i++) {
                    if(peak(i)) in(i);
                }
            } else {
                // Type 1: Range Query [x, y]
                // First peak (first_p) dhoondo jo strict boundaries ke andar ho (x se bada)
                auto it = s.lower_bound(x + 1);
                
                // Agar koi peak range me nahi hai, ya fir first peak hi range ke bahar hai
                if(it == s.end() || *it >= y) {
                    ans.push_back(0);
                    continue;
                }       
                
                // First peak (first_p) aur Last peak (last_p) set kar lo
                int first_p = *it, last_p = *prev(s.lower_bound(y));
                
                // Telescoping Sum Formula: Y(last_p - X) - first_p(first_p - X) - BIT_SUM(from first_p to last_p)
                ans.push_back(1LL * y * (last_p - x) - 1LL * first_p * (first_p - x) - query(last_p) + query(first_p));
            }
        }
        
        return ans;
    }
};